#pragma once
#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class rulesScreen : public cScreen
{
public:
    rulesScreen();
    virtual int Run(sf::RenderWindow &App);
};

rulesScreen::rulesScreen(void)
{
    
}

int rulesScreen::Run(sf::RenderWindow &App)
{
    sf::Texture texture;
    if (!texture.loadFromFile("blueGrid.png")) {
        std::cout << "Error loading texture newTexture.png" << std::endl;
        return(-1);
    }
    sf::Sprite background(texture);

    sf::Font Font;
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }

    sf::Text rulesText;
    rulesText.setFont(Font);
    rulesText.setPosition({ 100, 100 });
    rulesText.setColor(sf::Color(255, 255, 0, 255));
    rulesText.setCharacterSize(20);
    rulesText.setString("This is the game of Light Cycles. \n"
                        "Left player uses the W,S,A and D keys. \n"
                        "Right player uses the arrow keys. \n"
                        "Press escape to return to main menu. \n"
                        "If you hit a boundry or any trail you will lose. \n"
                        "Try to make the opponent crash!\n"
                        "Good luck!\n"
                        "Press ESC to go back to main menu.");

    sf::Event Event;
    bool Running = true;

    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Escape:
                    return (0);
                    break;
                default:
                    break;
                }
            }
        }

        //Clearing screen
        App.clear(sf::Color(0, 0, 0, 0));
        //Drawing
        App.draw(background);
        App.draw(rulesText);
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return -1;
}