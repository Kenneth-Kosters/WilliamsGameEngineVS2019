#pragma once
#include "Engine/GameEngine.h"

class Ship : public GameObject
{
public:
	//creates ship
	Ship();

	//Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elasped);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
	int fireTimer1_ = 0;
	int fireTimer2_ = 0;
	sf::Sound laser_;
};

typedef std::shared_ptr<Ship> ShipPtr;