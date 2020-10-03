#pragma once

#include "PacManGame.h"
#include "TileMap.h"
#include "GameObject.h"
#include "GhostAI.h"
#include "GameTimer.h"

#include <utility>

/// <summary>
/// Class that will contain the necessary information on the ghosts. AI Packages, movement, texture creation, rendering
/// </summary>

class Ghosts {
public:

	Ghosts(TileMap * map, int const& type, const char * texturePath, int const& setDifficulty);

	~Ghosts();

	void updateGhost(TileMap * map, GameObject * pacMan);	//! Updates the state of the ghost
	void moveGhost();	//! Moves the ghost within the maze
	void renderGhost();	//! Renders ghost sprite to the screen
	void animateGhost();	//! Animates the ghost

	int getX();		//! Get X postion
	int getY();		//! Get Y postion

	int getType();	//! Get Ghost type
	

private:

	int gType;				//Ghost type (1 = Blinky, 2 = Pinky, 3= Inky, 4 = Clyde)
	int mapX, mapY;			//Map Co-ords
	int direction;			//Ghosts current direction, used for animations and collision detection
	int targetX, targetY;	//Target position
	int xVel, yVel;			//Movement directions, used to move the ghost
	int mode;				//Chase-1, scatter-2, frightened-3, eaten-4 (For now, only chase mode will be used)
	int pacDirection;		//Players direction

	int difficulty;	//influences the chance the ghosts will enter scatter mode, and the time they will spend in it
	int exitScatter;		//The target the random number generator needs to meet if the ghost is going to exit scatter mode
	int enterScatter;		//The target the random number generator needs to meet if the ghost is going to enter scatter mode

	bool isMoving;

	std::pair<int, int>returnTarget;

	AI gAI;

	GameTimer countTimer;
	
	SDL_Texture* gTexture;
	SDL_Rect sRect, dRect;
};