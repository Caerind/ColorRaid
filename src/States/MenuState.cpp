#include "MenuState.hpp"

MenuState::MenuState(ah::StateManager& manager)
: ah::State(manager)
{
    sf::Vector2u wSize = ah::Application::getWindow().getSize();
    sf::Vector2f scale = sf::Vector2f(wSize.x/800.f,wSize.y/600.f);

    sf::Vector2f bSize = sf::Vector2f(400 * scale.x, 75 * scale.y);

    #ifdef N_DESKTOP_PLATFORM
    auto buttonGame = sfg::Button::Create("Play");
	buttonGame->SetClass("menu_button");
	buttonGame->SetAllocation(sf::FloatRect(wSize.x / 2 - bSize.x * 0.5f, 200.f * scale.y, bSize.x, bSize.y));
	buttonGame->GetSignal(sfg::Widget::OnLeftClick).Connect([&]()
    {
        requestClear();
        requestPush("BeginState");
    });

	auto buttonSettings = sfg::Button::Create("Settings");
	buttonSettings->SetClass("menu_button");
	buttonSettings->SetAllocation(sf::FloatRect(wSize.x / 2 - bSize.x * 0.5f, 325.f * scale.y, bSize.x, bSize.y));
	buttonSettings->GetSignal(sfg::Widget::OnLeftClick).Connect([&]()
    {
        requestClear();
        requestPush("SettingsState");
    });

	auto buttonQuit = sfg::Button::Create("Quit");
	buttonQuit->SetClass("menu_button");
	buttonQuit->SetAllocation(sf::FloatRect(wSize.x / 2 - bSize.x * 0.5f, 450.f * scale.y, bSize.x, bSize.y));
	buttonQuit->GetSignal(sfg::Widget::OnLeftClick).Connect([&]()
    {
        ah::Application::close();
    });

    mDesktop.SetProperty("Button.menu_button","FontSize",std::to_string(static_cast<unsigned int>(25 * scale.y)));

	mDesktop.Add(buttonGame);
    mDesktop.Add(buttonSettings);
	mDesktop.Add(buttonQuit);
	#else
    auto buttonGame = sfg::Button::Create("Play");
	buttonGame->SetClass("menu_button");
	buttonGame->SetAllocation(sf::FloatRect(wSize.x / 2 - bSize.x * 0.5f, 250.f * scale.y, bSize.x, bSize.y));
	buttonGame->GetSignal(sfg::Widget::OnLeftClick).Connect([&]()
    {
        requestClear();
        requestPush("BeginState");
    });

	auto buttonQuit = sfg::Button::Create("Quit");
	buttonQuit->SetClass("menu_button");
	buttonQuit->SetAllocation(sf::FloatRect(wSize.x / 2 - bSize.x * 0.5f, 350.f * scale.y, bSize.x, bSize.y));
	buttonQuit->GetSignal(sfg::Widget::OnLeftClick).Connect([&]()
    {
        ah::Application::close();
    });

    mDesktop.SetProperty("Button.menu_button","FontSize",std::to_string(static_cast<unsigned int>(25 * scale.y)));

	mDesktop.Add(buttonGame);
	mDesktop.Add(buttonQuit);
    #endif // N_DESKTOP_PLATFORM

	mBackground.setScale(scale);
	mBackground.setTexture(ah::Application::getResources().getTexture("back"));

	mTitleText.setFont(ah::Application::getResources().getFont("atmog"));
    mTitleText.setString(Game::getTitle());
    mTitleText.setCharacterSize(static_cast<unsigned int>(80 * scale.y));
    #ifdef N_DESKTOP_PLATFORM
    mTitleText.setPosition(wSize.x * 0.5f - mTitleText.getGlobalBounds().width * 0.5f, 50.f * scale.y);
    #else
    mTitleText.setPosition(wSize.x * 0.5f - mTitleText.getGlobalBounds().width * 0.5f, 100.f * scale.y);
    #endif // N_DESKTOP_PLATFORM
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
    mDesktop.HandleEvent(event);
    return true;
}

bool MenuState::update(sf::Time dt)
{
    mDesktop.Update(dt.asSeconds());
    return true;
}

void MenuState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();
    target.draw(mBackground,states);
    Game::drawGui(ah::Application::getWindow());
    target.draw(mTitleShadow,states);
    target.draw(mTitleText,states);
}

void MenuState::onActivate()
{
}

void MenuState::onDeactivate()
{
}
