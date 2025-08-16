#include <box2d.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include "BoxColision.hpp"
#include "TaskScheduler.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "My window");
    window.setFramerateLimit(60);
    
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = (b2Vec2){0.f, -9.8f};
    b2WorldId worldId = b2CreateWorld(&worldDef);

    float timeStep = 1.0f / 60.f;
    int subStep = 4;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            
            if (event->getIf<sf::Event::KeyPressed>()) {
                if (event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scan::Escape)
                    window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }
    b2DestroyWorld(worldId);
}