#include "TileMap.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

//Image map, hold the starting x and y pos for the walls

TileMap::TileMap() {

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

	lvlID = 0;

	map_tiles = TextureController::LoadTexture("Images/Tile_Sheet.png");

	imageData();

	//Currently going to default to the test map, will need to implement some way of changing level and level type (Reg, hex and graph)
	mapData(lvlID);

	std::cout << rows << " " << cols << std::endl;
	
}

TileMap::~TileMap(){

	for (int i = 0; i < cols; i++) {
		delete[] map[rows];
	}
	delete[] map;

}

//This might not be needed
void TileMap::loadMap(){

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {

		}
	}

}

void TileMap::drawMap(){

	//Draws the tiles onto the screen

	int tileId = 0;
	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			
			tileId = map[j][i];

			src.x = imageX[tileId];
			src.y = imageY[tileId];

			dest.x = i*24;
			dest.y = j*24;

			TextureController::Draw(map_tiles, src, dest);
		}

	}

}

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

void TileMap::mapData(int lvl) {

	//Reads the layout of the level from the corresponding file

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
	
}

//Might be needed to get the map information to the controller
int TileMap::getMapVal(int x, int y) { return map[y][x]; }