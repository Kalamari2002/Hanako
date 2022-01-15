#pragma once
#include "GameObject.h"
extern float deltaTime;

class PlayerBullet :
    public GameObject
{
private:
    void Movement();
public:
    PlayerBullet();
    virtual void Update() override;

};

