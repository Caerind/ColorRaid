#include "SettingsState.hpp"

SettingsState::SettingsState(ah::StateManager& manager)
: ah::State(manager)
{
    sf::Vector2u wSize = ah::Application::getWindow().getSize();
    sf::Vector2f scale = sf::Vector2f(wSize.x/800.f,wSize.y/600.f);

	mBackground.setTexture(ah::Application::getResources().getTexture("back"));
	mBackground.setScale(scale);
}

SettingsState::~SettingsState()
{
}

bool SettingsState::handleEvent(sf::Event const& event)
{
    return true;
}

bool SettingsState::update(sf::Time dt)
{
    return true;
}

void SettingsState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();
    target.draw(mBackground,states);
}

void SettingsState::onActivate()
{
}

void SettingsState::onDeactivate()
{
}
