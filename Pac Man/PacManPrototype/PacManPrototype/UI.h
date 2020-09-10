#pragma once
#include "PacManGame.h"

/// <summary>
/// Class that creates a simple Box that will house the Timer and Game Score
/// </summary>

class GameUI {
public:

	GameUI();
	void renderUI();
	void initUI(int const& offset, int const& sW);

private:

	SDL_Rect outer;
	SDL_Rect inner;
};