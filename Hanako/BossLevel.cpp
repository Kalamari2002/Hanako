#include "BossLevel.h"
BossLevel::BossLevel() {
	this->InitializeVariables();	//As the BossLevel object is initialized, it initializes its variables
}

void BossLevel::InitializeVariables() {

	sceneObjects.push_back(&player);	//The player address is stored in the sceneObjects vector, which is declared in the Scene parent class
}

void BossLevel::UpdateScene() {
	for (int i = 0; i < sceneObjects.size(); i++) {		
		sceneObjects.at(i)->Update();	//Calling every Update function from each GameObject in the BossLevel scene
	}
}