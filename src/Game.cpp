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

std::string Game::getTitle()
{
    return "Color Raid";
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
    setPixelValue(instance().mPixelValue);
}

float Game::getPixelValue()
{
    return instance().mPixelValue;
}

void Game::setPixelValue(float v)
{
    instance().mPixelValue = v;
    ah::Application::getResources().getShader("pixelate").setParameter("pixel_threshold",v);
}

Game::Game()
{
    mPixelValue = 0.0001f;
}

Game::~Game()
{
}

bool Game::load()
{
    ah::Application::getWindow().load(Game::getConfigFile());
    ah::Application::getAudio().load(Game::getConfigFile());
    instance().mKeys.load(Game::getConfigFile());
    return false;
}

void Game::save()
{
    ah::Application::getWindow().save(Game::getConfigFile());
    ah::Application::getAudio().save(Game::getConfigFile());
    instance().mKeys.save(Game::getConfigFile());
}
