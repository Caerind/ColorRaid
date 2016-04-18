#include "BeginState.hpp"

BeginState::BeginState(ah::StateManager& manager)
: ah::State(manager)
{
    sf::Vector2u wSize = ah::Application::getWindow().getSize();
    sf::Vector2f scale = sf::Vector2f(wSize.x/800.f,wSize.y/600.f);
    sf::Vector2f c = sf::Vector2f(ah::Application::getWindow().getSize().x * 0.5f, ah::Application::getWindow().getSize().y * 0.5f);
    mBackground.setScale(scale);
	mBackground.setTexture(ah::Application::getResources().getTexture("back"));

	#ifdef N_DESKTOP_PLATFORM
	mTut.setTexture(ah::Application::getResources().getTexture("tut"));
	mTut.setTextureRect(sf::IntRect(400,0,400,300));
	mTut.setOrigin(sf::Vector2f(200,150));
	mTut.setPosition(c);

	std::string str = Game::getKeyBinding().getKeyString("up") + ", " + Game::getKeyBinding().getKeyString("left") + ", " + Game::getKeyBinding().getKeyString("down") + ", " + Game::getKeyBinding().getKeyString("right");
	mTexts.push_back(sf::Text(str,ah::Application::getResources().getFont("cool"),20));
	mTexts.back().setPosition(c - mTut.getOrigin() + sf::Vector2f(150,25));
	str = Game::getKeyBinding().getKeyString("action");
	mTexts.push_back(sf::Text(str,ah::Application::getResources().getFont("cool"),20));
	mTexts.back().setPosition(c - mTut.getOrigin() + sf::Vector2f(165,80));
	str = Game::getKeyBinding().getKeyString("1") + ", " + Game::getKeyBinding().getKeyString("2") + ", " + Game::getKeyBinding().getKeyString("3");
	mTexts.push_back(sf::Text(str,ah::Application::getResources().getFont("cool"),20));
	mTexts.back().setPosition(c - mTut.getOrigin() + sf::Vector2f(165,140));
	#else
	mTut.setTexture(ah::Application::getResources().getTexture("tut"));
	mTut.setTextureRect(sf::IntRect(0,0,400,300));
	mTut.setOrigin(sf::Vector2f(200,150));
	mTut.setPosition(ah::Application::getWindow().getSize().x * 0.5f, ah::Application::getWindow().getSize().y * 0.5f);
	#endif // N_DESKTOP_PLATFORM
}

BeginState::~BeginState()
{
}

bool BeginState::handleEvent(sf::Event const& event)
{
    if (event.type == sf::Event::KeyPressed
    || event.type == sf::Event::TouchBegan
    || event.type == sf::Event::MouseButtonPressed)
    {
        requestClear();
        requestPush("GameState");
    }
    return true;
}

bool BeginState::update(sf::Time dt)
{
    return true;
}

void BeginState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();
    target.draw(mBackground,states);
    target.draw(mTut,states);
    #ifdef N_DESKTOP_PLATFORM
    for (std::size_t i = 0; i < mTexts.size(); i++)
    {
        target.draw(mTexts[i],states);
    }
    #endif // N_DESKTOP_PLATFORM
}

void BeginState::onActivate()
{
}

void BeginState::onDeactivate()
{
}
