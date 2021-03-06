#ifndef ____entity__
#define ____entity__

#include <SFML/Graphics.hpp>
#include <iostream>

class entity
{
protected:
    sf::Sprite sprite;
    sf::RectangleShape rect;

public:
    entity();
    void update(); // Keep sprite and rect together
};

#endif /* defined(____entity__) */
