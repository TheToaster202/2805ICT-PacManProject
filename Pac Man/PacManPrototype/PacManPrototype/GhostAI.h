#pragma once

#include "Ghost.h"
#include "TileMap.h"

/// <summary>
/// A class that will decide the next move for a ghost, the class will accept the ghosts current postion and the target tile and will output the tile the ghost will move to.
/// </summary>

class AI{
public:

	AI(int const & type);
	~AI();

	std::pair<int, int> AIPackage(TileMap const * map, int const& ghostType);	//! Method that will decide which AI package to run and will return the next postion

private:

	void Blinky(TileMap const* map);	//! Blinky's movement algorithm
	void Pinky(TileMap const* map);		//! Pinky's movement algorithm
	void Inky(TileMap const* map);		//! Inky's movement algorithm
	void Clyde(TileMap const* map);		//! Clydes's movement algorithm

	int cX, cY;	//Current X and Y
	int tX, tY;	//Target X and Y, IE: player postion
	std::pair<int, int> target;
	int gType;
};