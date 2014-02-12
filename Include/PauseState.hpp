#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP


#include <State.hpp>
#include <Container.hpp>
#include <GameState.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class PauseState : public State
{
public:
                            PauseState(StateStack& stack, Context contex);

    virtual void            draw();
    virtual bool            update(sf::Time dt);
    virtual bool            handleEvent(const sf::Event& event);

private:
    sf::Sprite              mBackgroundSprite;
    sf::Text                mPausedText;
    GUI::Container          mGuiContainer;
};
#endif // PAUSESTATE_HPP
