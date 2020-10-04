#include "TextureManager.h"

SDL_Texture* TextureController::LoadTexture(const char* texture, SDL_Renderer * r) {

	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(r, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureController::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{

	SDL_RenderCopy(PacManGame::renderer, tex, &src, &dest);

}
