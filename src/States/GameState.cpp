#include "GameState.hpp"
#include <iostream>

GameState::GameState(ah::StateManager& manager)
: ah::State(manager)
{
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

    return true;
}

bool GameState::update(sf::Time dt)
{
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
