#include "RectangleManager.h"

//A simple container class which helps to compact the data of the game class
RectangleController::RectangleController() {
	source.h = 0;
	source.w = 0;
	source.x = 0;
	source.y = 0;

	dest.h = 0;
	dest.w = 0;
	dest.x = 0;
	dest.y = 0;
}

RectangleController::~RectangleController(){}


//Initialises the players texture, to clean up the presentation of the game init method
void RectangleController::playerInit() {

	source.h = 16;
	source.w = 16;
	source.x = 16;
	source.y = 0;

	dest.h = 32;
	dest.w = 32;
	dest.x = 0;
	dest.y = 0;
}

//Initialises the ghosts texture, to clean up the presentation of the game init method
void RectangleController::ghostInit() {

	source.h = 16;
	source.w = 16;
	source.x = 0;
	source.y = 0;

	dest.h = 32;
	dest.w = 32;
	dest.x = 0;
	dest.y = 0;

}