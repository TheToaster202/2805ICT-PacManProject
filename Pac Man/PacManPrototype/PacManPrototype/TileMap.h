#pragma once
#include "PacManGame.h"


/// A class that handles the loading and generation of the game level

class TileMap {
public:

	//! Default Constructor
	TileMap();
	//! Default Destructor
	~TileMap();

	//! N/A
	void loadMap();
	//! Draws the map to the screen based on the given tile preset and the map file
	void drawMap();

	//! Gets the tile set information from a given file
	void imageData();
	//! Gets the layout of the level from a map file
	void mapData(int lvl);

	//! Returns the value contained within the x and y values on the map
	int getMapVal(int x, int y);

	//! Changes the tile
	void changeTile(int const& x, int const& y);

	int getTilePos(int const & x, int const & y);

	int getRows();
	int getCols();

	int getOffset();

private:

	SDL_Rect src, dest;
	SDL_Texture* map_tiles;

	int rows;
	int cols;

	int **map;
	int imageX[44];
	int imageY[44];
	
	int lvlID;

	int offset;
};