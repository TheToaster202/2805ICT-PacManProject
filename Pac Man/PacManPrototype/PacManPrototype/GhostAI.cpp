#include "GhostAI.h"

AI::AI(int const & type): gType(type) {
	cX = 0;
	cY = 0;
	tX = 0;
	tY = 0;

	target.first = 0;
	target.second = 0;
}

AI::~AI(){}

std::pair<int, int> AI::AIPackage(TileMap const* map, int const& ghostType = 0) {

	//Gives the option to change AI package mid game
	if (ghostType != 0) {
		gType = ghostType;
	}

	// Determines which ghost package will be used Blinky = 1, Pinky = 2, Inky = 3, Clyde = 4 and all other numbers
	switch (gType) {
	case 1:
		Blinky(map);
		break;
	case 2:
		Pinky(map);
		break;
	case 3:
		Inky(map);
		break;
	case 4:
		Clyde(map);
		break;
	default:
		std::cout << "Incorrect Ghost Types, using Clyde Instead..." << std::endl;
		Clyde(map);
		break;
	}
}

void AI::Blinky(TileMap const* map) {

}	

void AI::Pinky(TileMap const* map) {

}		

void AI::Inky(TileMap const* map) {

}		

void AI::Clyde(TileMap const* map) {

}