#pragma once
#include "Scene.h"
#include "Player.h"
#include "PlayerBullet.h"
class BossLevel :
    public Scene
{
private:
    Player player = *new Player();      //Boss Level will contain a player object
    //PlayerBullet playerBullet = *new PlayerBullet();
    virtual void InitializeVariables()override;     //Like every other scene, the boss level will initialize variables that are unique to it. Thus, it'll override the parent function InitializeVariables()

public:
    void UpdateScene();         //This function will call the Update function of every GameObject. It's called on the Game class every frame.
    BossLevel();        //Class constructors.
};

