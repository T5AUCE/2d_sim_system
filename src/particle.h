#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

struct Particle {
	sf::Vector2f position;
	sf::Vector2f prev_position;
	sf::Vector2f acceleration;
	sf::Color color;
	float radius = 3.0f;

	Particle(sf::Vector2f position_, sf::Vector2f acceleration_, sf::Color color_) :
		position{position_},
		prev_position{ position_},
		acceleration{10.0f,10.0f},
		color{color_}
	{}

	void update(float deltaT) {
		sf::Vector2f displace = position - prev_position;
		displace = atBounds(displace);
		prev_position = position;
		position = position + displace + acceleration * (deltaT * deltaT);
		acceleration = {};
	}

	sf::Vector2f atBounds(sf::Vector2f displace) {
		if (position.x <= 0 || 800 - position.x < radius * 2) {
			sf::Vector2f flip_x{ -1,1 };
			if (position.x <= 0) {
				position.x = 1;
			}
			else {
				position.x = 800 - radius * 2;
			}
			acceleration = acceleration.componentWiseMul(flip_x);
			displace = displace.componentWiseMul(flip_x);
		}
		if (position.y <= 0 || 800 - position.y < radius * 2) {
			sf::Vector2f flip_y{ 1,-1 };
			acceleration = acceleration.componentWiseMul(flip_y);
			displace = displace.componentWiseMul(flip_y);
		}
		return displace;
	}

	/* Changer */
	void changeAcceleration(sf::Vector2f a) {
		acceleration += a;
	}
};