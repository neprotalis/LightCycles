#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using std::endl;
using std::cout;
using std::vector;
using sf::Vector2f;

typedef enum direction
{
	UP, RIGHT, DOWN, LEFT, CRASH
}Direction;

class Bike : public sf::RectangleShape
{
    friend class gameScreen;
public:
    Bike(sf::Color const & newColor = sf::Color::Yellow, Vector2f const & size = { 1,1 }, Vector2f const & pos = { 0,0 }, Direction const & newDir = DOWN);
    ~Bike();

	Direction getDir();
	void setDir(Direction const &newDir);

	void update(float window_x, float window_y);
	void checkCrash(float window_x, float window_y);

private:
	Direction dir;
};