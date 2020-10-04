#include "Button.h"

Button::Button() {
	sRect.x = 0;
	sRect.y = 0;
	sRect.w = 0;
	sRect.h = 0;

	dRect.x = 0;
	dRect.y = 0;
	dRect.w = 0;
	dRect.h = 0;

	texture = nullptr;
}

Button::~Button() {
	SDL_DestroyTexture(texture);
}

void Button::initBtn(int const& xPos, int const& yPos, int const & width, int const & height, const char * texturePath, SDL_Renderer * r) {
	
	texture = TextureController::LoadTexture(texturePath, r);
	
	sRect.x = 0;
	sRect.y = 0;
	sRect.w = width;
	sRect.h = height;

	dRect.h = height*4;
	dRect.w = width*4;

	dRect.x = xPos;
	dRect.y = yPos;

	std::cout << texturePath << std::endl;

	if (texture == nullptr) {
		std::cout << "Failed to load texture" << std::endl;
		exit(1);
	}

}

void Button::renderBtn(SDL_Renderer * r) {
	SDL_RenderCopy(r, texture, &sRect, &dRect);
}

bool Button::buttonPress(SDL_Event * evnt) {

	bool isPressed = false;
	
	if (evnt->type == SDL_MOUSEMOTION || evnt->type == SDL_MOUSEBUTTONDOWN) {
		bool inside = true;
		
		int mX, mY;
		SDL_GetMouseState(&mX, &mY);

		if (mX < dRect.x) {
			inside = false;
		}
		else if (mX > dRect.x + dRect.w) {
			inside = false;
		}
		else if (mY < dRect.y) {
			inside = false;
		}
		else if (mY > dRect.y + dRect.h) {
			inside = false;
		}

		if (inside) {
			
			if (evnt->type == SDL_MOUSEBUTTONDOWN) {
				pressTimer.start();
				isPressed = true;
			}
		}
	}

	animateBtn();
	return isPressed;
}

void Button::animateBtn() {
	
	int countTimer = pressTimer.getTicks() / 100;

	if (countTimer >= 5) {
		pressTimer.stop();
		sRect.y = 0;
	}
	else if (countTimer > 0) {
		sRect.y = sRect.h;
	}
	
}