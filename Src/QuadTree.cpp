#include <Quadtree.hpp>

QuadTree::QuadTree(sf::Uint16 pLevel, sf::FloatRect bounds)
: MAX_OBJECTS(10)
, MAX_LEVELS(5)
, mLevel(pLevel)
, mBounds(bounds)
, mDepth(0u)
, mSearchDepth(0u)
{
    mChildren.reserve(4);
}

void QuadTree::clear(sf::FloatRect bounds)
{
    mObjects.clear();
    mChildren.clear();
    mBounds = bounds;

    mSearchDepth = 0u;
    mDepth = 0u;
}

void QuadTree::insert(sf::Sprite& object)
{
    //check if an object falls completely outside of a node
    if(!object.getGlobalBounds().intersects(mBounds))
    {
        return;
    }

    //if node is already split add object to corresponding child node if it fits
    if(!mChildren.empty())
    {
        sf::Int16 index = getIndex(object.getGlobalBounds());
        if(index != -1)
        {
            mChildren[index]->insert(object);
            return;
        }
    }
    //else add object to this node
    mObjects.push_back(const_cast<sf::Sprite*>(&object));

    //check number of objects in this node and split if necessary
    //adding any objects that fit to the new child noe
    if(mObjects.size() > MAX_OBJECTS && mLevel < MAX_LEVELS)
    {
        //split if there are no child nodes
        if(mChildren.empty())
        {
            split();
        }

        sf::Int16 i = 0;
        while(i < mObjects.size())
        {
            sf::Int16 index = getIndex(mObjects[i]->getGlobalBounds());
            if(index != -1)
            {
                mChildren[index]->insert(*mObjects[i]);
                mObjects.erase(mObjects.begin() + i);
            }
            else
            {
                i++; //we only increment i when not erasing because erasing moves everything up
                //one index inside the vector
            }
        }
    }
}

void QuadTree::split()
{
    const float halfWidth = mBounds.width / 2.0f;
    const float halfHeight = mBounds.height / 2.0f;
    const float x = mBounds.left;
    const float y = mBounds.top;

    mChildren.push_back(std::make_shared<QuadTree>(mLevel + 1, sf::FloatRect(x + halfWidth, y, halfWidth, halfHeight)));
    mChildren.push_back(std::make_shared<QuadTree>(mLevel + 1, sf::FloatRect(x, y, halfWidth, halfHeight)));
    mChildren.push_back(std::make_shared<QuadTree>(mLevel + 1, sf::FloatRect(x, y + halfHeight, halfWidth, halfHeight)));
    mChildren.push_back(std::make_shared<QuadTree>(mLevel + 1, sf::FloatRect(x + halfWidth, y + halfHeight, halfWidth, halfHeight)));

}

std::vector<sf::Sprite*> QuadTree::retrieve(sf::FloatRect bounds, sf::Uint16 searchDepth)
{
    searchDepth = mLevel;
    std::vector<sf::Sprite*> foundObjects;
    sf::Int16 index = getIndex(bounds);

    //recursively add objects of child node if bounds is full contained
    if(!mChildren.empty() && index != -1)
    {
        foundObjects = mChildren[index]->retrieve(bounds, searchDepth);
    }
    else
    {
        //add all objects of child nodes which intersect test area
        for(auto& child : mChildren)
        {
            if(bounds.intersects(child->mBounds))
            {
                std::vector<sf::Sprite*> childObjects = child->retrieve(bounds, searchDepth);
                foundObjects.insert(foundObjects.end(), childObjects.begin(), childObjects.end());
            }
        }
    }
    //and append objects in this node
    foundObjects.insert(foundObjects.end(), mObjects.begin(), mObjects.end());

    return foundObjects;
}

sf::Int16 QuadTree::getIndex(sf::FloatRect bounds)
{
    sf::Int16 index = -1;
    float verticalMidpoint = mBounds.left + (mBounds.width / 2.0f);
    float horizontalMidpoint = mBounds.top + (mBounds.height / 2.0f);

    //object can completely fit within the top quadrants
    bool topQuadrant = (bounds.top < horizontalMidpoint && bounds.top + bounds.height < horizontalMidpoint);
    //object can completely fit within bottom quadrants
    bool bottomQuadrant = (bounds.top > horizontalMidpoint);

    //object can completely fit within the left quadrants
    if(bounds.left < verticalMidpoint && bounds.left + bounds.width < verticalMidpoint)
    {
        if(topQuadrant)
        {
            index = 1;
        }
        else if(bottomQuadrant)
        {
            index = 2;
        }
    }
    //object can completely fit within the right quadrants
    else if(bounds.left > verticalMidpoint)
    {
        if(topQuadrant)
        {
            index = 0;
        }
        else if (bottomQuadrant)
        {
            index = 3;
        }
    }

    return index;
}

