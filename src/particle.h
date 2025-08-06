#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

struct Particle {
	sf::Vector2f position;
	sf::Vector2f prev_position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	float radius = 10.0f;

	Particle(sf::Vector2f position_, sf::Vector2f acceleration_) :
		position{position_},
		prev_position{ position_},
		acceleration{10.0f,10.0f}
	{}

	void update(float deltaT) {
		sf::Vector2f displace = position - prev_position;
		displace = atBounds(displace);
		prev_position = position;
		position = position + displace + acceleration * (deltaT * deltaT);
		acceleration = {};
	}

	sf::Vector2f atBounds(sf::Vector2f displace) {
		if (position.x < radius || 800 - position.x < radius) {
			sf::Vector2f flip_x{ -1,1 };
			acceleration = acceleration.componentWiseMul(flip_x);
			displace = displace.componentWiseMul(flip_x);
		}
		if (position.y < radius || 800 - position.y < radius) {
			sf::Vector2f flip_y{ 1,-1 };
			acceleration = acceleration.componentWiseMul(flip_y);
			displace = displace.componentWiseMul(flip_y);
		}
		return displace;
	}

	void setVelocity(sf::Vector2f v) {
		velocity = v;
	}

	void changeVelocity(sf::Vector2f v) {
		velocity = v;
	}

	void changeAcceleration(sf::Vector2f a) {
		acceleration += a;
	}

	sf::Vector2f getPosition() {
		return position;
	}

	sf::Vector2f getVelocity() {
		return velocity;
	}

	sf::Vector2f getAcceleration() {
		return acceleration;
	}

	float getRadius() {
		return radius;
	}
};