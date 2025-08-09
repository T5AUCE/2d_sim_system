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

	void create(Particle& particle, int length, int width, float framerate) {
		float dt = 1 / framerate;
		particle.update(dt, length, width);

		circle.setPosition(particle.position);
		circle.setScale({particle.radius,particle.radius});
		circle.setFillColor(particle.color);
		target.draw(circle);
	}
};