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
    thor::ParticleSystem* system = NWorld::getParticleSystem(systemId);
    if (system != nullptr)
    {
        mConnection = system->addEmitter(thor::refEmitter(*this));
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failed" << std::endl;
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
