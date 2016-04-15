#ifndef NPARTICLECOMPONENT_HPP
#define NPARTICLECOMPONENT_HPP

#include "Component.hpp"

#include <Thor/Particles.hpp>

class NParticleComponent : public NComponent, public thor::UniversalEmitter
{
    public:
        NParticleComponent();
        ~NParticleComponent();

        void connectToSystem(std::string const& systemId);
        bool isConnected() const;
        void disconnect();

        void onMovedThis();

    protected:
        thor::Connection mConnection;
};

#endif // NPARTICLECOMPONENT_HPP
