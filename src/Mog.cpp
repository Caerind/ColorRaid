#include "Mog.hpp"
#include "Game.hpp"

Mog::Mog()
{
    mSprite.setTexture("mogs");
    setType(NMath::random(0,2));

    mLifeMax = 100 + static_cast<int>(Game::getGameDuration().asSeconds());
    mLife = mLifeMax;

    mJins = nullptr;
}

void Mog::setJins(Jins::Ptr jins)
{
    mJins = jins;
}

void Mog::tick(sf::Time dt)
{
    NVector d = mJins->getPosition() - getPosition();
    NVector n = d;
    if (d.size2D() < 300.f)
    {
        n.normalize();
        n *= dt.asSeconds() * 120.f;
        move(n);
        moving(true);
        if (d.size2D() < 40.f && mLastHit.getElapsedTime() > sf::seconds(1.f))
        {
            mLastHit.restart();
            mJins->setLife(mJins->getLife() - NMath::random(1,3));
        }
    }
    else
    {
        moving(false);
    }
}
