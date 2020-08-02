#pragma once

#include "SDL_image.h"

//A simple container class, which goal is to compact the data of the game class
class RectangleController {
public:
	RectangleController();
	~RectangleController();

	void playerInit();
	void ghostInit();

	SDL_Rect source, dest;
};