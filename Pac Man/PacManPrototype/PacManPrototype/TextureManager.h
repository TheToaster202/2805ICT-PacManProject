#pragma once

#include "PacManGame.h"

/// A functor class that will manage the import of textures from file, and returns the created pointer to the game class

class TextureController {
public:

	//! Loads the given file name and returns the SDL2 usuable texture
	static SDL_Texture* LoadTexture(const char* fileName);
	//! Draws the texture to the screen with the given SDL2 texture and rectangles
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};
