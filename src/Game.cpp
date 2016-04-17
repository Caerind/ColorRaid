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

std::string Game::getConfigFile()
{
    return "assets/Data/settings.xml";
}

void Game::resetKilled()
{
    instance().mKilled = 0;
}

void Game::addKilled()
{
    instance().mKilled++;
}

int Game::getKilled()
{
    return instance().mKilled;
}

int Game::getGoodDamage()
{
    return 100;
}

int Game::getBadDamage()
{
    return 30;
}

void Game::drawGui(sf::RenderWindow& window)
{
    instance().mSfgui.Display(window);
}

lp::KeyBinding& Game::getKeyBinding()
{
    return instance().mKeys;
}

sf::Time Game::getGameDuration()
{
    return instance().mGameDuration.getElapsedTime();
}

void Game::resetGameDuration()
{
    instance().mGameDuration.restart();
}

Game::Game()
{
}

Game::~Game()
{
}

bool Game::load(std::string const& filename)
{
    return false;
}

void Game::save(std::string const& filename)
{
}
