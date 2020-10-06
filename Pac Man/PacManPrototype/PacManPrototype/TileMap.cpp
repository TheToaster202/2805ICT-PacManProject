#include "TileMap.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

//Image map, hold the starting x and y pos for the walls


//! Delagates to the image and map data methods to collect data about the levels, then delegates to the draw map method to create the map
TileMap::TileMap(int const & level) {

	rows = 0;
	cols = 0;
	
	src.h = 8;
	src.w = 8;
	src.x = 0;
	src.y = 0;

	dest.h = 24;
	dest.w = 24;
	dest.x = 0;
	dest.y = 0;
	
	map = nullptr;
	imageX[0] = {0};
	imageY[0] = {0};

	lvlID = level;

	pelletCount = 0;

	offset = 80;

	std::cout << rows << " " << cols << std::endl;

	imageData();

	//Currently going to default to the test map, will need to implement some way of changing level and level type (Reg, hex and graph)
	mapData(lvlID);
	
}

TileMap::~TileMap(){

	for (int i = 0; i < cols; i++) {
		delete[] map[rows];
	}
	delete[] map;

}

//! Loads the texture from a file
void TileMap::loadMap(){

	map_tiles = TextureController::LoadTexture("Images/Tile_Sheet.png", PacManGame::renderer);

}

//! Using the image data and the map layout, draws the map to the screen
void TileMap::drawMap(){

	//Draws the tiles onto the screen

	int tileId = 0;
	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			
			tileId = map[j][i];

			src.x = imageX[tileId];
			src.y = imageY[tileId];

			dest.x = (i*24);
			dest.y = (j*24) + offset;

			TextureController::Draw(map_tiles, src, dest);
		}

	}

}


//! Opens the stored imageXY text file, which contains the pixle positons of the different tiles within the texture file
void TileMap::imageData() {

	//Reads from a file, how to seperate the different parts of the image into useable tiles
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

	ss.clear();
	ss.str(line);

	while (ss >> part) {
		imageY[i] = std::stoi(part);
		i++;
	}

	input.close();

	for (int i = 0; i < 39; i++) {
		std::cout << imageX[i] << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 39; i++) {
		std::cout << imageY[i] << " ";
	}

	std::cout << std::endl;
}

//! Opens the stores map(lvl num) text file and allocates the memory required to store the maps information in a 2d array
void TileMap::mapData(int lvl) {

	//Reads the layout of the level from the corresponding file

	if (lvl > 3) {
		lvl = 1;
	}
	
	std::string fileName = "map";
	fileName += std::to_string(lvl) + ".txt";

	std::string filePath = "Misc/" + fileName;

	std::cout << "Looking for: " << filePath << std::endl;

	std::ifstream input(filePath);
	if (!input) {
		input.open("Misc/mapD.txt");
		if (!input) {
			std::cout << "Total Error of map loading" << std::endl;
		}
	}

	//Reads first line (Level Dimensions)

	std::string line;
	std::getline(input, line);
	std::istringstream ss(line);
	std::string part;
	
	ss >> cols;
	ss >> rows;

	//Allocate Memory

	map = new int* [rows];
	for (int i = 0; i < rows; i++) {
		map[i] = new int[cols];
	}

	//Initialises the 2d array

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			map[i][j] = 0;
		}
	}

	//Reads the rest of the file
	int i = 0;
	while (getline(input, line)) {
		ss.clear();
		ss.str(line);
		std::string part;

		if (line == "END") {
			break;
		}
		
		int j = 0;
		while (ss >> part) {

			//Checks if the any end conditions are met
			if (part == "\n" || j >= cols) {
				break;
			}

			int tempHold = stoi(part);

			map[i][j] = tempHold;

			j++;
		}

		i++;
	}
	input.close();

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			int tileId = map[j][i];

			if (tileId == 15 || tileId == 16) {
				pelletCount++;
			}
		}
	}

}

int TileMap::getMapVal(int x, int y) { return map[y][x]; }

void TileMap::changeTile(int const& x, int const& y) {
	
	if (map[y][x] == 15 || map[y][x] == 16) {
		map[y][x] = 7;
		pelletCount--;
	}

}

int TileMap::getTilePos(int const & x, int const & y) {

}

int TileMap::getRows() {
	return rows;
}

int TileMap::getCols() {
	return cols;
}

int TileMap::getOffset() {
	return offset;
}

int TileMap::getPellets() {
	return pelletCount;
}