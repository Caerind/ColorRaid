#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP

#include "../NodeEngine/Application/Application.hpp"
#include "../NodeEngine/Application/State.hpp"
#include "States.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>

class EndState : public ah::State
{
    public:
        EndState(ah::StateManager& manager);
        virtual ~EndState();

        bool handleEvent(sf::Event const& event);
        bool update(sf::Time dt);
        void render(sf::RenderTarget& target, sf::RenderStates states);

        void onActivate();
        void onDeactivate();

    protected:
        sf::Sprite mBackground;
        sf::Sprite mTut;
        sf::Text mText;
};

#endif // ENDSTATE_HPP
