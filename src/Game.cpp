#include "Game.hpp"

Game* Game::mInstance = nullptr;

Game& Game::instance()
{
    if (mInstance == nullptr)
    {
        mInstance = new Game();
    }
    return *mInstance;
}

std::string Game::getTitle()
{
    return "Test";
}

Game::Game()
{
}

Game::~Game()
{
    save();
}

bool Game::load()
{
    return false;
}

void Game::save()
{
}
