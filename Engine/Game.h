#pragma once

#include "Graphics.h"
#include "MainWindow.h"
#include "FrameTimer.h"

#include "GameObject.h"
#include "StaticObject.h"
#include "ContainerUtils.h"

class Game {
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	void Go();
public:
	void addGameObject(GameObject&);
	void removeGameObject(GameObject&);
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
	//Object management
	std::vector<GameObject*> gameObjects;
	std::vector<StaticObject*> staticObjects;
	///Object management
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