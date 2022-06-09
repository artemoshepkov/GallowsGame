#include "menu.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

void SelectmodeMenu(RenderWindow& window)
{
    Music MenuMusic;
    MenuMusic.openFromFile("Music/MenuMusic.wav");
    MenuMusic.setVolume(15.f);
    MenuMusic.play();

    Texture easyTexture, mediumTexture, hardTexture, Selectbackground,
            model1Texture, model2Texture, model3Texture;
    easyTexture.loadFromFile("Images/easy.png");
    mediumTexture.loadFromFile("Images/medium.png");
    hardTexture.loadFromFile("Images/hard.png");
    Selectbackground.loadFromFile("Images/select.jpg");
    model1Texture.loadFromFile("images/easy_model.jpg");
    model2Texture.loadFromFile("images/medium_model.jpg");
    model3Texture.loadFromFile("images/hard_model.jpg");
    Sprite easy(easyTexture), medium(mediumTexture), hard(hardTexture),
            background(Selectbackground), model(model1Texture);
    bool isSelect = 1;
    int Selectnum = 0;
    easy.setPosition(800, 400);
    medium.setPosition(800, 500);
    hard.setPosition(800, 600);
    model.setPosition(100, 300);
    background.setPosition(0, 0);
    while (isSelect) {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        easy.setColor(Color::Black);
        medium.setColor(Color::Black);
        hard.setColor(Color::Black);
        Selectnum = 0;

        if (IntRect(800, 400, 144, 60).contains(Mouse::getPosition(window))) {
            easy.setColor(Color::Green);
            model.setTexture(model1Texture);
            Selectnum = 1;
        }
        if (IntRect(800, 500, 244, 60).contains(Mouse::getPosition(window))) {
            medium.setColor(Color::Blue);
            model.setTexture(model2Texture);
            Selectnum = 2;
        }
        if (IntRect(800, 600, 144, 60).contains(Mouse::getPosition(window))) {
            hard.setColor(Color::Red);
            model.setTexture(model3Texture);
            Selectnum = 3;
        }
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (Selectnum == 1) {
                MenuMusic.stop();
                GameMenu(window, Selectnum);
                isSelect = false;
            }
            if (Selectnum == 2) {
                MenuMusic.stop();
                isSelect = false;
                GameMenu(window, Selectnum);
            }
            if (Selectnum == 3) {
                MenuMusic.stop();
                isSelect = false;
                GameMenu(window, Selectnum);
            }
        }
        window.clear();
        window.draw(background);
        window.draw(easy);
        window.draw(medium);
        window.draw(hard);
        window.draw(model);
        window.display();
    }
}
