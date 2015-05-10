#include "object.h"

object::object(int objectType, float x, float y) // Default Constructor
{
    // Rect
    rect.setPosition(x, y);
    rect.setOrigin(50,50);
    rect.setSize(sf::Vector2f(100, 100));
    rect.setFillColor(sf::Color::Green);

    // Sprite
    sprite.setOrigin(100,100);
    sprite.setPosition(x, y);
}

void object::update()
{
    // Keep sprite at rect
    sprite.setPosition(rect.getPosition());
    sprite.setRotation(rect.getRotation());
}
