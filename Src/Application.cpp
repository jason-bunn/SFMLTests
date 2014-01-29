#include <Application.hpp>
#include <Utility.hpp>
#include <State.hpp>
#include <StateIdentifiers.hpp>
#include <TitleState.hpp>
#include <GameState.hpp>
#include <MenuState.hpp>
#include <PauseState.hpp>
//#include <SettingsState.hpp>
//#incldue <GameOverState.hpp>

#include <iostream>

const sf::Time Application::TimePerFrame = sf::seconds(1.0f/60.0f);

Application::Application()
: mWindow(sf::VideoMode(1024, 768), "Epic 2dRPG - Pre-Alpha")
, mTextures()
, mFonts()
//, mPlayer()
, mStateStack(State::Context(mWindow, mTextures, mFonts))//, mPlayer))
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)

{
    mWindow.setKeyRepeatEnabled(false);

    mFonts.load(Fonts::Main, "Media/SF Square Head.ttf");
    mFonts.load(Fonts::InGame, "Media/8bm.ttf");

    //load menu and title images
    mTextures.load(Textures::TitleScreen, "Media/Images/MenuScreen.png");
    //load button images
    mTextures.load(Textures::Buttons, "Media/Images/NewButtons.png");

    //initialize framerate/debug text
    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setColor(sf::Color::White);
    mStatisticsText.setPosition(5.0f, 5.0f);
    mStatisticsText.setCharacterSize(10u);

    //register states and push the title state onto the stack
    registerStates();
    mStateStack.pushState(States::Title);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            //process inputs
            processInput();
            //update logic frame
            update(TimePerFrame);

            //check inside this loop because stack might be empty before update call
            if(mStateStack.isEmpty())
                mWindow.close();
        }

        updateStatistics(dt);
        //draw stuff
        render();
    }
}

void Application::processInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        //send events to current state
        mStateStack.handleEvent(event);

        //close the window if event registered
        if(event.type == sf::Event::Closed)
        {
            mWindow.close();
        }
    }
}

void Application::update(sf::Time dt)
{
    //send update to current state
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();

    //send draw call to current state
    mStateStack.draw();
    //set the view of the main window
    mWindow.setView(mWindow.getDefaultView());

    mWindow.draw(mStatisticsText);

    mWindow.display();
}

void Application::updateStatistics(sf::Time dt)
{
    mStatisticsUpdateTime += dt;
    mStatisticsNumFrames +=1;
    if(mStatisticsUpdateTime >= sf::seconds(1.0f))
    {
        mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));

        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}

void Application::registerStates()
{
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);
   // mStateStack.registerState<SettingsState>(States::Settings);
   // mStateStack.registerState<GameOverState>(States::GameOver);
}
