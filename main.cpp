#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    sf::RenderWindow win(sf::VideoMode(683, 384), "Sonar Battle");

    sf::Clock mainClock;
    sf::Time acc = sf::Time::Zero;
    sf::Time timestep = sf::seconds(1.f/ 30.f);

    sf::Font defaultFont;

    if (defaultFont.loadFromFile("assets/kenpix.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    sf::Text fpsCounter = sf::Text("FPS: ", defaultFont, 25);
    fpsCounter.setPosition(500.f, 25.f);

    while (win.isOpen())
    {
        // Event handling should not be capped
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        // Game logic should be capped by timestep
        while (acc > timestep)
        {
            acc -= timestep;

            //TODO: Do game logic here
        }


        // Drawing should not be capped
        win.clear(sf::Color(120, 165, 240));
        win.display();
    }

    return 0;
}
