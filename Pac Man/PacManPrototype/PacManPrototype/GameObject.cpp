#include "GameObject.h"
#include "TextureManager.h"
#include "TileMap.h"


GameObject::GameObject(const char* texturePath) {

	objectTexture = TextureController::LoadTexture(texturePath);

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 48;
	destRect.w = 48;;

	mapX = 2;
	mapY = 2;

	destRect.x = mapX * 24 - 10;
	destRect.y = mapY * 24 - 10;

	direction = 3;

	currentTile = 0;
	nextTile = 0;

	animIndex = 0;
	indexer = 0;

}

GameObject::~GameObject(){}

//! Encapsulates all items about the player character that are to updated every frame
void GameObject::updateObject(TileMap *map, const int &newDir) {

	//if (direction != 0 && (destRect.y + 10) % 24 == 0 && (destRect.x + 10) % 24 == 0) {
		mapY = (destRect.y + 10) / 24;
		mapX = (destRect.x + 10) / 24;
		currentTile = map->getMapVal(mapX, mapY);
	//}

	direction = newDir;

	//Calculates the next tile based on the direction of the player
	switch (direction) {
	case 0:
		//nextTile = currentTile;
		break;
	case 1:
		mapY += 1;
		nextTile = map->getMapVal(mapX, mapY - 1);
		break;
	case 2:
		nextTile = map->getMapVal(mapX, mapY + 1);
		break;
	case 3:
		nextTile = map->getMapVal(mapX + 1, mapY);
		break;
	case 4:
		mapY += 1;
		nextTile = map->getMapVal(mapX - 1, mapY);
		break;
	default:
		direction = 0;
		//nextTile = currentTile;
		break;
	}

	std::cout << mapX << " " << mapY << " " << direction << " " << nextTile << std::endl << destRect.x << " " << destRect.y << std::endl;

	//Moves the player
	moveObject(currentTile, nextTile);
	animateObject();
	
}

void GameObject::renderObject() {
	SDL_RenderCopy(PacManGame::renderer, objectTexture, &srcRect, &destRect);
}

//! Method that will handle calculating the next position of the player char
void GameObject::moveObject(const int &currentTile, const int &nextTile) {
	
	int posTest= 0;

	if (nextTile != 7 && nextTile != 16 && nextTile != 15) {
		direction = 0;
		return;
	}

	switch (direction) {
	case 1:
		destRect.y -= 4;
		break;
	case 2:
		destRect.y += 4;

		break;
	case 3:
		destRect.x += 4;

		break;
	case 4:
		destRect.x -= 4;

		break;
	default:
		direction = 0;
		break;
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