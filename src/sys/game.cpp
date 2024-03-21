#include <sys/game.hpp>

Game::Game()
: mWindow(sf::VideoMode(640,480), "mi App SFML")
, mPlayer() 
{
    mPlayer.setRadius(40.f);
    mPlayer.setFillColor(sf::Color::Cyan);
    mPlayer.setPosition(100.f, 100.f);

}

void Game::run()
{
    sf::Clock clock;
    //sf::Time timeOfLastUpdate = sf::Time::Zero;
    
    while(mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        processEvent();
        update(dt); 
        /*
        while(timeOfLastUpdate > TimePerFrame)
        {
            timeOfLastUpdate -= TimePerFrame;            
            processEvent();
            update(TimePerFrame);
        }*/
        render();
    }
}

void Game::processEvent()
{
    sf::Event events;
    while(mWindow.pollEvent(events))
    {
        //if(events.type == sf::Event::Closed)
        //    mWindow.close();
        switch(events.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(events.key.code, true );
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(events.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }//switch
    }
}

void Game::update(sf::Time deltatime)
{
    //logica del juego
    sf::Vector2f movement(0.f, 0.f);
    if(mMovingUp   ) { movement.y -= 1.f; }
    if(mMovingDown ) { movement.y += 1.f; }
    if(mMovingLeft ) { movement.x -= 1.f; }
    if(mMovingRight) { movement.x += 1.f; }
    mPlayer.move(movement);
}

void Game::render()
{

    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if      (key == sf::Keyboard::W) mMovingUp    = isPressed;
    else if (key == sf::Keyboard::S) mMovingDown  = isPressed; 
    else if (key == sf::Keyboard::A) mMovingLeft  = isPressed; 
    else if (key == sf::Keyboard::D) mMovingRight = isPressed; 
}