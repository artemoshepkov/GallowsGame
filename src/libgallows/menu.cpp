#include "menu.h"
#include "functions.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

void MainMenu(RenderWindow& window)
{
    Music MenuMusic;
    MenuMusic.openFromFile("Music/MenuMusic.wav");
    MenuMusic.setVolume(15.f);
    MenuMusic.play();

    Texture MenuStartTexture, MenuExitTexture, MenuTexture;
    MenuStartTexture.loadFromFile("Images/start.png");
    MenuExitTexture.loadFromFile("Images/exit.png");
    MenuTexture.loadFromFile("Images/menu.jpg");
    Sprite MenuStart(MenuStartTexture), MenuExit(MenuExitTexture),
            MenuBackground(MenuTexture);

    bool isMenu = 1;
    int MenuNum = 0;

    MenuStart.setPosition(187, 415);
    MenuExit.setPosition(200, 500);
    MenuBackground.setPosition(0, 0);

    while (isMenu) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        MenuStart.setColor(Color::Black);
        MenuExit.setColor(Color::Black);
        MenuNum = 0;

        if (IntRect(187, 415, 171, 50).contains(Mouse::getPosition(window))) {
            MenuStart.setColor(sf::Color::Blue);
            MenuNum = 1;
        }
        if (IntRect(200, 500, 131, 55).contains(Mouse::getPosition(window))) {
            MenuExit.setColor(Color::Blue);
            MenuNum = 2;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (MenuNum == 1) {
                isMenu = false;
                MenuMusic.stop();
                SelectmodeMenu(window);
            }
            if (MenuNum == 2) {
                window.close();
                isMenu = false;
            }
        }

        window.draw(MenuBackground);
        window.draw(MenuStart);
        window.draw(MenuExit);

        window.display();
    }
}
