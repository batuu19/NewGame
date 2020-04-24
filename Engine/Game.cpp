#include "pch.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::addGameObject(GameObject& go)
{
	gameObjects.push_back(&go);
}

void Game::removeGameObject(GameObject& go)
{
	//remove_element_from_end(gameObjects, &go);
}

void Game::UpdateModel()
{
	while (!wnd.kbd.KeyIsEmpty())
	{
		const Keyboard::Event k = wnd.kbd.ReadKey();
		handleInput(k);
	}
	while (!wnd.mouse.IsEmpty())
	{
		const Mouse::Event m = wnd.mouse.Read();
		handleInput(m);
	}

	const float dt = ft.mark();

	for (auto go : gameObjects) {
		go->update(dt);
	}
}

void Game::ComposeFrame()
{
	for (auto go : gameObjects) {
		go->draw(gfx);
	}
	for (auto so : staticObjects) {
		so->draw(gfx);
	}
}


void Game::handleInput(Keyboard::Event event)
{

}

void Game::handleInput(Mouse::Event event)
{
}

void Game::processAction(std::string action)
{
}
