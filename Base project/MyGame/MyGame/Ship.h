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

private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
};

typedef std::shared_ptr<Ship> ShipPtr;