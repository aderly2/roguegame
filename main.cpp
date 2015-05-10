#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <random>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <iostream>

//#include "player.h"
#include "enemy.h"
#include "object.h"

#include "Map.h"
#include "TextureLoader.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~ RANDOM FUNCTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int generateRandom(int max)
{
    int randomNumber = rand();
    float random = (randomNumber % max) + 1;
    int myRandom = random;
    return myRandom;
}

int main(int, char const**)
{
// Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rogue-Like RPG 1.00");

    Map map(sf::Vector2i(10, 10));
    map.setTileSize(sf::Vector2f(40, 40));

    TextureLoader textures;
    textures.load("default", "resources/cb.bmp");

// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw Player
        map.draw(window, textures);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
