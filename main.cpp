#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <random>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <iostream>

using namespace std;

//#include "player.h"
#include "enemy.h"
#include "object.h"

#include "Map.h"

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
//        window.draw(player);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
