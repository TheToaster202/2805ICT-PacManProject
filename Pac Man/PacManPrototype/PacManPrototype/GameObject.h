#pragma once

#include "PacManGame.h"
#include "TileMap.h"

/// Encapulates all of the information regarding the player character including: textures, rendering, movement and collision

class GameObject {

public:

	//! Default Contructor
	GameObject(const char* texturePath);
	//! Default Destructor
	~GameObject();

	//! Updates the player character with every frame
	void updateObject(TileMap *map, int const &newDir, float const &timeStep);
	//! Renders the player character to the screen every frame
	void renderObject();
	//! Handles the movement of the player character
	void moveObject(const float &timeStep);
	//! Detects collisions
	void objectCollision(const int& currentTile, const int& nextTile);
	//! Animates the player character
	void animateObject();

private:

	//! Player character texture
	SDL_Texture* objectTexture;
	//! The rectanges which define the player characters position and current texture tile
	SDL_Rect srcRect, destRect;

	//!Holds the player characters position on the 2d map array
	double mapX;
	double mapY;

	//!Players moving direction (Still - 0, Up - 1, Down - 2, Right - 3, Left - 4)
	int direction;

	//!The current tile the player is on, and the tile directly infront of them
	int currentTile;
	int nextTile;

	//!Animation presets
	int animIndex;
	int indexer;

	int upWakaX[3] = {0, 0, 16};
	int upWakaY[3] = {0, 16, 16};

	int downWakaX[3] = {0, 32, 48};
	int downWakaY[3] = {0, 16, 16};

	int rightWakaX[3] = {0, 48, 64};
	int rightWakaY[3] = {0, 0, 0};

	int leftWakaX[3] = {0, 16, 32};
	int leftWakaY[3] = {0, 0, 0};

	static const int objVel = 100;
	
	float xVel;
	float yVel;
};