#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <fstream>

class Game
{
    public:
        static Game& instance();

        static std::string getTitle();

    private:
        Game();
        ~Game();

		bool load();
		void save();

        static Game* mInstance;
};

#endif // GAME_HPP
