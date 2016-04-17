#include "GameState.hpp"
#include "../NodeEngine/Core/World.hpp"

GameState::GameState(ah::StateManager& manager)
: ah::State(manager)
{
    NWorld::clear();

    NWorld::getWindow().setBackgroundColor(sf::Color::White);

    mJins = NWorld::createActor<Jins>();
    mJins->setPosition(400.f,300.f,0.f);

    NWorld::createActor<Map>();

    NParticleSystem::Ptr pSys = NWorld::getParticleSystem("p");
    pSys->setTexture("particle");
    pSys->setPosition(0.f,0.f,0.f);
	pSys->addAffector(thor::TorqueAffector(300.f));
    pSys->addAffector(thor::AnimationAffector(thor::FadeAnimation(0.1f, 0.1f)));

    Game::resetGameDuration();
    Game::resetKilled();
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

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == Game::getKeyBinding().getKey("1"))
        {
            mJins->setType(Jins::Type::Blue);
        }
        if (event.key.code == Game::getKeyBinding().getKey("2"))
        {
            mJins->setType(Jins::Type::Red);
        }
        if (event.key.code == Game::getKeyBinding().getKey("3"))
        {
            mJins->setType(Jins::Type::Yellow);
        }
        if (event.key.code == Game::getKeyBinding().getKey("action"))
        {
            for (std::size_t i = 0; i < mMogs.size(); i++)
            {
                NVector d = mJins->getPosition() - mMogs[i]->getPosition();
                if (d.size2D() < 100.f)
                {
                    int damage = (mMogs[i]->getType() == mJins->getType()) ? Game::getGoodDamage() : Game::getBadDamage();
                    mMogs[i]->setLife(mMogs[i]->getLife() - damage);
                }
            }
        }
    }

    return true;
}

bool GameState::update(sf::Time dt)
{
    for (std::size_t i = 0; i < mMogs.size();)
    {
        if (mMogs[i]->getLife() <= 0)
        {
            NWorld::removeActor(mMogs[i]->getId());
            Game::addKilled();
            mMogs.erase(mMogs.begin() + i);
        }
        else
        {
            i++;
        }
    }

    NWorld::tick(dt);

    sf::Vector2f movement;
    #ifdef N_DESKTOP_PLATFORM
    if (sf::Keyboard::isKeyPressed(Game::getKeyBinding().getKey("up")))
    {
        movement.y--;
    }
    if (sf::Keyboard::isKeyPressed(Game::getKeyBinding().getKey("down")))
    {
        movement.y++;
    }
    if (sf::Keyboard::isKeyPressed(Game::getKeyBinding().getKey("left")))
    {
        movement.x--;
    }
    if (sf::Keyboard::isKeyPressed(Game::getKeyBinding().getKey("right")))
    {
        movement.x++;
    }
    #else
    // TODO : Android Joystick
    #endif // N_DESKTOP_PLATFORM
    movement *= dt.asSeconds() * 200.f;
    mJins->move(movement);
    mJins->moving(movement != sf::Vector2f(0.f,0.f));

    NVector p = mJins->getPosition();
    if (p.x < 0.f)
    {
        mJins->setPosition(0,p.y,0.f);
    }
    if (p.x > 1216.f)
    {
        mJins->setPosition(1216.f,p.y,0.f);
    }
    p = mJins->getPosition();
    if (p.y < 0.f)
    {
        mJins->setPosition(p.x,0.f,0.f);
    }
    if (p.y > 1216.f)
    {
        mJins->setPosition(p.x,1216.f,0.f);
    }

    mSpawnTimer += dt;
    float t = std::max(0.5f - 0.1f * (Game::getGameDuration().asSeconds() / 30.f),0.1f);
    if (mSpawnTimer > sf::seconds(t))
    {
        mMogs.push_back(NWorld::createActor<Mog>());
        mMogs.back()->setPosition(NMath::random(0.f,1216.f),NMath::random(0.f,1216.f),0.f);
        mMogs.back()->setJins(mJins);
        NWorld::getWindow().setDebugInfo("moglife",std::to_string(mMogs.back()->getLife()));
        mSpawnTimer = sf::Time::Zero;
    }

    NWorld::getWindow().setDebugInfo("life",std::to_string(mJins->getLife()));

    if (mJins->getLife() <= 0)
    {
        requestClear();
        requestPush("MenuState");
    }

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
