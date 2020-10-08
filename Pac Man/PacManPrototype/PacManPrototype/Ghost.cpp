#include "Ghost.h"
#include "TextureManager.h"

Ghosts::Ghosts(TileMap* map, int const& type, const char * texturePath, int const & setDifficulty){
	gTexture = TextureController::LoadTexture(texturePath, PacManGame::renderer);

	gType = type;

	sRect.h = 16;
	sRect.w = 16;
	sRect.x = 0;
	sRect.y = 0;

	dRect.h = 48;
	dRect.w = 48;

	mapY = 2;
	mapX = 2;

	isMoving = false;

	direction = 1;

	targetX = 0;
	targetY = 0;

	xVel = 1;
	yVel = 1;

	mode = 1;

	pacDirection = 0;

	difficulty = setDifficulty;

	enterScatter = 0;
	exitScatter = 0;

	returnTarget.first = 0;
	returnTarget.second = 0;

	switch (gType) {
	case 1:						//Blinky will rarely enter scatter mode, and will easily leave it
		enterScatter = 90;		//10% to enter
		exitScatter = 60;		//90% to leave	... etc

		mapY = 2;
		mapX = map->getCols()-3;
		
		break;
	case 2:
		enterScatter = 60;
		exitScatter = 70;

		mapY = 2;
		mapX = 2;

		break;
	case 3:
		enterScatter = 60;
		exitScatter = 40;

		mapY = map->getRows()-3;
		mapX = 2;

		break;
	case 4:
		enterScatter = 40;
		exitScatter = 80;

		mapY = map->getRows()-3;
		mapX = map->getCols()-3;
		break;
	}

	dRect.x = mapX * 24 - 11;
	dRect.y = (mapY * 24 - 11) + 80;

	countTimer.start();

}

Ghosts::~Ghosts() {
	SDL_DestroyTexture(gTexture);
}

void Ghosts::renderGhost() {
	SDL_RenderCopy(PacManGame::renderer, gTexture, &sRect, &dRect);
}

void Ghosts::updateGhost(TileMap* map, GameObject* pacMan) {

	//Don't do any calculations if the ghost is currently moving to a new tile
	if (!isMoving) {

		int timeStep = (countTimer.getTicks() / 100) + (rand() - 10) % 20;

		if (mode == 1) {
			int chance = (rand() - 10) % 20;		//Generate a number between 0 and 100
			chance += difficulty;			//Potentially nudging to chance out side of the tolerance

			/*if (chance <= enterScatter) {
				mode = 2;
			}*/

			if (timeStep + difficulty >= enterScatter + chance) {
				mode = 2;
				
				countTimer.stop();
				countTimer.start();

				//If not clyde
				if (gType != 4) {
					enterScatter += difficulty;
				}
			}
		}
		else if (mode == 2) {
			int chance = rand() % 100;
			chance -= difficulty;

			/*if (chance <= exitScatter) {
				mode = 1;
			}*/

			if (timeStep - difficulty >= exitScatter) {
				mode = 1;
				
				countTimer.stop();
				countTimer.start();

				//If not clyde
				if (gType != 4) {
					exitScatter -= difficulty;
				}
			}
		}
		else if (mode == 3) {

		}
		else if (mode == 4) {
			if (mapX == 14 && mapY == 12) {
				mode = 1;
				
				countTimer.stop();
				countTimer.start();
			}
		}

		//std::cout << mapX << " " << mapY << std::endl;
		
		targetY = pacMan->getY();
		targetX = pacMan->getX();

		returnTarget = gAI.AIPackage(map, mapX, mapY, targetX, targetY, gType, direction, mode, pacMan->getDirection());

		int xDiff = mapX - returnTarget.first;
		int yDiff = mapY - returnTarget.second;

		if (yDiff == 1) {
			direction = 1;

			xVel = 0;
			yVel = -1;
		}
		else if (yDiff == -1) {
			direction = 2;

			xVel = 0;
			yVel = 1;
		}
		else if (xDiff == -1) {
			direction = 3;

			xVel = 1;
			yVel = 0;
		}
		else if (xDiff == 1) {
			direction = 4;

			xVel = -1;
			yVel = 0;
		}

	}

	moveGhost();
	animateGhost();

}

void Ghosts::moveGhost() {
	
	if (dRect.y == (returnTarget.second * 24 - 11) + 80 && dRect.x == (returnTarget.first * 24 - 11)) {
		mapX = returnTarget.first;
		mapY = returnTarget.second;

		isMoving = false;
	}
	else {
		dRect.x += xVel * 4;
		dRect.y += yVel * 4;
		
		isMoving = true;
	}
}

void Ghosts::animateGhost() {
	
	if (mode == 3) {

		sRect.x = 16;
		sRect.y = 32;

		return;
	}
	
	switch (direction) {
	case 1:
		sRect.x = 0;
		break;
	case 2:
		sRect.x = 16;
		break;
	case 3:
		sRect.x = 48;
		break;
	case 4:
		sRect.x = 32;
		break;
	}

	if (mode == 1) {
		sRect.y = 0;
	}
	else if (mode == 4) {
		sRect.y = 16;
	}

}

int Ghosts::getX() { return mapX; }

int Ghosts::getY() { return mapY; }

int Ghosts::getType() { return gType; }

int Ghosts::getMode() { return mode; }