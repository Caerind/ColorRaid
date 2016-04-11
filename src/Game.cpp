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

void Game::drawGui(sf::RenderWindow& window)
{
    instance().mSfgui.Display(window);
}

void Game::setActionKey(std::string const& id, sf::Keyboard::Key key)
{
    instance().mKeys[id].first = key;
    (*instance().mActionMap)[id] = thor::Action(instance().mKeys[id].first,(instance().mKeys[id].second) ? thor::Action::Hold : thor::Action::PressOnce);
}

sf::Keyboard::Key Game::getActionKey(std::string const& id)
{
    return instance().mKeys[id].first;
}

Game::ActionMapPtr Game::getActionMap()
{
    return instance().mActionMap;
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
    mActionMap = std::make_shared<thor::ActionMap<std::string>>();

    if (!load())
    {
        mKeys["1"].first = sf::Keyboard::Num1;
        mKeys["2"].first = sf::Keyboard::Num2;
    }

    for (auto itr = mKeys.begin(); itr != mKeys.end(); itr++)
    {
        (*mActionMap)[itr->first] = thor::Action(itr->second.first,(itr->second.second) ? thor::Action::Hold : thor::Action::PressOnce);
    }

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
