#include <SFML/Graphics.hpp>
#include <iostream>
const int windowWidth = 640;
const int windowHeight = 480;
const int windowStyle = sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize;
int main()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Autumn Harvest", windowStyle);
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setFillColor(sf::Color::Red);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    printf("e resized: %i , %i \n", event.size.width, event.size.height);
                case sf::Event::TextEntered:
                    if(event.text.unicode < 128)
                    printf("%c", event.text.unicode);
                    break;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-0.1f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(0.1f, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.move(0.0f, 0.1f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.move(0.0f, -0.1f);
        }
        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}