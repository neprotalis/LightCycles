// neon title text from flaminglogos.com
#pragma once
#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class mainMenuScreen : public cScreen {
private:
    int alpha_max;
    int alpha_div;
    bool playing;
public:
    mainMenuScreen();
    bool getPlaying();
    virtual int Run(sf::RenderWindow &App);
};

// default constructor
mainMenuScreen::mainMenuScreen() {
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

bool mainMenuScreen::getPlaying() {
    return playing;
}

// Run acts as main loop for game
int mainMenuScreen::Run(sf::RenderWindow &App) {
    sf::Event Event;
    bool Running = true;
    sf::Texture blueGrid;
    sf::Sprite background;
    sf::Texture titleTexture;
    sf::Sprite title;
    int alpha = 0;
    sf::Font Font;
    sf::Text Play;
    sf::Text Rules;
    sf::Text Exit;
    sf::Text ExitToMain;
    sf::Text Continue;
    int menu = 0;

    if (!blueGrid.loadFromFile("blueGrid.png")) {
        std::cout << "Error loading texture newTexture.png" << std::endl;
        return(-1);
    }
    background.setTexture(blueGrid);
    background.setColor(sf::Color(255, 255, 255, alpha));

    if (!titleTexture.loadFromFile("titleTexture.png")) {
        std::cout << "Error loading texture titleTexture.png" << std::endl;
        return(-1);
    }
    title.setTexture(titleTexture);
    title.setPosition(135, 100);
    if (!Font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }
    Play.setFont(Font);
    Play.setCharacterSize(20);
    Play.setString("Play");
    Play.setPosition({ 270.f, 220.f });

    Rules.setFont(Font);
    Rules.setCharacterSize(20);
    Rules.setString("Rules");
    Rules.setPosition({ 270.f, 260.f });

    Exit.setFont(Font);
    Exit.setCharacterSize(20);
    Exit.setString("Exit");
    Exit.setPosition({ 270.f, 300.f });

    ExitToMain.setFont(Font);
    ExitToMain.setCharacterSize(20);
    ExitToMain.setString("Exit to Menu");
    ExitToMain.setPosition(App.getSize().x / 3, App.getSize().y / 2);

    Continue.setFont(Font);
    Continue.setCharacterSize(20);
    Continue.setString("Continue");
    Continue.setPosition(App.getSize().x / 3, (App.getSize().y / 2) - 40);

    if (playing)
    {
        alpha = alpha_max;
    }

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
                case sf::Keyboard::Up:
                    if (menu > 0 && !playing)
                        --menu;
                    else if (menu == 0 && !playing)
                        menu = 2;
                    else
                        menu = 3;
                    break;
                case sf::Keyboard::Down:
                    if (menu < 2 && !playing)
                        ++menu;
                    else if (menu == 2 && !playing)
                        menu = 0;
                    else
                        menu = 3;
                    break;
                case sf::Keyboard::Return:
                    if (menu == 0)
                    {
                        //Let's play!
                        playing = true;
                        App.clear();
                        return (1);
                    }
                    else if (menu == 1) {
                        return (2);
                    }
                    else if (menu == 3) {
                        playing = false;
                        return(0);
                    }
                    else
                    {
                        // Exit Game
                        return (-1);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        //When getting at alpha_max, we stop modifying the sprite
        if (alpha<alpha_max)
        {
            alpha += 3;
        }
        background.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
        if (menu == 0)
        {
            Play.setColor(sf::Color(255, 0, 0, 255));
            Rules.setColor(sf::Color(255, 255, 255, 255));
            Exit.setColor(sf::Color(255, 255, 255, 255));
            Continue.setColor(sf::Color(255, 0, 0, 255));
            ExitToMain.setColor(sf::Color(255, 255, 255, 255));
        }
        else if (menu == 1) {
            Play.setColor(sf::Color(255, 255, 255, 255));
            Rules.setColor(sf::Color(255, 0, 0, 255));
            Exit.setColor(sf::Color(255, 255, 255, 255));
            Continue.setColor(sf::Color(225, 0, 0, 255));
        }
        else
        {
            Play.setColor(sf::Color(255, 255, 255, 255));
            Rules.setColor(sf::Color(255, 255, 255, 255));
            ExitToMain.setColor(sf::Color(255, 0, 0, 255));
            Exit.setColor(sf::Color(255, 0, 0, 255));
            Continue.setColor(sf::Color(255, 255, 255, 255));
        }

        //Clearing screen
        App.clear();
        //Drawing
        App.draw(background);
        if (alpha == alpha_max)
        {
            if (playing)
            {
                App.draw(ExitToMain);
            }
            else
            {
                App.draw(title);
                App.draw(Play);
                App.draw(Rules);
                App.draw(Exit);
            }
        }
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}