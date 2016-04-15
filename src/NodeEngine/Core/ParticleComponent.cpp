#include "ParticleComponent.hpp"
#include "World.hpp"

NParticleComponent::NParticleComponent()
{
}

NParticleComponent::~NParticleComponent()
{
    disconnect();
}

void NParticleComponent::connectToSystem(std::string const& systemId)
{
    NParticleSystem::Ptr system = NWorld::getParticleSystem(systemId);
    if (system != nullptr)
    {
        mConnection = system->addEmitter(thor::refEmitter(*this));
    }
}

bool NParticleComponent::isConnected() const
{
    return mConnection.isConnected();
}

void NParticleComponent::disconnect()
{
    mConnection.disconnect();
}

void NParticleComponent::onMovedThis()
{
    setParticlePosition(NVector::NToSFML2F(getFinalPosition()));
}
