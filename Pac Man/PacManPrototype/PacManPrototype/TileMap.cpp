#include "TileMap.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

//Image map, hold the starting x and y pos for the walls

TileMap::TileMap() {

	src.h = 0;
	src.w = 0;
	src.x = 0;
	src.y = 0;

	dest.h = 0;
	dest.w = 0;
	dest.x = 0;
	dest.y = 0;
	
	map[0][0] = {0};
	imageX[0] = {0};
	imageY[0] = {0};

	map_tiles = TextureController::LoadTexture("Images/Tile_Sheet.png");

	imageData();
	
}

TileMap::~TileMap(){}

void TileMap::loadMap(){}

void TileMap::drawMap(){}

void TileMap::imageData() {

	//Image x/y pos reading
	std::string line;

	std::ifstream input("Misc/ImageXY.txt");
	if (!input) {
		std::cout << "File could not be opened" << std::endl;
	}

	std::getline(input, line);

	std::istringstream ss(line);
	std::string part;

	int i = 0;

	while (ss >> part) {
		imageX[i] = std::stoi(part);
		i++;
	}

	i = 0;

	std::getline(input, line);

	std::istringstream ss(line);

	while (ss >> part) {
		imageY[i] = std::stoi(part);
		i++;
	}

}