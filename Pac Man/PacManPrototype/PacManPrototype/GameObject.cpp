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

	mapX = 7;
	mapY = 24;

	destRect.x = mapX * 24 - 10;
	destRect.y = mapY * 24 - 10;

	direction = 4;

}

GameObject::~GameObject(){}

void GameObject::updateObject(TileMap *map) {
	
	int currentTile = map->getMapVal(mapX, mapY);
	int nextTile = 0;

	//Calculates the next tile based on the direction of the player
	switch (direction) {
	case 0:
		nextTile = currentTile;
		break;
	case 1:
		nextTile = map->getMapVal(mapX, mapY - 1);
		break;
	case 2:
		nextTile = map->getMapVal(mapX, mapY + 1);
		break;
	case 3:
		nextTile = map->getMapVal(mapX + 1, mapY);
		break;
	case 4:
		nextTile = map->getMapVal(mapX - 1, mapY);
		break;
	default:
		direction = 0;
		nextTile = currentTile;
		break;
	}

	//Moves the player
	moveObject(currentTile, nextTile);

}

void GameObject::renderObject() {
	SDL_RenderCopy(PacManGame::renderer, objectTexture, &srcRect, &destRect);
}

//Method that will handle calculating the next position of the player char
void GameObject::moveObject(const int &currentTile, const int &nextTile) {
	
	//Will eventually need to get the movement controller in as well, but for now just going to need to get it working
	if (nextTile != 7 && nextTile != 16 && nextTile != 15) {
		direction = 0;
		return;
	}

	switch (direction) {
	case 1:
		destRect.y -= 1;
		break;
	case 2:
		destRect.y += 1;
		break;
	case 3:
		destRect.x += 1;
		break;
	case 4:
		destRect.x -= 1;
		break;
	default:
		direction = 0;
		break;
	}

}