#include "particle.h"

class UserInput {
public:
	static void mouse_click(Particle& particle, sf::RenderWindow& window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			sf::Vector2f soften{ 0.2,0.2 };
			sf::Vector2f toward = soften.componentWiseMul(mousePos - particle.getPosition());
			
			particle.changeAcceleration(toward);
		}
	}
};
