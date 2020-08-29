#include "GameTimer.h"

GameTimer::GameTimer() {
	mPaused = false;
	mStarted = false;

	mStartTicks = 0;
	mPausedTicks = 0;
}

void GameTimer::start() {
	mStarted = true;
	mPaused = false;

	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void GameTimer::stop() {
	mStarted = false;
	mPaused = false;

	mStartTicks = 0;
	mPausedTicks = 0;
}

void GameTimer::pause() {
	if (mStarted && !mPaused) {
		mPaused = true;

		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void GameTimer::unpause() {
	if (mStarted && mPaused) {
		mPaused = false;

		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}

Uint32 GameTimer::getTicks() {
	Uint32 time = 0;

	if (mStarted) {
		if (mPaused) {
			time = mPausedTicks;
		}else {
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}

bool GameTimer::isStarted() {
	return mStarted;
}

bool GameTimer::isPaused() {
	return mPaused && mStarted;
}