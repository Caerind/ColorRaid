#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../NodeEngine/Application/Application.hpp"
#include "../NodeEngine/Application/State.hpp"
#include "States.hpp"

#include "../ParticleTestor.hpp"

class GameState : public ah::State
{
    public:
        GameState(ah::StateManager& manager);
        virtual ~GameState();

        bool handleEvent(sf::Event const& event);
        bool update(sf::Time dt);
        void render(sf::RenderTarget& target, sf::RenderStates states);

        void onActivate();
        void onDeactivate();

    private:
        ParticleTestor::Ptr mPlayer;
};

#endif // GAMESTATE_HPP
