#pragma once
#include "PacManGame.h"

class TileMap {
public:

	TileMap();
	~TileMap();

	void loadMap();
	void drawMap();

	void imageData();
	void mapData(int lvl);

private:

	SDL_Rect src, dest;
	SDL_Texture* map_tiles;

	int rows;
	int cols;

	int **map;
	int imageX[39];
	int imageY[39];
	
	int lvlID;
};