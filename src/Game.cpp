#include "Game.hpp"
#include "NodeEngine/Application/Application.hpp"

Game* Game::mInstance = nullptr;

Game& Game::instance()
{
    if (mInstance == nullptr)
    {
        mInstance = new Game();
    }
    return *mInstance;
}

void Game::drawGui(sf::RenderWindow& window)
{
    instance().mSfgui.Display(window);
}

lp::KeyBinding& Game::getKeyBinding()
{
    return instance().mKeys;
}

Game::Game()
{
}

Game::~Game()
{
}
