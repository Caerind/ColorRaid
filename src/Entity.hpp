#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "NodeEngine/Core/Actor.hpp"
#include "NodeEngine/Core/SpriteComponent.hpp"
#include "NodeEngine/Core/ParticleComponent.hpp"

class Entity : public NActor
{
    public:
        Entity();

        void setLife(int life);
        int getLife() const;

        void setLifeMax(int lifeMax);
        int getLifeMax() const;

        void setType(int type);
        int getType() const;

        void moving(bool moving);
        bool isMoving() const;

    protected:
        int mLife;
        int mLifeMax;
        int mType;
        bool mMoving;

        NSpriteComponent mSprite;
        NParticleComponent mParticles;
};

#endif // ENTITY_HPP
