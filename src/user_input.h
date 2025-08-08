#include "particle.h"

class UserInput {
public:
	static void mouse_click(Particle& particle, sf::RenderWindow& window) {
		sf::Vector2f stop_range{ 5.0f,5.0f };
		sf::Vector2f soften{ 0.1f,0.1f };

		sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::Vector2f distance = mouse_pos - particle.position;
		sf::Vector2f opposite = particle.position - mouse_pos;

		sf::Vector2f toward = gravity_effect(distance);
		sf::Vector2f away = gravity_effect(opposite);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			// Stop at cursor
			if (distance.length() < stop_range.length()) {
				sf::Vector2f displace = particle.position - particle.prev_position;
				sf::Vector2f distance_ratio{distance.length()/stop_range.length(),distance.length() / stop_range.length()};
				particle.prev_position += displace.componentWiseMul(distance_ratio);
			}
			else {
				particle.changeAcceleration(toward);
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{
			particle.changeAcceleration(away);
		}
	}

	static void freeze(Particle& particle, sf::RenderWindow& window) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
			particle.prev_position = particle.position;
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
