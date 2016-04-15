#include "GameState.hpp"
#include "../NodeEngine/Core/World.hpp"
#include <iostream>

#include "../Pixelate.hpp"

#include <Thor/Graphics.hpp>
#include <Thor/Animations.hpp>

GameState::GameState(ah::StateManager& manager)
: ah::State(manager)
{
    NWorld::clear();

    NWorld::setEffect(new Pixelate());

    NParticleSystem::Ptr pSys1 = NWorld::getParticleSystem("test1");
    pSys1->setTexture("particle");
    pSys1->setPosition(0,0,0);

    NParticleSystem::Ptr pSys2 = NWorld::getParticleSystem("test2");
    pSys2->setTexture("particle");
    pSys2->setPosition(0,0,-20);
    pSys2->addAffector(thor::ForceAffector(sf::Vector2f(0.f,100.f)));
	pSys2->addAffector(thor::TorqueAffector(100.f));

	// Build color gradient (green -> teal -> blue)
	thor::ColorGradient gradient;
	gradient[0.f] = sf::Color(0, 150, 0);
	gradient[0.5f] = sf::Color(0, 150, 100);
	gradient[1.f] = sf::Color(0, 0, 150);

	// Create color and fade in/out animations
	thor::ColorAnimation colorizer(gradient);
	thor::FadeAnimation fader(0.1f, 0.1f);

	// Add particle affectors
	pSys2->addAffector(thor::AnimationAffector(colorizer));
	pSys2->addAffector(thor::AnimationAffector(fader));

    mPlayer = NWorld::createActor<ParticleTestor>();
    mPlayer->setPosition(NWorld::getActiveView().getCenter());
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
    }

    return true;
}

bool GameState::update(sf::Time dt)
{
    NWorld::tick(dt);

    if (sf::Keyboard::isKeyPressed(Game::getKeyBinding().getKey("1")))
    {
        mPlayer->setParticleAngle(-200 * dt.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(Game::getKeyBinding().getKey("2")))
    {
        mPlayer->setParticleAngle(200 * dt.asSeconds());
    }

    NWorld::getWindow().setDebugInfo("Actors",std::to_string(NWorld::getActorCount()));
    NWorld::getWindow().setDebugInfo("Tickables",std::to_string(NWorld::getTickableCount()));
    NWorld::getWindow().setDebugInfo("Renderables",std::to_string(NWorld::getRenderableCount()));
    NWorld::getWindow().setDebugInfo("ParticlesSystems",std::to_string(NWorld::getParticleSystemCount()));
    NWorld::getWindow().setDebugInfo("MX",std::to_string(NWorld::getPointerPositionView().x));
    NWorld::getWindow().setDebugInfo("MY",std::to_string(NWorld::getPointerPositionView().y));
    return true;
}

void GameState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    NWorld::render();
}

void GameState::onActivate()
{
}

void GameState::onDeactivate()
{
    NWorld::clear();
}
