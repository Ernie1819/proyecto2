#include <SFML/Graphics.hpp>

class Game 
{

public:
        Game();
    void run();

private:
    void processEvent();
    void       update(sf::Time);
    void       render();
    void handlePlayerInput(sf::Keyboard::Key, bool);


private:
    sf::RenderWindow mWindow;
    sf::CircleShape  mPlayer;
    bool    mMovingUp{false};
    bool  mMovingDown{false};
    bool  mMovingLeft{false};
    bool mMovingRight{false};
    sf::Time TimePerFrame = sf::seconds(1.f/60.f);

};