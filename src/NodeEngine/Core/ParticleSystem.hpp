#ifndef NPARTICLESYSTEM_HPP
#define NPARTICLESYSTEM_HPP

#include "SceneComponent.hpp"

#include <Thor/Particles.hpp>

class NParticleSystem : public NSceneComponent
{
    public:
        NParticleSystem();

        std::string getId() const;
        void setId(std::string const& id);

        void setTexture(std::string const& id);
        void setTexture(sf::Texture& texture);

        void tick(sf::Time dt);
        void render(sf::RenderTarget& target);

        thor::ParticleSystem& getSystem();

    protected:
        std::string mId;
        thor::ParticleSystem mSystem;
};

#endif // NPARTICLESYSTEM_HPP
