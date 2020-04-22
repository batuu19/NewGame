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
}

void Game::ComposeFrame()
{
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
