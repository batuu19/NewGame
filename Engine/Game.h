#pragma once

#include "Graphics.h"
#include "MainWindow.h"
#include "FrameTimer.h"


class Game {
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	void handleInput(Keyboard::Event);
	void handleInput(Mouse::Event);
	void processAction(std::string action);
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	FrameTimer ft;

};