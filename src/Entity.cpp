#include "Entity.hpp"

Entity::Entity()
{
    setPosition(0.f,0.f,0.f);

    mSprite.setPosition(0.f,0.f,0.f);
    mSprite.setOrigin(32,32);
    attachComponent(&mSprite);

    mParticles.setPosition(-5.f,0.f,0.f);
    mParticles.setEmissionRate(20.f);
	mParticles.setParticleLifetime(sf::seconds(0.15f));
    mParticles.connectToSystem("p");
    attachComponent(&mParticles);

    mLife = 100;
    mLifeMax = 100;
    mType = 0;
}

void Entity::setLife(int life)
{
    mLife = life;
}

int Entity::getLife() const
{
    return mLife;
}

void Entity::setLifeMax(int lifeMax)
{
    mLifeMax = lifeMax;
}

int Entity::getLifeMax() const
{
    return mLifeMax;
}

void Entity::setType(int type)
{
    mType = type;
    mSprite.setTextureRect(sf::IntRect(64 * mType,0,64,64));

    if (type == 0)
    {
        mParticles.setParticleColor(sf::Color::Blue);
    }
    if (type == 1)
    {
        mParticles.setParticleColor(sf::Color::Red);
    }
    if (type == 2)
    {
        mParticles.setParticleColor(sf::Color::Yellow);
    }
}

int Entity::getType() const
{
    return mType;
}

void Entity::moving(bool moving)
{
    mMoving = moving;
}

bool Entity::isMoving() const
{
    return mMoving;
}
