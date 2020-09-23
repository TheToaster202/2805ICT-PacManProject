#include "GhostAI.h"

AI::~AI(){
	delete[] sptSet;
	delete[] distances;
}

std::pair<int, int> AI::AIPackage(TileMap* map, int const & currentX, int const & currentY, int const & targetX, int const & targetY, int const & ghostType, int const & playerDirection) {

	distances = new int[map->getRows()];
	sptSet = new bool[map->getRows()];

	memset(distances, 0, map->getRows());
	memset(sptSet, 0, map->getRows());

	cX = currentX;
	cY = currentY;

	//Gives the option to change AI package mid game
	if (ghostType != 0) {
		gType = ghostType;
	}

	// Determines which ghost package will be used Blinky = 1, Pinky = 2, Inky = 3, Clyde = 4 and all other numbers
	switch (gType) {
	case 1:
		Blinky(map, targetX, targetY, playerDirection);
		break;
	case 2:
		Pinky(map, targetX, targetY, playerDirection);
		break;
	case 3:
		Inky(map, targetX, targetY, playerDirection);
		break;
	case 4:
		Clyde(map, targetX, targetY, playerDirection);
		break;
	default:
		std::cout << "Incorrect Ghost Types, using Clyde Instead..." << std::endl;
		Clyde(map, targetX, targetY, playerDirection);
		break;
	}

	return target;
}

//! Blinky will always target the player, and will find the shortest path to the players current tile
void AI::Blinky(TileMap * map, int const& targetX, int const& targetY, int const & pDir) {

	tX = targetX;
	tY = targetY;

}	

//! Pinky will target the tiles in front of the player in an attempt to ambush them.
void AI::Pinky(TileMap * map, int const& targetX, int const& targetY, int const & pDir) {

}		

//! Inky will look to cut off the players escape by targeting the tile behind the player
void AI::Inky(TileMap * map, int const& targetX, int const& targetY, int const & pDir) {

}		

//! Clyde will chase the player, until he gets to close and goes back to his corner of the map...
void AI::Clyde(TileMap * map, int const& targetX, int const& targetY, int const & pDir) {

}

void AI::shortestPath() {

}

int AI::minDist() {

}