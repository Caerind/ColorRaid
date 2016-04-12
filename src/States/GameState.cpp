#include "GameState.hpp"
#include "../NodeEngine/Core/World.hpp"
#include "../ParticleTestor.hpp"
#include <iostream>

GameState::GameState(ah::StateManager& manager)
: ah::State(manager)
{
    NParticleSystem& pSys = NWorld::addParticleSystem("test1");
    pSys.setTexture("particle");
}

GameState::~GameState()
{
}

bool GameState::handleEvent(sf::Event const& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        requestClear();
        requestPush("MenuState");
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        ParticleTestor::Ptr p = NWorld::createActor<ParticleTestor>();
        p->setPosition(NWorld::getPointerPositionView());
    }

    return true;
}

bool GameState::update(sf::Time dt)
{
    NWorld::getWindow().setDebugInfo("Actors",std::to_string(NWorld::getActorCount()));
    NWorld::getWindow().setDebugInfo("Tickables",std::to_string(NWorld::getTickableCount()));
    NWorld::getWindow().setDebugInfo("Renderables",std::to_string(NWorld::getRenderableCount()));
    NWorld::getWindow().setDebugInfo("ParticlesSystems",std::to_string(NWorld::getParticleSystemCount()));
    return true;
}

void GameState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();
}

void GameState::onActivate()
{
}

void GameState::onDeactivate()
{
}
