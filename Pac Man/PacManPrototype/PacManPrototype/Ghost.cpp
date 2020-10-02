#include "Ghost.h"
#include "TextureManager.h"

Ghosts::Ghosts(int const& type, const char * texturePath){
	gTexture = TextureController::LoadTexture(texturePath);

	gType = type;

	sRect.h = 16;
	sRect.w = 16;
	sRect.x = 0;
	sRect.y = 0;

	dRect.h = 48;
	dRect.w = 48;

	mapY = 30;
	mapX = 2;

	dRect.x = mapX * 24 - 11;
	dRect.y = (mapY * 24 - 11) + 80;

	isMoving = false;

	direction = 1;

	targetX = 0;
	targetY = 0;

	xVel = 1;
	yVel = 1;

	mode = 1;

	pacDirection = 0;

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
		
		targetY = pacMan->getY();
		targetX = pacMan->getX();

		returnTarget = gAI.AIPackage(map, mapX, mapY, targetX, targetY, gType, direction, mode);

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
		sRect.x = 15;
		break;
	case 3:
		sRect.x = 47;
		break;
	case 4:
		sRect.x = 31;
		break;
	}

	if (mode == 1) {
		sRect.y = 0;
	}
	else if (mode == 4) {
		sRect.y = 15;
	}

}

int Ghosts::getX() { return mapX; }

int Ghosts::getY() { return mapY; }

int Ghosts::getType() { return gType; }