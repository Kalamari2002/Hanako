#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
class GameObject		//Every GameObject will have a sprite, position on screen and size
{
private:
	sf::Texture spriteTexture;
	void CentralizeSprite();		//The sprite position is actually at the (0,0) of the image file. This function makes it so that the sprite's center (not top left corner) is always on top of the GameObject position
public:
	std::string textureAddress;
	sf::Vector2i position;
	sf::Vector2f size;

	sf::Sprite sprite;


	GameObject(std::string spriteAddress, sf::Vector2i initPos, sf::Vector2f size);		//When initialized, a GameObject requires the texture address for the sprite, initial position and size
	virtual void Update();		//Since every scene will Update different objects and opperate in different ways, the parent Update function is virtual so that its children may override it if necessary
};

