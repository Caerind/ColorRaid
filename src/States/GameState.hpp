#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../NodeEngine/Application/Application.hpp"
#include "../NodeEngine/Application/State.hpp"
#include "States.hpp"

#include "../Jins.hpp"
#include "../Mog.hpp"
#include "../Pixelate.hpp"
#include "../Map.hpp"
#include "../NodeEngine/Utils/Joystick.hpp"

#include <iostream>

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
        Jins::Ptr mJins;
        std::vector<Mog::Ptr> mMogs;

        #ifdef N_MOBILE_PLATFORM
        Joystick mJoystick;
        sf::Sprite mButtons;
        #endif // N_MOBILE_PLATFORM

        sf::Sprite mLife;
        sf::Sprite mLifeBar;

        sf::Time mSpawnTimer;

        std::string mDurationHandle;
};

#endif // GAMESTATE_HPP
