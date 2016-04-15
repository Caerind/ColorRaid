#include "ParticleSystem.hpp"
#include "World.hpp"

NParticleSystem::NParticleSystem()
{
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
