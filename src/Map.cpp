#include "Map.h"

#include <vector>

Map::Map(sf::Vector2i size)
{
    mTilemap = std::vector<std::vector<Tile>>((int)size.x, std::vector<Tile>((int)size.y));

    for(int x = 0; x < size.x; x++)
    {
        for(int y = 0; y < size.y; y++)
        {
            mTilemap[x][y].left = x != 0 ? &mTilemap[x - 1][y] : &mTilemap[size.x - 1][y];
            mTilemap[x][y].right = x != size.x - 1 ? &mTilemap[x + 1][y] : &mTilemap[0][y];

            mTilemap[x][y].top = y != 0 ? &mTilemap[x][y - 1] : &mTilemap[x][size.y - 1];
            mTilemap[x][y].bottom = y != size.y - 1 ? &mTilemap[x][y + 1] : &mTilemap[x][0];
        }
    }
}

Tile* Map::getTile(int x, int y)
{
    return &mTilemap[x][y];
}

Tile* Map::getTile(sf::Vector2i pos)
{
    return getTile(pos.x, pos.y);
}
