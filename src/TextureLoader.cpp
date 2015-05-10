#include "TextureLoader.h"

TextureLoader::TextureLoader()
{

}

void TextureLoader::load(std::string textureName, std::string path, sf::IntRect rect)
{
    mTextureMap[textureName].loadFromFile(path, rect);
}

sf::Texture& TextureLoader::get(std::string name)
{
    return mTextureMap[name];
}
