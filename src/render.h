#include "particle.h"

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
		
		float dt = 1.0f / 60;
		particle.update(dt);

		circle.setPosition(particle.position);
		circle.setScale({particle.radius,particle.radius});
		circle.setFillColor(particle.color);
		target.draw(circle);
	}
};