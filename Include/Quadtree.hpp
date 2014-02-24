#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>
class QuadTree
{
public:

                                QuadTree(sf::Uint16 pLevel, sf::FloatRect bounds);

    void                        clear(sf::FloatRect bounds);
    void                        insert(sf::Sprite& sprite);
    std::vector<sf::Sprite*>    retrieve(sf::FloatRect bounds, sf::Uint16 currentDepth);

private:
    void                        split();
    sf::Int16                   getIndex(sf::FloatRect bounds);

private:
    const int                   MAX_OBJECTS;
    const int                   MAX_LEVELS;
    sf::Uint16                  mLevel;
    std::vector<sf::Sprite*>    mObjects;
    sf::FloatRect               mBounds;
    std::vector<std::shared_ptr<QuadTree>> mChildren;

    sf::Uint16                  mDepth, mSearchDepth;
};
#endif // QUADTREE_HPP
