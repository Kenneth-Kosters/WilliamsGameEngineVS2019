#include "Ship.h"
#include "Laser.h"
#include <stdlib.h>  

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}
void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
const float SPEED = 0.3f;
const int FIRE_DELAY = 200;
const int FIRE_DELAY1 = 200;
const int FIRE_DELAY2 = 200;
// Omitted code...

void Ship::update(sf::Time& elapsed) 
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x; 
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) x += SPEED * msElapsed;
	sprite_.setPosition(sf::Vector2f(x, y));
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	assignTag("ship");
	setCollisionCheckEnabled(true);
	

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}
	if (fireTimer1_ > 0)
	{
		fireTimer1_ -= msElapsed;
	}
	if (fireTimer2_ > 0)
	{
		fireTimer2_ -= msElapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);
		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
		laser_.setBuffer(GAME.getSoundBuffer("Resources/laser.wav"));
		laser_.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer1_ <= 0)
	{
		fireTimer1_ = FIRE_DELAY1;
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float laserX = x + (bounds.width - 30);
		float laserY = y + (bounds.height - 105);
		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer2_ <= 0)
	{
		fireTimer2_ = FIRE_DELAY2;
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float laserX = x + (bounds.width - 30);
		float laserY = y + (bounds.height - 15);
		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);
	}
	if (pos.x < 0) {
		sprite_.setPosition(sf::Vector2f(x + 800, y));
	}
	if (pos.x > 800) {
		sprite_.setPosition(sf::Vector2f(x - 800, y));
	}
	if (pos.y < 0) {
		sprite_.setPosition(sf::Vector2f(x, y + 500));
	}
	if (pos.y > 500) {
		sprite_.setPosition(sf::Vector2f(x, y - 500));
	}
}

sf::FloatRect Ship::getCollisionRect()
{
	return sf::FloatRect();
}
