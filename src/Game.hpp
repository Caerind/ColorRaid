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
        typedef std::shared_ptr<thor::ActionMap<std::string>> ActionMapPtr;

        static Game& instance();

        static std::string getTitle();
        static std::string getConfigFile();

        static void drawGui(sf::RenderWindow& window);

        static lp::KeyBinding& getKeyBinding();

        static sf::Time getGameDuration();
        static void resetGameDuration();

		static bool load(std::string const& filename);
		static void save(std::string const& filename);

    private:
        Game();
        ~Game();

        static Game* mInstance;

        sfg::SFGUI mSfgui;

        lp::KeyBinding mKeys;

        sf::Clock mGameDuration;
};

#endif // GAME_HPP
