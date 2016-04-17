#include "Jins.hpp"

Jins::Jins()
{
    mSprite.setTexture("jins");
    attachComponent(&mCamera);

    setType(Jins::Blue);

    mLife = 500;
    mLifeMax = 500;
}
