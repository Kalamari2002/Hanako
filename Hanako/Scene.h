#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
class Scene
{
private:
	virtual void InitializeVariables();		//Every scene will contain different variables, thus this function will be virtual
public:
	std::vector<GameObject*> sceneObjects;		//sceneObjects is a vector of ALL GameObjects in a given scene. This makes updating GameObjects much easier
	virtual void UpdateScene();
	Scene();
};

