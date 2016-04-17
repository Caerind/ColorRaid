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

        static void resetKilled();
        static void addKilled();
        static int getKilled();

        static int getGoodDamage();
        static int getBadDamage();

        static void drawGui(sf::RenderWindow& window);

        static lp::KeyBinding& getKeyBinding();

        static sf::Time getGameDuration();
        static void resetGameDuration();

		static bool load();
		static void save();

		static float getPixelValue();
		static void setPixelValue(float v);

    private:
        Game();
        ~Game();

        static Game* mInstance;

        sfg::SFGUI mSfgui;

        lp::KeyBinding mKeys;

        sf::Clock mGameDuration;

        int mKilled;

        float mPixelValue;
};

#endif // GAME_HPP
