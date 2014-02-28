#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <tgd/Property.hpp>
#include <tgd/Entity.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>
class QuadTree
{
public:

                                QuadTree(sf::Uint16 pLevel, sf::FloatRect bounds);

    void                        clear(sf::FloatRect bounds);
    void                        insert(std::shared_ptr<tgd::Entity> object);
    std::vector<std::shared_ptr<tgd::Entity>>    retrieve(sf::FloatRect bounds, sf::Uint16 currentDepth);

private:
    void                        split();
    sf::Int16                   getIndex(sf::FloatRect bounds);

private:
    const int                   MAX_OBJECTS;
    const int                   MAX_LEVELS;
    sf::Uint16                  mLevel;
    std::vector<std::shared_ptr<tgd::Entity>>    mObjects;
    sf::FloatRect               mBounds;
    std::vector<std::shared_ptr<QuadTree>> mChildren;

    sf::Uint16                  mDepth, mSearchDepth;
};
#endif // QUADTREE_HPP
