#include "MenuState.hpp"

MenuState::MenuState(ah::StateManager& manager)
: ah::State(manager)
{
    sf::Vector2u wSize = ah::Application::getWindow().getSize();
    sf::Vector2f scale = sf::Vector2f(wSize.x/800.f,wSize.y/600.f);

	mBackground.setScale(scale);
	mBackground.setTexture(ah::Application::getResources().getTexture("back"));

	mTitleText.setFont(ah::Application::getResources().getFont("atmog"));
    mTitleText.setString(Game::getTitle());
    mTitleText.setCharacterSize(static_cast<unsigned int>(80 * scale.y));
    mTitleText.setPosition(wSize.x * 0.5f - mTitleText.getGlobalBounds().width * 0.5f, 25.f * scale.y);
    mTitleText.setColor(sf::Color::White);

    mTitleShadow.setFont(ah::Application::getResources().getFont("atmog"));
    mTitleShadow.setString(mTitleText.getString());
    mTitleShadow.setCharacterSize(mTitleText.getCharacterSize());
    mTitleShadow.setPosition(mTitleText.getPosition() + sf::Vector2f(2.f * scale.x, 2.f * scale.y));
    mTitleShadow.setColor(sf::Color::Black);
}

MenuState::~MenuState()
{
}

bool MenuState::handleEvent(sf::Event const& event)
{
    return true;
}

bool MenuState::update(sf::Time dt)
{
    return true;
}

void MenuState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();
    target.draw(mBackground,states);
    target.draw(mTitleShadow,states);
    target.draw(mTitleText,states);
}

void MenuState::onActivate()
{
}

void MenuState::onDeactivate()
{
}
