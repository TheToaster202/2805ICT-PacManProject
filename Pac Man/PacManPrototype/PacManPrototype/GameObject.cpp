#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturePath) {

	objectTexture = TextureController::LoadTexture(texturePath);

	srcRect.h = 0;
	srcRect.w = 0;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 0;
	destRect.w = 0;
	destRect.x = 0;
	destRect.y = 0;

}

GameObject::~GameObject(){}

void GameObject::updateObject() {

	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.x = 16;
	srcRect.y = 0;

	destRect.h = 32;
	destRect.w = 32;
	destRect.x = 0;
	destRect.y = 0;

}

void GameObject::renderObject() {
	SDL_RenderCopy(PacManGame::renderer, objectTexture, &srcRect, &destRect);
}