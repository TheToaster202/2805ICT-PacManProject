#pragma once

#include "PacManGame.h"

/// <summary>
/// Class that will contain the necessary information on the ghosts. AI Packages, movement, texture creation, rendering
/// </summary>

class Ghosts {
public:

	Ghosts(int const& type, const char * texturePath);

	~Ghosts();

	void renderGhost();
	

private:

	int gType;	//Ghost type
	int mapX, mapY;	//Map Co-ords
	int currentTile, nextTile;

	SDL_Texture* gTexture;
	SDL_Rect sRect, dRect;
};