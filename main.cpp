#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

unsigned int getFPS(const sf::Time& time) {
     return (unsigned int)(1000000.0f / time.asMicroseconds());
}

int main()
{
    sf::RenderWindow win(sf::VideoMode(683, 384), "Sonar Battle");

    sf::Clock mainClock;
    sf::Time acc = sf::Time::Zero;
    sf::Time timestep = sf::seconds(1.f / 30.f);

    sf::Font defaultFont;

    if (!defaultFont.loadFromFile("Assets/Fonts/kenpixel.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    sf::Text fpsCounter = sf::Text("FPS: ", defaultFont, 15);
    fpsCounter.setPosition(550.f, 15.f);

    while (win.isOpen())
    {
        acc+= mainClock.restart();

        // Events should not be limited by FPS
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        // Main game loop (logic)
        while (acc > timestep)
        {
            acc -= timestep;
            //TODO: Gamelogic here
        }

         // FPS is limited by the computer; we don't need to do anything
        win.clear(sf::Color(120, 165, 240));
        //Alternate colour:
        //win.clear(sf::Color(95,145,220, 255));
        fpsCounter.setString("FPS:  " + std::to_string(getFPS(acc)));
        win.draw(fpsCounter);
        win.display();
    }

    return 0;
}
