#include "Map.h"

#include <vector>

Map::Map(sf::Vector2i size)
{
    mMapSize = size;

    mTilemap = std::vector<std::vector<Tile>>((int)size.x, std::vector<Tile>((int)size.y));

    for(int x = 0; x < size.x; x++)
    {
        for(int y = 0; y < size.y; y++)
        {
            mTilemap[x][y].left = x != 0 ? &mTilemap[x - 1][y] : &mTilemap[size.x - 1][y];
            mTilemap[x][y].right = x != size.x - 1 ? &mTilemap[x + 1][y] : &mTilemap[0][y];

            mTilemap[x][y].top = y != 0 ? &mTilemap[x][y - 1] : &mTilemap[x][size.y - 1];
            mTilemap[x][y].bottom = y != size.y - 1 ? &mTilemap[x][y + 1] : &mTilemap[x][0];

            mTilemap[x][y].texture = "default";
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

void Map::setTile(int x, int y, Tile tile)
{
    mTilemap[x][y] = tile;
}

sf::Vector2i Map::getMapSize()
{
    return mMapSize;
}

void Map::setTileSize(sf::Vector2f size)
{
    mTileSize = size;
}

sf::Vector2f Map::getTileSize()
{
    return mTileSize;
}

void Map::draw(sf::RenderTarget& target, TextureLoader& textures, sf::IntRect rect)
{
    if(rect == sf::IntRect())
        rect = sf::IntRect(0, 0, getMapSize().x, getMapSize().y);

    sf::Sprite sprite;

    for(int x = rect.left; x < rect.width; x++)
    {
        for(int y = rect.top; y < rect.height; y++)
        {
            sprite.setPosition(x * getTileSize().x, y * getTileSize().y);
            sprite.setTexture(textures.get(getTile(x, y)->texture));
            sprite.setScale(getTileSize().x / sprite.getTexture()->getSize().x, getTileSize().y / sprite.getTexture()->getSize().y); //to remove
            target.draw(sprite);
        }
    }
}
