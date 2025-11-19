#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML Test");
    sf::Clock clock;  

    sf::RectangleShape player(sf::Vector2f(10, 10));   
    player.setFillColor(sf::Color::Red);
    
    sf::Vector2f dir(1.0f,0.0f);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        dir = sf::Vector2f(0.0f, 1.0f);
                        break;

                    case sf::Keyboard::Down:
                        dir = sf::Vector2f(0.0f, -1.0f);
                        break;

                    case sf::Keyboard::Left:
                        dir = sf::Vector2f(-1.0f, 0.0f);
                        break;

                    case sf::Keyboard::Right:
                        dir = sf::Vector2f(1.0f, 0.0f);
                        break;

                    default:
                        break;
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        sf::Time elapsed = clock.getElapsedTime(); 
        std::cout << "Time passed: " << elapsed.asSeconds() << " seconds\n";

        window.clear(sf::Color::Green);
        window.draw(player);
        player.setPosition(player.getPosition() + (dir * 10.f));
        window.display();
    }

    return 0;
}
