#include "Bike.h"

Bike::Bike(sf::Color const &newColor, Vector2f const &size, Vector2f const &pos, Direction const &newDir)
{
	this->setFillColor(newColor);
	this->setSize(size);
	this->setPosition(pos);
	dir = newDir;
}

Bike::~Bike() {
}

Direction Bike::getDir()
{
	return dir;
}

void Bike::setDir(Direction const &newDir)
{
	dir = newDir;
}



//After moving, check for crash, log position into vector
void Bike::update(float window_x, float window_y)
{
	if (dir != CRASH)
	{
		checkCrash(window_x, window_y);
        
	}
}

//Pass in dimensions of window and the bike to check
//uncomment the rest of function when player 2 is created
void Bike::checkCrash(float window_x, float window_y)
{
	switch (this->getDir())
	{
	case UP:
		if (this->getPosition().y <= 0)
		{
			this->setDir(CRASH);
			cout << "CRASH!" << endl;
		}
		break;
	case RIGHT:
		if (this->getPosition().x >= (window_x - 10))
		{
			this->setDir(CRASH);
			cout << "CRASH!" << endl;
		}
		break;
	case DOWN:
		if (this->getPosition().y >= (window_y - 10))
		{
			this->setDir(CRASH);
			cout << "CRASH!" << endl;
		}
		break;
	case LEFT:
		if (this->getPosition().x <= 0)
		{
			this->setDir(CRASH);
			cout << "CRASH!" << endl;
		}
		break;
	}
}