#pragma once

#include "PacManGame.h"
#include "TileMap.h"

class GameObject {

public:

	//Ctors
	GameObject(const char* texturePath);
	~GameObject();

	void updateObject(TileMap *map);
	void renderObject();
	void moveObject(const int &currentTile, const int &nextTile);

private:

	//The characters will just jump to a new tile rather than traditionally move
	// int xPos, yPos;

	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;

	//Holds the player characters position on the 2d map array
	int mapX;
	int mapY;

	//Players moving direction (Still - 0, Up - 1, Down - 2, Right - 3, Left - 4)
	int direction;

};