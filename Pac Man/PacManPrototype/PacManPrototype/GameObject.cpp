#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturePath) {

	objectTexture = TextureController::LoadTexture(texturePath);

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 48;
	destRect.w = 48;;

	mapX = 10;
	mapY = 30;

	destRect.x = mapX * 24 - 10;
	destRect.y = (mapY * 24 - 10) + 80;

	direction = 3;

	currentTile = 0;
	nextTile = 0;

	animIndex = 0;
	indexer = 0;
	
	xVel = 0;
	yVel = 0;

	isMoving = false;

}

GameObject::~GameObject(){
	SDL_DestroyTexture(objectTexture);
}

//! Encapsulates all items about the player character that are to updated every frame
void GameObject::updateObject(TileMap *map, PacScore & score, const int &newDir, const int &timeStep) {

	if (!isMoving) {
		direction = newDir;
	}

	currentTile = map->getMapVal(mapX, mapY);

	if (currentTile == 15 || currentTile == 16) {
		map->changeTile(mapX, mapY);
		
		if (currentTile == 16) {
			score.increaseScore(1, timeStep);
		}

		if (currentTile == 15) {
			score.increaseScore(2, timeStep);
		}
	}

	//Calculates the next tile based on the direction of the player
	
	switch (direction) {
	case 0:
		//nextTile = currentTile;
		break;
	case 1:
		//mapY += 1;
		nextTile = map->getMapVal(mapX, mapY - 1);
		yVel = (-1 * objVel);
		xVel = 0;
		break;
	case 2:
		nextTile = map->getMapVal(mapX, mapY + 1);
		yVel = objVel;
		xVel = 0;
		break;
	case 3:
		nextTile = map->getMapVal(mapX + 1, mapY);
		xVel = objVel;
		yVel = 0;
		break;
	case 4:
		//mapY += 1;
		nextTile = map->getMapVal(mapX - 1, mapY);
		xVel = (-1 * objVel);
		yVel = 0;
		break;
	default:
		direction = 0;
		nextTile = currentTile;
		break;
	}

	//Moves the player
	moveObject(timeStep);
	animateObject();
}

void GameObject::renderObject() {
	SDL_RenderCopy(PacManGame::renderer, objectTexture, &srcRect, &destRect);
}

//! Method that will handle calculating the next position of the player char
void GameObject::moveObject(const int &timeStep) {

	if (nextTile != 7 && nextTile != 16 && nextTile != 15) {
		direction = 0;
		return;
	}

	if (destRect.y == ((mapY+yVel) * 24 - 10) + 80 && destRect.x == ((mapX+xVel) * 24 - 10)) {
		mapY += yVel;
		mapX += xVel;
		isMoving = false;
	}
	else {

		destRect.x += xVel * 4;
		destRect.y += yVel * 4;
		isMoving = true;

	}
	
}

//! Methods that handels animating the player character, based on the direction they are currently moving
void GameObject::animateObject() {

	//std::cout << animIndex << std::endl;

	if (animIndex == 2) {
		indexer = -1;
	}
	else if (animIndex == 0) {
		indexer = 1;
	}
	
	switch (direction) {
	case 1:
		srcRect.x = upWakaX[animIndex];
		srcRect.y = upWakaY[animIndex];
		break;
	case 2:
		srcRect.x = downWakaX[animIndex];
		srcRect.y = downWakaY[animIndex];
		break;
	case 3:
		srcRect.x = rightWakaX[animIndex];
		srcRect.y = rightWakaY[animIndex];
		break;
	case 4:
		srcRect.x = leftWakaX[animIndex];
		srcRect.y = leftWakaY[animIndex];
		break;
	default:
		srcRect.x = 0;
		srcRect.y = 0;
		break;
	}
	
	animIndex += indexer;
	
}

int GameObject::getX() { return mapX; }
int GameObject::getY() { return mapY; }
int GameObject::getDirection() { return direction; }