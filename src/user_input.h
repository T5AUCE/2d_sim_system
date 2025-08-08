#include "particle.h"

class UserInput {
public:
	static void mouse_click(Particle& particle, sf::RenderWindow& window) {
		
		sf::Vector2f stop_range{ 25.0f,25.0f };
		sf::Vector2f soften{ 0.01f,0.01f };

		sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::Vector2f distance = mouse_pos - particle.position;
		sf::Vector2f opposite = particle.position - mouse_pos;

		sf::Vector2f toward = gravity_effect(distance);
		sf::Vector2f away = gravity_effect(opposite);
		
		// Left mouse
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (distance.lengthSquared() < stop_range.lengthSquared()) {
				sf::Vector2f displace = particle.position - particle.prev_position;
				particle.prev_position += displace.componentWiseMul(soften);
			}
			else {
				particle.changeAcceleration(toward);
			}
		}

		// Right mouse
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{
				particle.changeAcceleration(away);
		}
	}
private:
	static sf::Vector2f gravity_effect(sf::Vector2f distance) {
		sf::Vector2f mass{ 50000.0f,50000.0f };
		sf::Vector2f magnitude{ distance.length(),distance.length()};
		sf::Vector2f unit_vector = distance.componentWiseDiv(magnitude);

		sf::Vector2f gravity_force = mass.componentWiseDiv(magnitude.componentWiseMul(magnitude));
		return gravity_force.componentWiseMul(unit_vector);
	}
};
