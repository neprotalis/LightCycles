#include <iostream>
#include "cScreen.h"
#include "Bike.h"

#include <SFML/Graphics.hpp>


class gameScreen : public cScreen{
private:
    // Create Bikes
    Bike p1Bike;
    Bike p2Bike;
    bool grid[640][480];
public:
    gameScreen();
    void initBikes();
    virtual int Run(sf::RenderWindow &App);
};

gameScreen::gameScreen(void)
{
    // Initialize Bikes
    initBikes();
}

void gameScreen::initBikes() {
    p1Bike.setFillColor(sf::Color::Red);
    p1Bike.setSize({ 10, 10 });
    p1Bike.setPosition({ 0,240 });
    p1Bike.setDir(RIGHT);
    p2Bike.setFillColor(sf::Color::Blue);
    p2Bike.setSize({ 10, 10 });
    p2Bike.setPosition({ 630,240 });
    p2Bike.setDir(LEFT);
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
            grid[i][j] = false;
        }
    }
}

int gameScreen::Run(sf::RenderWindow &App)
{
    //// Set Background
    //sf::Texture texture;
    //if (!texture.loadFromFile("blueGrid.png")) {
    //    std::cout << "Error loading texture newTexture.png" << std::endl;
    //    return(-1);
    //}
    //sf::Sprite background(texture);

    sf::Texture previousScreen;
    sf::Sprite background;
    sf::Text p1Win;
    sf::Text p2Win;
    sf::Font font;

    bool cleared = false;

    previousScreen.create(App.getSize().x, App.getSize().y);


    if (!font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return (-1);
    }

    p1Win.setColor(sf::Color::Yellow);
    p1Win.setPosition(App.getSize().x / 3, App.getSize().y / 3);
    p1Win.setFont(font);
    p1Win.setCharacterSize(24);
    p1Win.Bold;
    p1Win.setString("PLAYER 1 WINS");

    p2Win.setColor(sf::Color::Yellow);
    p2Win.setPosition(App.getSize().x / 3, App.getSize().y / 3);
    p2Win.setFont(font);
    p2Win.setCharacterSize(24);
    p2Win.Bold;
    p2Win.setString("PLAYER 2 WINS");

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
                    previousScreen.update(App);
                    background.setTexture(previousScreen);
                    return (0);
                    break;
                case sf::Keyboard::W: // move p1 up
                    //p1IsPressed = true;
                    if (p1Bike.getDir() != DOWN && p1Bike.getDir() != CRASH)
                    {
                        p1Bike.setDir(UP);
                    }
                    break;
                case sf::Keyboard::A:// move p1 left
                        //p1IsPressed = true;
                    if (p1Bike.getDir() != RIGHT && p1Bike.getDir() != CRASH)
                    {
                        p1Bike.setDir(LEFT);
                    }
                    break;
                case sf::Keyboard::S://move p1 down
                    //p1IsPressed = true;
                    if (p1Bike.getDir() != UP && p1Bike.getDir() != CRASH)
                    {
                        p1Bike.setDir(DOWN);
                    }
                    break;
                case sf::Keyboard::D://move p1 right
                    //p1IsPressed = true;
                    if (p1Bike.getDir() != LEFT && p1Bike.getDir() != CRASH)
                    {
                        p1Bike.setDir(RIGHT);
                    }
                    break;

                case sf::Keyboard::Up: // move p2 up
                    //p2IsPressed = true;
                    if (p2Bike.getDir() != DOWN && p2Bike.getDir() != CRASH)
                    {
                        p2Bike.setDir(UP);
                    }
                    break;
                case sf::Keyboard::Left:// move p2 left
                    //p2IsPressed = true;
                    if (p2Bike.getDir() != RIGHT && p2Bike.getDir() != CRASH)
                    {
                        p2Bike.setDir(LEFT);
                    }
                    break;
                case sf::Keyboard::Down://move p2 down
                    //p1IsPressed = true;
                    if (p2Bike.getDir() != UP && p2Bike.getDir() != CRASH)
                    {
                        p2Bike.setDir(DOWN);
                    }
                    break;
                case sf::Keyboard::Right://move p2 right
                    //p1IsPressed = true;
                    if (p2Bike.getDir() != LEFT && p2Bike.getDir() != CRASH)
                    {
                        p2Bike.setDir(RIGHT);
                    }
                    break;
                /*case sf::Event::KeyReleased:
                {
                if (p1IsPressed && (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::S
                || event.key.code == sf::Keyboard::D))
                {
                p1IsPressed = false;
                }
                */
                default:
                    break;
                }
            }
        }

        //Updating Dir
        if (p1Bike.getDir() != CRASH)
        {
            switch (p1Bike.getDir())
            {
            case UP:
                grid[(int)p1Bike.getPosition().x][(int)p1Bike.getPosition().y] = true;
                p1Bike.move(0, -1);
                break;
            case RIGHT:
                grid[(int)p1Bike.getPosition().x][(int)p1Bike.getPosition().y] = true;
                p1Bike.move(1, 0);
                break;
            case DOWN:
                grid[(int)p1Bike.getPosition().x][(int)p1Bike.getPosition().y] = true;
                p1Bike.move(0, 1);
                break;
            case LEFT:
                grid[(int)p1Bike.getPosition().x][(int)p1Bike.getPosition().y] = true;
                p1Bike.move(-1, 0);
                break;
            }

        }

        if (p2Bike.getDir() != CRASH)
        {
            switch (p2Bike.getDir())
            {
            case UP:
                grid[(int)p2Bike.getPosition().x][(int)p2Bike.getPosition().y] = true;
                p2Bike.move(0, -1);
                break;
            case RIGHT:
                grid[(int)p2Bike.getPosition().x][(int)p2Bike.getPosition().y] = true;
                p2Bike.move(1, 0);
                break;
            case DOWN:
                grid[(int)p2Bike.getPosition().x][(int)p2Bike.getPosition().y] = true;
                p2Bike.move(0, 1);
                break;
            case LEFT:
                grid[(int)p2Bike.getPosition().x][(int)p2Bike.getPosition().y] = true;
                p2Bike.move(-1, 0);
                break;
            }

        }

        // checking collisions
        p1Bike.update(App.getSize().x, App.getSize().y);
        p2Bike.update(App.getSize().x, App.getSize().y);
        if (grid[(int)p1Bike.getPosition().x][(int)p1Bike.getPosition().y] == true)
            p1Bike.setDir(CRASH);
        if (grid[(int)p2Bike.getPosition().x][(int)p2Bike.getPosition().y] == true)
            p2Bike.setDir(CRASH);

        // Display Position
        if (p1Bike.getDir() != CRASH)
        {
            cout << "Player 1 Bike Position: " << p1Bike.getPosition().x << "," << p1Bike.getPosition().y << endl;
        }
        if (p2Bike.getDir() != CRASH)
        {
            cout << "Player 2 Bike Position: " << p2Bike.getPosition().x << "," << p2Bike.getPosition().y << endl;
        }


        //Clearing screen
        App.clear();
        //Drawing
        App.draw(background);
        App.draw(p1Bike);
        App.draw(p2Bike);
        if (p2Bike.getDir() == CRASH) {
            App.draw(p1Win);
            App.display();
            App.waitEvent(Event);
            Running = false;
            return 0;
        }
        if (p1Bike.getDir() == CRASH) {
            App.draw(p2Win);
            App.display();
            App.waitEvent(Event);
            Running = false;
            return 0;
        }
        App.display();
        if (cleared) {
            previousScreen.update(App);
            background.setTexture(previousScreen);
        }
        cleared = true;
    }
    //Never reaching this point normally, but just in case, exit the application
    return -1;
}