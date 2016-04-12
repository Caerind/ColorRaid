#include "NodeEngine/Application/Application.hpp"
#include "States/States.hpp"
#include "Game.hpp"

int main()
{
    ah::Application::getResources().loadImage("icon","assets/Textures/icon.png");
    ah::Application::getResources().loadTexture("ld","assets/Textures/ld.png");
    ah::Application::getResources().loadTexture("libs","assets/Textures/libs.png");
    ah::Application::getResources().loadTexture("back","assets/Textures/back.png");
    ah::Application::getResources().loadTexture("cursor","assets/Textures/cursor.png");
    ah::Application::getResources().loadTexture("icon","assets/Textures/icon.png");
    ah::Application::getResources().loadTexture("particle","assets/Textures/particle.png");
    ah::Application::getResources().loadFont("atmog","assets/Fonts/atmog.ttf");
    ah::Application::getResources().loadFont("cool","assets/Fonts/coolveticca.ttf");
    ah::Application::getResources().loadSoundBuffer("jingle","assets/Sounds/jingleAtmog.wav");

    ah::Application::getResources().getTexture("ld").setSmooth(true);
    ah::Application::getResources().getTexture("libs").setSmooth(true);
    ah::Application::getResources().getTexture("back").setSmooth(true);

    ah::Application::getWindow().setTitle(Game::getTitle());
    ah::Application::getWindow().create();
    ah::Application::getWindow().setIcon(&ah::Application::getResources().getImage("icon"));
    ah::Application::getWindow().setDebugInfoFont(&ah::Application::getResources().getFont("cool"));
    ah::Application::getWindow().showDebugInfo(true);

    ah::Application::getStates().registerState<IntroState>();
    ah::Application::getStates().registerState<MenuState>();
    ah::Application::getStates().registerState<GameState>();
    ah::Application::getStates().registerState<SettingsState>();

    ah::Application::getStates().pushState<IntroState>();

    ah::Application::getAudio().playMusic("assets/Musics/theme.ogg");

    Game::instance();

    ah::Application::run();

    return 0;
}
