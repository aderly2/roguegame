#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "object.h"

struct Tile
{
    std::vector<object> objects;

    Tile* left;
    Tile* right;
    Tile* top;
    Tile* bottom;

    std::string texture;
};

typedef std::vector<std::vector<Tile>> TilesMap;

class Map
{
    public:
        Map(sf::Vector2i size);

        Tile* getTile(int x, int y);
        Tile* getTile(sf::Vector2i pos);
    protected:
    private:
        TilesMap mTilemap;
};

#endif // MAP_H
