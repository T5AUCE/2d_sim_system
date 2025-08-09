#include <SFML/Graphics.hpp>
#include <iostream>
#include "render.h"
#include "user_input.h"

int main()
{
    constexpr int window_width = 800;
    constexpr int window_length = 800;
    const float framerate = 60.0f;
    const float rows = 75.0f;
    const float columns = 75.0f;
    const float radius = 1.0f;
    const sf::Vector2f acceleration{ 40.0f,40.0f };

    float horizontal_increment = 0 - radius;
    float vertical_increment = 0 - radius;
    
    sf::Color color;
    sf::RenderWindow window(sf::VideoMode({ window_width,window_length }), "2d_sim_system");
    window.setFramerateLimit(framerate);

    Render render(window);
    UserInput user;

    std::vector<Particle> dots;

    for (int i = 0; i < rows; i++) {
        horizontal_increment = 0 - radius;
        vertical_increment += window_length/ (columns + 1);
        for (int j = 0; j < columns; j++) {
            horizontal_increment += window_width / (rows + 1);
            sf::Vector2f position{horizontal_increment,vertical_increment};

            int generate_color = std::rand() % 8;
            if (generate_color == 1) {
                color = sf::Color::Blue;
            }
            else if (generate_color == 2) {
                color = sf::Color::Red;
            }
            else if (generate_color == 3) {
                color = sf::Color::Magenta;
            }
            else if (generate_color == 4) {
                color = sf::Color::Green;
            }
            else if (generate_color == 5) {
                color = sf::Color::Yellow;
            }
            else if (generate_color == 6) {
                color = sf::Color::Cyan;
            }
            else if (generate_color == 7) {
                color = sf::Color::White;
            }

            dots.emplace_back(position, acceleration, color, radius);
        }
    }

    /* Main Loop */
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
            user.mouse_click(dot, window, framerate);
            user.freeze(dot, window);
            render.create(dot,window_length,window_width,framerate);
        }
        window.display();
    }
}