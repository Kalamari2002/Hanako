#pragma once
#include "GameObject.h"
extern float deltaTime;
class Player :
    public GameObject
{
private:
    const int VEL = 500;    //Movement velocity
    sf::Vector2i velocity;      //Current velocity of the player
public:
    Player();
    virtual void Update() override;
    void Movement();
};

