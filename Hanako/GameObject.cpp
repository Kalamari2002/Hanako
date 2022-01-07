#include "GameObject.h"
GameObject::GameObject(std::string spriteAddress, sf::Vector2i initPos, sf::Vector2f size) {
	
	//Encapsulating variables
	this->textureAddress = spriteAddress;
	this->position = initPos;
	this->size = size;	

	spriteTexture.loadFromFile(textureAddress);		//Setting the sprite texture from whatever address is specified in the constructor
	this->sprite.setTexture(spriteTexture);		//The sprite then uses the sprite texture
	this->sprite.setScale(this->size);			//The sprite scale will be the size from the constructor

	Update();

}

void GameObject::CentralizeSprite() {		//Centralizing the sprite with the GameObject position

	//textureSize will take the size of the texture file and multiply it by the size, this way the conversions are consistent with the specified size
	sf::Vector2i textureSize(this->sprite.getTexture()->getSize().x * this->size.x, this->sprite.getTexture()->getSize().y * this->size.y);


	//To centralize the sprite, we'll move the sprite half its width to the left and half its height up
	float centrX = this->position.x - (textureSize.x / 2);		
	float centrY = this->position.y - (textureSize.y / 2);

	this->sprite.setPosition(centrX, centrY);
}

void GameObject::Update() {
	CentralizeSprite();	//By default, the GameObject will centralize its sprite every frame
}