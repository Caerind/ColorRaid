#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "../NodeEngine/Application/Application.hpp"
#include "../NodeEngine/Application/State.hpp"
#include "States.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include "../Game.hpp"

class MenuState : public ah::State
{
    public:
        MenuState(ah::StateManager& manager);
        virtual ~MenuState();

        bool handleEvent(sf::Event const& event);
        bool update(sf::Time dt);
        void render(sf::RenderTarget& target, sf::RenderStates states);

        void onActivate();
        void onDeactivate();

    private:

        sf::Sprite mBackground;
        sf::Text mTitleText;
        sf::Text mTitleShadow;
};

#endif // MENUSTATE_HPP
