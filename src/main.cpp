
#include <SFML/Graphics.hpp>
#include <iostream>
#include "render.h"

int main()
{
    constexpr int32_t window_width = 800;
    constexpr int32_t window_length = 800;

    sf::RenderWindow window(sf::VideoMode({window_width,window_length}), "2d_sim_system");
    window.setFramerateLimit(144);

    UserInput user;

    Render render(window);
    Particle dot({ 200,400 },{10,10});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();

        user.mouse_click(dot, window);
        

        render.create(dot);
        window.display();
    }
}