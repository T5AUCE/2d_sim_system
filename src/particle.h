#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

struct Particle {
	sf::Vector2f position;
	sf::Vector2f prev_position;
	sf::Vector2f acceleration;
	sf::Color color;
	float radius = 2.0f;

	Particle(sf::Vector2f position_, sf::Vector2f acceleration_, sf::Color color_, float radius_) :
		position{position_},
		prev_position{ position_},
		acceleration{acceleration_},
		color{color_},
		radius{radius_}
	{}

	void update(float dt, int l, int w) {
		sf::Vector2f displace = position - prev_position;
		displace = atBounds(displace, l, w);
		prev_position = position;
		position = position + displace + acceleration * (dt * dt);
		acceleration = {};
	}

	sf::Vector2f atBounds(sf::Vector2f displace, int l, int w) {
		if (position.x <= 0 || w - position.x < radius * 2) {
			sf::Vector2f flip_x{ -1,1 };
			if (position.x <= 0) {
				position.x = 1;
			}
			else {
				position.x = w - radius * 2;
			}
			acceleration = acceleration.componentWiseMul(flip_x);
			displace = displace.componentWiseMul(flip_x);
		}
		if (position.y <= 0 || l - position.y < radius * 2) {
			sf::Vector2f flip_y{ 1,-1 };
			if (position.y <= 0) {
				position.y = 1;
			}
			else {
				position.y = l - radius * 2;
			}
			acceleration = acceleration.componentWiseMul(flip_y);
			displace = displace.componentWiseMul(flip_y);
		}
		return displace;
	}

	void changeAcceleration(sf::Vector2f a) {
		acceleration += a;
	}
};