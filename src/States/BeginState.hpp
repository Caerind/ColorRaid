#ifndef BEGINSTATE_HPP
#define BEGINSTATE_HPP

#include "../NodeEngine/Application/Application.hpp"
#include "../NodeEngine/Application/State.hpp"
#include "States.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>

class BeginState : public ah::State
{
    public:
        BeginState(ah::StateManager& manager);
        virtual ~BeginState();

        bool handleEvent(sf::Event const& event);
        bool update(sf::Time dt);
        void render(sf::RenderTarget& target, sf::RenderStates states);

        void onActivate();
        void onDeactivate();

    protected:
        sf::Sprite mBackground;
        sf::Sprite mTut;
        std::vector<sf::Text> mTexts;
};

#endif // BEGINSTATE_HPP
