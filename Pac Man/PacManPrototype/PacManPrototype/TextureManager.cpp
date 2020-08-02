
//A class that will manage the import of textures from file, and returns the created pointer to the game class

#include "TextureManager.h"

SDL_Texture* TextureController::LoadTexture(const char* texture) {

	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(PacManGame::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}
