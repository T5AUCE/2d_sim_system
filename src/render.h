#pragma once
#include "particle.h"
#include "user_input.h"

class Render {
private:
	sf::RenderTarget& target;
	sf::CircleShape circle;

public:
	Render(sf::RenderTarget& target_) : 
		target{target_},
		circle(1.0f)
	{}

	void create(Particle& particle) {
		target.clear(sf::Color::Black);
		
		float dt = 1.0f / 60;
		particle.update(dt);

		circle.setPosition(particle.getPosition());
		circle.setScale({particle.getRadius(),particle.getRadius()});
		circle.setFillColor(sf::Color::Blue);
		target.draw(circle);
	}
};