#ifndef ____object__
#define ____object__

#include <SFML/Graphics.hpp>

class object
{
protected:
    sf::Sprite sprite;
    sf::RectangleShape rect;

public:
    object(int objectType, float x, float y);

    void update();

};

#endif /* defined(____object__) */
