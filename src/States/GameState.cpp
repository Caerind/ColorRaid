#include "GameState.hpp"
#include "../NodeEngine/Core/World.hpp"

GameState::GameState(ah::StateManager& manager)
: ah::State(manager)
{
    NWorld::clear();

    NWorld::setEffect<Pixelate>();

    mJins = NWorld::createActor<Jins>();
    mJins->setPosition(NMath::random(100.f,1100.f),NMath::random(100.f,1100.f),0.f);

    NWorld::createActor<Map>();

    NParticleSystem::Ptr pSys = NWorld::getParticleSystem("p");
    pSys->setTexture("particle");
    pSys->setPosition(0.f,0.f,0.f);
    // TODO : Affectors
	//pSys->addAffector(thor::TorqueAffector(300.f));
    //pSys->addAffector(thor::AnimationAffector(thor::FadeAnimation(0.1f, 0.1f)));

    NWorld::getValues().setInt("killed",0);

    #ifdef N_MOBILE_PLATFORM
    mJoystick.setButtonTexture(NWorld::getResources().getTexture("joyButton"));
    mJoystick.setBackgroundTexture(NWorld::getResources().getTexture("joyBackground"));
    mJoystick.setPosition(sf::Vector2f(NWorld::getWindow().getSize().x - 150, NWorld::getWindow().getSize().y - 150));
    mJoystick.setDeltaMax(50);

    mButtons.setTexture(NWorld::getResources().getTexture("buttons"));
    mButtons.setPosition(0.f, NWorld::getWindow().getSize().y - 200.f);
    #endif // N_MOBILE_PLATFORM

    mLife.setTexture(NWorld::getResources().getTexture("life"));
    mLife.setTextureRect(sf::IntRect(0,0,200,26));
    mLife.setPosition(NWorld::getWindow().getSize().x - 200,0);
    mLifeBar.setTexture(NWorld::getResources().getTexture("life"));
    mLifeBar.setTextureRect(sf::IntRect(0,26,200,26));
    mLifeBar.setPosition(NWorld::getWindow().getSize().x - 200,0);

    mDurationHandle = NWorld::startTimer();

    std::string h = NWorld::setTimer(sf::seconds(0.25f),[&]()
    {
        mMogs.push_back(NWorld::createActor<Mog>((int)NWorld::getTimerElapsed(mDurationHandle).asSeconds()));
        mMogs.back()->setPosition(NMath::random(0.f,1216.f),NMath::random(0.f,1216.f),0.f);
        mMogs.back()->setJins(mJins);
    });
    NWorld::repeatTimer(h,true);
}

GameState::~GameState()
{
}

bool GameState::handleEvent(sf::Event const& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        requestClear();
        requestPush("EndState");
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
                    int damage = (mMogs[i]->getType() == mJins->getType()) ? 100 : 30;
                    mMogs[i]->setLife(mMogs[i]->getLife() - damage);
                }
            }
        }
    }

    #ifdef N_MOBILE_PLATFORM
    mJoystick.handleEvent(event);

    sf::FloatRect bR(0,NWorld::getWindow().getSize().y-200.f,250,200);
    if ((event.type == sf::Event::TouchBegan && bR.contains(event.touch.x,event.touch.y))
    || (event.type == sf::Event::MouseButtonPressed && bR.contains(event.mouseButton.x,event.mouseButton.y)))
    {
        #ifndef WINDOWS
        sf::Vector2f p = sf::Vector2f(event.touch.x,event.touch.y);
        #else
        sf::Vector2f p = sf::Vector2f(event.mouseButton.x,event.mouseButton.y);
        #endif // WINDOWS
        sf::FloatRect a(0,NWorld::getWindow().getSize().y - 200.f +90,170,110);
        sf::FloatRect u(36,NWorld::getWindow().getSize().y - 200.f +12,75,65);
        sf::FloatRect d(150,NWorld::getWindow().getSize().y - 200.f +25,75,65);
        sf::FloatRect t(175,NWorld::getWindow().getSize().y - 200.f +115,75,65);
        if (a.contains(p))
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
        if (u.contains(p))
        {
            mJins->setType(Jins::Type::Blue);
        }
        if (d.contains(p))
        {
            mJins->setType(Jins::Type::Red);
        }
        if (t.contains(p))
        {
            mJins->setType(Jins::Type::Yellow);
        }
    }
    #endif // N_MOBILE_PLATFORM

    return true;
}

bool GameState::update(sf::Time dt)
{
    for (std::size_t i = 0; i < mMogs.size();)
    {
        if (mMogs[i]->getLife() <= 0)
        {
            NWorld::removeActor(mMogs[i]->getId());
            NWorld::getValues().setInt("killed",1 + NWorld::getValues().getInt("killed"));
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
    movement = mJoystick.getDelta();
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

    NWorld::getWindow().setDebugInfo("t",std::to_string(NWorld::getTimerElapsed(mDurationHandle).asSeconds()));

    if (mJins->getLife() <= 0)
    {
        requestClear();
        requestPush("EndState");
    }

    mLife.setTextureRect(sf::IntRect(0,0,200.f * ((float)mJins->getLife() / (float)mJins->getLifeMax()),26));

    return true;
}

void GameState::render(sf::RenderTarget& target, sf::RenderStates states)
{
    NWorld::render();

    #ifdef N_MOBILE_PLATFORM
    mJoystick.render(target,states);
    target.draw(mButtons);
    #endif // N_MOBILE_PLATFORM

    target.draw(mLifeBar,states);
    target.draw(mLife,states);
}

void GameState::onActivate()
{
}

void GameState::onDeactivate()
{
    NWorld::clear();
}
