#ifndef PARTICLETESTOR_HPP
#define PARTICLETESTOR_HPP

#include "NodeEngine/Core/Actor.hpp"
#include "NodeEngine/Core/ParticleComponent.hpp"
#include "NodeEngine/Core/SpriteComponent.hpp"

class ParticleTestor : public NActor
{
    public:
        typedef std::shared_ptr<ParticleTestor> Ptr;

    public:
        ParticleTestor();

        void onMoved();

        void setParticleAngle(float angle);

    protected:
        NParticleComponent mComponent1;
        NParticleComponent mComponent2;
        float mParticleAngle;
};

#endif // PARTICLETESTOR_HPP
