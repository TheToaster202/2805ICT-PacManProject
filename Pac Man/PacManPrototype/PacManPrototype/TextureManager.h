#pragma once

//A class that will manage the import of textures from file, and returns the created pointer to the game class

#include "PacManGame.h"

class TextureController {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
};
