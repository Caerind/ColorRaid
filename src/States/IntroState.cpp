#include "IntroState.hpp"

IntroState::IntroState(ah::StateManager& manager)
: ah::State(manager)
{
    mDuration = sf::seconds(2.1f);

    sf::Vector2u wSize = ah::Application::getWindow().getSize();
    sf::Vector2f scale = sf::Vector2f(wSize.x/800.f,wSize.y/600.f);

    mBackground.setScale(scale);
    mBackground.setTexture(ah::Application::getResources().getTexture("splash"));

    mAtmogText.setFont(ah::Application::getResources().getFont("atmog"));
    mAtmogText.setString(L"Atmög");
    mAtmogText.setCharacterSize(static_cast<unsigned int>(200 * scale.y));
    mAtmogText.setPosition(wSize.x * 0.5f - mAtmogText.getGlobalBounds().width * 0.5f,wSize.y * 0.5f - mAtmogText.getGlobalBounds().height * 0.5f);
    mAtmogText.setColor(sf::Color::White);

    mAtmogShadow.setFont(ah::Application::getResources().getFont("atmog"));
    mAtmogShadow.setString(mAtmogText.getString());
    mAtmogShadow.setCharacterSize(mAtmogText.getCharacterSize());
    mAtmogShadow.setPosition(mAtmogText.getPosition() + sf::Vector2f(2.f * scale.x, 2.f * scale.y));
    mAtmogShadow.setColor(sf::Color::Black);
}

IntroState::~IntroState()
{
}

bool IntroState::handleEvent(sf::Event const& event)
{
    return true;
}

bool IntroState::update(sf::Time dt)
{
    if (mClock.getElapsedTime() < mDuration / 3.f)
    {
        mBackground.setTextureRect(sf::IntRect(0,0,800,600));
    }
    if (mClock.getElapsedTime() >= mDuration / 3.f && mClock.getElapsedTime() < 2.f * mDuration / 3.f)
    {
        mBackground.setTextureRect(sf::IntRect(800,0,800,600));
    }
    if (mClock.getElapsedTime() >= 2.f * mDuration / 3.f && mClock.getElapsedTime() < mDuration)
    {
        mBackground.setTextureRect(sf::IntRect(1600,0,800,600));
    }
    if (mClock.getElapsedTime() >= mDuration)
    {
        requestClear();
        requestPush("MenuState");
    }
    return true;
}

void IntroState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();
    target.draw(mBackground,states);
    if (mClock.getElapsedTime().asSeconds() >= mDuration.asSeconds() * 2 / 3)
    {
        target.draw(mAtmogShadow,states);
        target.draw(mAtmogText,states);
    }
}

void IntroState::onActivate()
{
    ah::Application::getWindow().hideMouseCursor();
}

void IntroState::onDeactivate()
{
    ah::Application::getWindow().useCustomMouseCursor(&ah::Application::getResources().getTexture("cursor"));
}
