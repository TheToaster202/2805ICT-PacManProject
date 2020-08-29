#pragma once
#include "PacManGame.h"

/// <summary>
/// Class that keeps track of game time, used for frame indenpendent movement of gmae objects
/// </summary>


class GameTimer {
private:

	Uint32 mStartTicks;
	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;

public:
	//! Default Construction
	GameTimer();

	//! Clock Actions
	void start();
	void stop();
	void pause();
	void unpause();

	//! Gets the current timer value
	Uint32 getTicks();

	//! checks the status of the timer
	bool isStarted();
	bool isPaused();
};