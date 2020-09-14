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

	mapY = 2;
	mapX = 3;

	dRect.x = mapX * 24 - 13;
	dRect.y = (mapY * 24 - 13) + 80;

	currentTile = 0;
	nextTile = 0;

}

Ghosts::~Ghosts(){}

void Ghosts::renderGhost() {
	SDL_RenderCopy(PacManGame::renderer, gTexture, &sRect, &dRect);
}