#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.h"

int main()
{
    //Applications variables
    std::vector<cScreen*> Screens;
    int screen = 0;

    //Window creation
    sf::RenderWindow App(sf::VideoMode(640, 480, 32), "Light Cycles");
    App.setFramerateLimit(300);

    //Mouse cursor no more visible
    App.setMouseCursorVisible(false);

    //Screens preparations
    mainMenuScreen s0;
    Screens.push_back(&s0);
    gameScreen s1;
    Screens.push_back(&s1);
    rulesScreen s2;
    Screens.push_back(&s2);

    //Main loop
    while (screen >= 0)
    {
        if (!s0.getPlaying())
            s1.initBikes();
        screen = Screens[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}