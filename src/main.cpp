#include <SFML/Graphics.hpp>
#include <iostream>
#include "render.h"
#include "user_input.h"

int main()
{
    constexpr int32_t window_width = 800;
    constexpr int32_t window_length = 800;
    const int rows = 10;
    const int columns = 10;
    const sf::Vector2f acceleration{ 10.0f,10.0f };

    float horizontal_increment = 0.0f;
    float vertical_increment = 0.0f;
    
    sf::Color color;
    sf::RenderWindow window(sf::VideoMode({ window_width,window_length }), "2d_sim_system");
    window.setFramerateLimit(144);
    Render render(window);
    UserInput user;

    std::vector<Particle> dots;

    for (int i = 0; i < rows; i++) {
        horizontal_increment = 0;
        vertical_increment += window_width / (columns + 1);
        for (int j = 0; j < columns; j++) {
            horizontal_increment += window_length / (rows + 1);
            sf::Vector2f position{horizontal_increment,vertical_increment};

            int generate_color = std::rand() % 4;
            if (generate_color == 1) {
                color = sf::Color::Blue;
            }
            else if (generate_color == 2) {
                color = sf::Color::Red;
            }
            else if (generate_color == 3) {
                color = sf::Color::Magenta;
            }
            else {
                color = sf::Color::Green;
            }

            dots.emplace_back(position, acceleration,color);
        }
    }

    /*Particle dot({ 200,400 },{10,10});*/

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

        for (auto& dot : dots) {
            user.mouse_click(dot, window);
            render.create(dot);
        }

        window.display();
    }
}