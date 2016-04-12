#include "ParticleSystem.hpp"
#include "World.hpp"

NParticleSystem::NParticleSystem()
{
}

std::string NParticleSystem::getId() const
{
    return mId;
}

void NParticleSystem::setId(std::string const& id)
{
    mId = id;
}

void NParticleSystem::setTexture(std::string const& id)
{
    thor::ParticleSystem::setTexture(NWorld::getResources().getTexture(id));
}

void NParticleSystem::tick(sf::Time dt)
{
    update(dt);
}

void NParticleSystem::render(sf::RenderTarget& target)
{
    sf::RenderStates states;
    states.transform *= getFinalTransform();
    target.draw(*this);
}
