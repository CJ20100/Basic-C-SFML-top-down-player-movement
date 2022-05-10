#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>



int main()
{
    float PXV = 4.f;
    float PYV = 0.f;

    bool jump = false;

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(800, 500), "dinasore");
    sf::RectangleShape Player(sf::Vector2f(50.f, 50.f));
    sf::RectangleShape Ground(sf::Vector2f(700.f, 50.f));
    Ground.setPosition(-100, 100);
    Player.setPosition(100, 100);
    Player.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Player.getPosition().y > 450.f)
        {
            Player.setPosition(Player.getPosition().x, 450.f);
        }
        

		float deltaTime = clock.restart().asSeconds();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
            Player.move(0, -100 * deltaTime);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player.move(0, 100 * deltaTime);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Player.move(-100 * deltaTime, 0);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Player.move(100 * deltaTime, 0);
		}

        window.clear();
        window.draw(Player);
        window.display();
    }

    return 0;
}

