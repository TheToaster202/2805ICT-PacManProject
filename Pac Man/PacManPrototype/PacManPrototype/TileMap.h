#pragma once
#include "PacManGame.h"

class TileMap {
public:

	TileMap();
	~TileMap();

	void loadMap();
	void drawMap();

	void imageData();

private:

	SDL_Rect src, dest;
	SDL_Texture* map_tiles;

	int map[25][30];
	int imageX[39];
	int imageY[39];
};