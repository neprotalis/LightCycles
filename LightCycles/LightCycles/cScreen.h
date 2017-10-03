#pragma once
#include <SFML/Graphics.hpp>

// Basic outline for a screen object used for menus
class cScreen {
public:
    virtual int Run(sf::RenderWindow &App) = 0;
};