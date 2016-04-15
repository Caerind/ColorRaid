#ifndef NPARTICLESYSTEM_HPP
#define NPARTICLESYSTEM_HPP

#include "SceneComponent.hpp"

#include <Thor/Particles.hpp>

class NParticleSystem : public NSceneComponent, public thor::ParticleSystem
{
    public:
        typedef std::shared_ptr<NParticleSystem> Ptr;

    public:
        NParticleSystem();

        void setTexture(std::string const& id);

        virtual void tick(sf::Time dt);
        virtual void render(sf::RenderTarget& target);
};

#endif // NPARTICLESYSTEM_HPP
