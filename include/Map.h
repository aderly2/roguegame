#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "object.h"
#include "TextureLoader.h"

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
        void  setTile(int x, int y, Tile tile);

        sf::Vector2i getMapSize();

        void  setTileSize(sf::Vector2f size);
        sf::Vector2f getTileSize();

        void draw(sf::RenderTarget& target, TextureLoader& textures, sf::IntRect rect = sf::IntRect(0,0,0,0));

    protected:
    private:
        sf::Vector2i mMapSize;
        sf::Vector2f mTileSize;

        TilesMap mTilemap;
};

#endif // MAP_H
