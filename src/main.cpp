#include "NodeEngine/Application/Application.hpp"
#include "NodeEngine/Utils/Log.hpp"
#include "States/States.hpp"
#include "Game.hpp"

int main()
{
    ah::Application::getValues().setString("title","Color Raid");
    ah::Application::getValues().setString("file","assets/Data/settings.xml");
    ah::Application::getValues().setInt("killed",0);

    ah::Application::getResources().loadImage("icon","assets/Textures/icon.png");
    ah::Application::getResources().loadTexture("splash","assets/Textures/splash.png");
    ah::Application::getResources().loadTexture("back","assets/Textures/back.jpeg");
    ah::Application::getResources().loadTexture("cursor","assets/Textures/cursor.png");
    ah::Application::getResources().loadTexture("icon","assets/Textures/icon.png");
    ah::Application::getResources().loadTexture("particle","assets/Textures/particle.png");
    ah::Application::getResources().loadTexture("jins","assets/Textures/jins.png");
    ah::Application::getResources().loadTexture("mogs","assets/Textures/mogs.png");
    ah::Application::getResources().loadTexture("tileset","assets/Textures/tileset.png");
    ah::Application::getResources().loadTexture("joyButton","assets/Textures/joyButton.png");
    ah::Application::getResources().loadTexture("joyBackground","assets/Textures/joyBackground.png");
    ah::Application::getResources().loadTexture("buttons","assets/Textures/buttons.png");
    ah::Application::getResources().loadTexture("tut","assets/Textures/tut.png");
    ah::Application::getResources().loadTexture("life","assets/Textures/life.png");
    ah::Application::getResources().loadFont("atmog","assets/Fonts/atmog.ttf");
    ah::Application::getResources().loadFont("cool","assets/Fonts/coolveticca.ttf");
    ah::Application::getResources().loadSoundBuffer("jingle","assets/Sounds/jingleAtmog.wav");
    ah::Application::getResources().loadShader("pixel","assets/Shaders/pixelate.frag",sf::Shader::Fragment);

    ah::Application::getResources().getTexture("splash").setSmooth(true);
    ah::Application::getResources().getShader("pixel").setParameter("pixel_threshold",0.0001f);

    Game::getKeyBinding().setKey("1",sf::Keyboard::Num1);
    Game::getKeyBinding().setKey("2",sf::Keyboard::Num2);
    Game::getKeyBinding().setKey("3",sf::Keyboard::Num3);
    Game::getKeyBinding().setKey("action",sf::Keyboard::Space);
    Game::getKeyBinding().setKey("up",sf::Keyboard::Z);
    Game::getKeyBinding().setKey("down",sf::Keyboard::S);
    Game::getKeyBinding().setKey("left",sf::Keyboard::Q);
    Game::getKeyBinding().setKey("right",sf::Keyboard::D);

    std::string f = ah::Application::getValues().getString("file");
    ah::Application::getWindow().load(f);
    ah::Application::getAudio().load(f);
    ah::Application::getValues().load(f);
    Game::getKeyBinding().load(f);

    ah::Application::getWindow().setTitle(ah::Application::getValues().getString("title"));
    ah::Application::getWindow().create();
    ah::Application::getWindow().setIcon(&ah::Application::getResources().getImage("icon"));
    ah::Application::getWindow().setDebugInfoFont(&ah::Application::getResources().getFont("cool"));
    ah::Application::getWindow().setDebugInfoColor(sf::Color::Black);
    ah::Application::getWindow().showDebugInfo(false);

    ah::Application::getStates().registerState<IntroState>("IntroState");
    ah::Application::getStates().registerState<MenuState>("MenuState");
    ah::Application::getStates().registerState<GameState>("GameState");
    ah::Application::getStates().registerState<SettingsState>("SettingsState");
    ah::Application::getStates().registerState<EndState>("EndState");
    ah::Application::getStates().registerState<BeginState>("BeginState");

    ah::Application::getStates().pushState("IntroState");

    ah::Application::getAudio().playMusic("assets/Musics/theme.ogg",true);

    NLog::setOnline("http://atmog.altervista.org/","Log/","Color Raid","1.0.0","None");

    ah::Application::run();

    f = ah::Application::getValues().getString("file");
    ah::Application::getWindow().save(f);
    ah::Application::getAudio().save(f);
    ah::Application::getValues().save(f);
    Game::getKeyBinding().save(f);

    return 0;
}
