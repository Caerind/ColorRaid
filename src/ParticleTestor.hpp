#ifndef PARTICLETESTOR_HPP
#define PARTICLETESTOR_HPP

#include "NodeEngine/Core/Actor.hpp"
#include "NodeEngine/Core/ParticleComponent.hpp"

class ParticleTestor : public NActor
{
    public:
        typedef std::shared_ptr<ParticleTestor> Ptr;

    public:
        ParticleTestor();

        NParticleComponent mComponent1;
};

#endif // PARTICLETESTOR_HPP
