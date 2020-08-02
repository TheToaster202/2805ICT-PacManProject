#pragma once

#include "PacManGame.h"

class GameObject {

public:

	//Ctors
	GameObject(const char* texturePath);
	~GameObject();

	void updateObject();
	void renderObject();

private:

	//The characters will just jump to a new tile rather than traditionally move
	// int xPos, yPos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;

};