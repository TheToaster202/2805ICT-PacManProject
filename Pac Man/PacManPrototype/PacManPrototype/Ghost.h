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

	int getX();		//! Get X postion
	int getY();		//! Get Y postion

	int getPacX();	//! Get Player X position
	int getPacY();	//! Get Player Y postion

	int getType();	//! Get Ghost type
	

private:

	int gType;	//Ghost type
	int mapX, mapY;	//Map Co-ords
	int direction;	//Ghosts current direction, used for animations and collision detection
	int pacX, pacY; //Player position
	int xVel, yVel; //Movement directions, used to move the ghost
	int mode; //Chase-1, scatter-2, frightened-3, eaten-4 (For now, only chase mode will be used)
	int pacDirection;	//Players direction

	bool isMoving;

	std::pair<int, int>returnTarget;

	AI gAI;
	
	SDL_Texture* gTexture;
	SDL_Rect sRect, dRect;
};