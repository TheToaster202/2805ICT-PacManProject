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

	currentTile = 0;
	nextTile = 0;

	direction = 0;

	pacX = 0;
	pacY = 0;

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

	gAI.AIPackage(map, mapX, mapY, pacX, pacY, gType, pacMan->getDirection());

	moveGhost();

}

void Ghosts::moveGhost() {
	
	dRect.x += xVel;
	dRect.y += yVel;

}

int Ghosts::getX() { return mapX; }

int Ghosts::getY() { return mapY; }

int Ghosts::getPacX() { return pacX; }

int Ghosts::getPacY() { return pacY; }

int Ghosts::getType() { return gType; }