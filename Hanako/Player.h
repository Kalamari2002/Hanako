#pragma once
#include "GameObject.h"
#include "PlayerBullet.h"
#include <iostream>
#include <vector>
extern float deltaTime;
class Player :
    public GameObject
{
private:
    const int VEL = 500;    //Movement velocity
    sf::Vector2i velocity;      //Current velocity of the player

    int currentBulletIndex = 0;
    int NUMBER_OF_BULLETS = 25;
    sf::Clock fireRate;
    const float TIME_BETWEEN_BULLETS = 0.05f;


public:
    PlayerBullet playerBullet = *new PlayerBullet();
    std::vector<PlayerBullet*> bullets;

    Player();

    virtual void Update() override;
    void Movement();
    void Shoot();
};

