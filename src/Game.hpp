#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <fstream>
#include <memory>
#include <map>

#include <SFML/System/Clock.hpp>
#include <SFGUI/SFGUI.hpp>
#include <Thor/Input.hpp>

class Game
{
    public:
        typedef std::shared_ptr<thor::ActionMap<std::string>> ActionMapPtr;

        static Game& instance();

        static std::string getTitle();

        static void drawGui(sf::RenderWindow& window);

        static void setActionKey(std::string const& id, sf::Keyboard::Key key);
        static sf::Keyboard::Key getActionKey(std::string const& id);
        static ActionMapPtr getActionMap();

        static sf::Time getGameDuration();
        static void resetGameDuration();

    private:
        Game();
        ~Game();

		bool load();
		void save();

        static Game* mInstance;



        sfg::SFGUI mSfgui;

        ActionMapPtr mActionMap;
        std::map<std::string,std::pair<sf::Keyboard::Key,bool>> mKeys;

        sf::Clock mGameDuration;
};

#endif // GAME_HPP
