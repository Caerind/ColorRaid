#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <fstream>

#include <SFGUI/SFGUI.hpp>

class Game
{
    public:
        static Game& instance();

        static std::string getTitle();

        static void drawGui(sf::RenderWindow& window);

    private:
        Game();
        ~Game();

		bool load();
		void save();

        sfg::SFGUI mSfgui;

        static Game* mInstance;
};

#endif // GAME_HPP
