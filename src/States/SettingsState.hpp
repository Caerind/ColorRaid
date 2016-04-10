#ifndef SETTINGSSTATE_HPP
#define SETTINGSSTATE_HPP

#include "../NodeEngine/Application/Application.hpp"
#include "../NodeEngine/Application/State.hpp"
#include "States.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include "../Game.hpp"

class SettingsState : public ah::State
{
    public:
        SettingsState(ah::StateManager& manager);
        virtual ~SettingsState();

        bool handleEvent(sf::Event const& event);
        bool update(sf::Time dt);
        void render(sf::RenderTarget& target, sf::RenderStates states);

        void onActivate();
        void onDeactivate();

    private:

        sf::Sprite mBackground;
};

#endif // SETTINGSSTATE_HPP
