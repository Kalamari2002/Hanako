#include "PlayerBullet.h"
PlayerBullet::PlayerBullet():GameObject("./Sprites/Player/playerbullet.png", sf::Vector2i(150, 500), sf::Vector2f(.5f, .5f)) {
	std::cout << "BULLET SPAWNED" << std::endl;
}

void PlayerBullet::Movement() {
	const int VEL = 1000;
	this->position.y -= VEL * deltaTime;
}

void PlayerBullet::Update() {
	GameObject::Update();
	Movement();
}