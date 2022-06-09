#include "ResetGame.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void ResetGame(bool& button, Sprite& ResetGameSprite, RenderWindow& window)
{
    if (IntRect(420, 50, 367, 49).contains(Mouse::getPosition(window))) {
        button = 1;
        ResetGameSprite.setColor(Color::Blue);
    }
}
