#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <fstream>
#include <memory>
#include <map>

#include <SFML/System/Clock.hpp>
#include <SFGUI/SFGUI.hpp>

#include "NodeEngine/Utils/KeyBinding.hpp"

class Game
{
    public:
        static Game& instance();

        static void drawGui(sf::RenderWindow& window);

        static lp::KeyBinding& getKeyBinding();

    private:
        Game();
        ~Game();

        static Game* mInstance;

        sfg::SFGUI mSfgui;

        lp::KeyBinding mKeys;
};

#endif // GAME_HPP
