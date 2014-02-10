#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <Camera.hpp>
#include <State.hpp>
#include <World.hpp>
#include <entities/Player.hpp>
#include <tgd/System.hpp>
#include <events/EventRouter.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class GameState : public State
{
public:

                    GameState(StateStack& stack, Context context);

    virtual void    draw();
    virtual bool    update(sf::Time dt);
    virtual bool    handleEvent(const sf::Event& event);
    void            clearGameState();

public:

private:

    World                   mWorld;
    tgd::System             mSystem;
    Camera                  mainCam;

    //Player&       mPlayer;
};
#endif // GAMESTATE_HPP
