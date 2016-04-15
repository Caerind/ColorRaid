#include "ParticleTestor.hpp"

#include <Thor/Math.hpp>
#include <Thor/Vectors.hpp>

ParticleTestor::ParticleTestor()
{
	mParticleAngle = -90.f;

    mComponent2.setPosition(-30,0,0);
    mComponent1.setEmissionRate(30.f);
	mComponent1.setParticleLifetime(sf::seconds(5.f));
    mComponent1.setParticleVelocity(thor::Distributions::deflect(thor::PolarVector2f(200.f, mParticleAngle), 10.f));
    mComponent1.setParticleColor(sf::Color::Red);
    mComponent1.connectToSystem("test1");

    mComponent2.setPosition(30,0,0);
    mComponent2.setEmissionRate(30.f);
	mComponent2.setParticleLifetime(sf::seconds(5.f));
    mComponent2.setParticleVelocity(thor::Distributions::deflect(thor::PolarVector2f(200.f, mParticleAngle), 10.f));
    mComponent2.setParticleColor(sf::Color::Green);
    mComponent2.connectToSystem("test2");

    mComponent.setPosition(30,30,0);
    mComponent.setTexture("icon");

    attachComponent(&mComponent1);
    attachComponent(&mComponent2);
    attachComponent(&mComponent);
}

void ParticleTestor::setParticleAngle(float angle)
{
    mParticleAngle += angle;
    mComponent1.setParticleVelocity(thor::Distributions::deflect(thor::PolarVector2f(200.f, mParticleAngle), 10.f));
    mComponent2.setParticleVelocity(thor::Distributions::deflect(thor::PolarVector2f(200.f, mParticleAngle), 10.f));
}
