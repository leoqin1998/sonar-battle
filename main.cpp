#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow win(sf::VideoMode(683, 384), "Sonar Battle");

    sf::Clock mainClock;
    sf::Time acc = sf::Time::Zero;
    sf::Time timestep = sf::seconds(1.f / 30.f);

    sf::Font defaultFont;

    if (!defaultFont.loadFromFile("assets/kenpixel.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    sf::Text fpsCounter = sf::Text("FPS: ", defaultFont, 15);
    fpsCounter.setOutlineColor(sf::Color::Black);
    fpsCounter.setOutlineThickness(1.f);
    fpsCounter.setPosition(500.f, 25.f);

    while (win.isOpen())
    {
        // Events should not be limited by FPS
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        while (acc > timestep)
        {
            acc -= timestep;

            //TODO: Gamelogic here
        }

        // FPS is limited by the computer; we don't need to do anything
        win.clear(sf::Color(95,145,220, 255));
        win.draw(fpsCounter);
        win.display();
    }

    return 0;
}
