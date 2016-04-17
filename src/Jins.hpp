#ifndef JINS_HPP
#define JINS_HPP

#include "Entity.hpp"
#include "NodeEngine/Core/CameraComponent.hpp"

class Jins : public Entity
{
    public:
        Jins();

        typedef std::shared_ptr<Jins> Ptr;

        enum Type
        {
            Blue = 0,
            Red = 1,
            Yellow = 2,
        };

    private:
        NCameraComponent mCamera;
};

#endif // JINS_HPP
