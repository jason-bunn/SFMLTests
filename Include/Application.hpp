#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <Utility.hpp>
#include <ResourceHolder.hpp>
#include <ResourceIdentifiers.hpp>
//#include <Player.hpp>
#include <StateStack.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>


class Application
{
    public:
                            Application();
        void                run();

    public:
        sf::RenderWindow    mWindow;
        TextureHolder       mTextures;
        FontHolder          mFonts;

    private:
        void                processInput();
        void                update(sf::Time dt);
        void                render();

        void                updateStatistics(sf::Time dt);
        void                registerStates();

    private:
        static const sf::Time TimePerFrame;



        //Player              mPlayer;

        StateStack          mStateStack;


        sf::Text            mStatisticsText;
        sf::Time            mStatisticsUpdateTime;
        std::size_t         mStatisticsNumFrames;



};

#endif // APPLICATION_HPP
