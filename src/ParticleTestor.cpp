#include "ParticleTestor.hpp"

#include <Thor/Math.hpp>
#include <Thor/Vectors.hpp>

ParticleTestor::ParticleTestor()
{
    mComponent1.setEmissionRate(30.f);
	mComponent1.setParticleLifetime(sf::seconds(5.f));
	thor::PolarVector2f velocity(200.f, -90.f);
    mComponent1.setParticleVelocity(thor::Distributions::deflect(velocity, 10.f));
    mComponent1.connectToSystem("test1");
}
