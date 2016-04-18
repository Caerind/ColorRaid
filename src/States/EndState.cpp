#include "EndState.hpp"

#include "../NodeEngine/Utils/Log.hpp"

EndState::EndState(ah::StateManager& manager)
: ah::State(manager)
{
    sf::Vector2u wSize = ah::Application::getWindow().getSize();
    sf::Vector2f scale = sf::Vector2f(wSize.x/800.f,wSize.y/600.f);
    sf::Vector2f c = sf::Vector2f(ah::Application::getWindow().getSize().x * 0.5f, ah::Application::getWindow().getSize().y * 0.5f);

    mBackground.setScale(scale);
	mBackground.setTexture(ah::Application::getResources().getTexture("back"));

	mTut.setTexture(ah::Application::getResources().getTexture("tut"));
	mTut.setTextureRect(sf::IntRect(800,0,400,300));
	mTut.setOrigin(sf::Vector2f(200,150));
	mTut.setPosition(c);

    mText = sf::Text(ah::Application::getValues().getString("killed"),ah::Application::getResources().getFont("cool"),45);
    mText.setPosition(c - sf::Vector2f(mText.getGlobalBounds().width / 2,-20));

    NLog::onlineLog("Game Played ! Score : " + ah::Application::getValues().getString("killed"));
}

EndState::~EndState()
{
}

bool EndState::handleEvent(sf::Event const& event)
{
    if (event.type == sf::Event::KeyPressed
    || event.type == sf::Event::TouchBegan
    || event.type == sf::Event::MouseButtonPressed)
    {
        requestClear();
        requestPush("MenuState");
    }
    return true;
}

bool EndState::update(sf::Time dt)
{
    return true;
}

void EndState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();
    target.draw(mBackground,states);
    target.draw(mTut,states);
    target.draw(mText,states);
}

void EndState::onActivate()
{
}

void EndState::onDeactivate()
{
}
