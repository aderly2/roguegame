#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

typedef std::map<std::string, sf::Texture> TextureMap;

class TextureLoader
{
    public:
        TextureLoader();
        void load(std::string textureName, std::string path, sf::IntRect rect = sf::IntRect());

        sf::Texture& get(std::string name);

    protected:
    private:
        TextureMap mTextureMap;
};

#endif // TEXTURELOADER_H
