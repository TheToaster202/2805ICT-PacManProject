#include "UI.h"

GameUI::GameUI() {
	
	outer.x = 0;
	outer.y = 0;
	outer.w = 0;
	outer.h = 0;

	inner.x = 0;
	inner.y = 0;
	inner.w = 0;
	inner.h = 0;

}

//! Sets the size of the rectangles
void GameUI::initUI(int const& offset, int const& sW) {
	outer.x = 0;
	outer.y = 0;
	outer.w = sW;
	outer.h = offset;

	inner.x = 5;
	inner.y = 5;
	inner.w = sW - 10;
	inner.h = offset - 10;
}

//! Renders the rectangles to the screen
void GameUI::renderUI() {
	SDL_SetRenderDrawColor(PacManGame::renderer, 87, 182, 255, 255);

	SDL_RenderFillRect(PacManGame::renderer, &outer);

	SDL_SetRenderDrawColor(PacManGame::renderer, 0, 0, 0, 255);

	SDL_RenderFillRect(PacManGame::renderer, &inner);

	SDL_RenderPresent(PacManGame::renderer);

}