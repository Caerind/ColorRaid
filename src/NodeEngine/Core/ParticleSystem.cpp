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
    mSystem.setTexture(NWorld::getResources().getTexture(id));
}

void NParticleSystem::setTexture(sf::Texture& texture)
{
    mSystem.setTexture(texture);
}

void NParticleSystem::tick(sf::Time dt)
{
    mSystem.update(dt);
    std::cout << "up" << std::endl;
}

void NParticleSystem::render(sf::RenderTarget& target)
{
    sf::RenderStates states;
    states.transform *= getFinalTransform();
    target.draw(mSystem);
    std::cout << "ren" << std::endl;
}

thor::ParticleSystem& NParticleSystem::getSystem()
{
    return mSystem;
}
