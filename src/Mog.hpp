#ifndef MOG_HPP
#define MOG_HPP

#include "Entity.hpp"
#include "Jins.hpp"

#include <SFML/System/Clock.hpp>

class Mog : public Entity
{
    public:
        Mog(int l);

        typedef std::shared_ptr<Mog> Ptr;

        void setJins(Jins::Ptr jins);

        void tick(sf::Time dt);

        enum Type
        {
            Blue = 0,
            Red = 1,
            Yellow = 2,
        };

    private:
        Jins::Ptr mJins;
        bool mFollow;
        sf::Clock mLastHit;
};

#endif // MOG_HPP
