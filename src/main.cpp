#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML Test");
    sf::Clock clock;  

    sf::RectangleShape player(sf::Vector2f(10, 10));   
    player.setFillColor(sf::Color::Red);
    
    sf::Vector2f dir(1,0);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        dir = sf::Vector2f(0, 1);
                        break;

                    case sf::Keyboard::Down:
                        dir = sf::Vector2f(0, -1);
                        break;

                    case sf::Keyboard::Left:
                        dir = sf::Vector2f(-1 ,0);
                        break;

                    case sf::Keyboard::Right:
                        dir = sf::Vector2f(1, 0);
                        break;

                    default:
                        break;
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        if(player.getPosition().x > window.getSize().x - player.getSize().x)
            dir.x = -dir.x;
        if(player.getPosition().x < 0)
            dir.x = -dir.x;
        if(player.getPosition().y > window.getSize().y - player.getSize().y)
            dir.y = -dir.y;
        if(player.getPosition().y < 0)
            dir.y = -dir.y;


        sf::Time delta = clock.restart();
        float dt = delta.asSeconds();

        player.move(dir * dt);

        window.clear(sf::Color::Green);
        window.draw(player);
        window.display();
    }

    return 0;
}
