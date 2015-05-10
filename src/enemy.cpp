#include "enemy.h"

enemy::enemy() // Default Constructor
{
    // Rect
    rect.setPosition(100, 100);
    rect.setOrigin(50,50);
    rect.setSize(sf::Vector2f(100, 100));
    rect.setFillColor(sf::Color::Green);

    // Sprite
    sprite.setOrigin(100,100);
    sprite.setPosition(100, 100);
}

void aiMovement()
{

}
