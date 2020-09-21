#pragma once

#include "PacManGame.h"
#include "TileMap.h"
#include "GameObject.h"
#include "GhostAI.h"

#include <utility>

/// <summary>
/// Class that will contain the necessary information on the ghosts. AI Packages, movement, texture creation, rendering
/// </summary>

class Ghosts {
public:

	Ghosts(int const& type, const char * texturePath);

	~Ghosts();

	void updateGhost(TileMap * map, GameObject * pacMan);	//! Updates the state of the ghost
	void moveGhost();	//! Moves the ghost within the maze
	void renderGhost();	//! Renders ghost sprite to the screen
	

private:

	int gType;	//Ghost type
	int mapX, mapY;	//Map Co-ords
	int currentTile, nextTile;
	int direction;	//Ghosts current direction, used for animations and collision detection
	int pacX, pacY; //Player position
	int xVel, yVel; //Movement directions, used to move the ghost

	SDL_Texture* gTexture;
	SDL_Rect sRect, dRect;
};