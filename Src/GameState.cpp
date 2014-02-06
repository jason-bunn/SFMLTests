#include <GameState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Events::EventRouter mainRouter;
Events::EventRouter* routerPtr = &mainRouter;

GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mWorld(*context.window, *context.fonts, routerPtr)
, mSystem(*context.textures, *context.window, routerPtr)
, mainCam(mWorld, mSystem, *context.window, routerPtr)

{

    mSystem.createEntity<Player>();
    routerPtr->Broadcast("playerCreated");


}

void GameState::draw()
{
    mainCam.draw();
    mWorld.draw();
    mSystem.draw();
}

bool GameState::update(sf::Time dt)
{
    mWorld.update(dt);
    mSystem.update(dt);
    mainCam.update(dt);


    //CommandQueue& commands = mScene.getCommandQueue();
    //mPlayer.handleRealtimeInput(commands);

    return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
    //game input handling
    //CommandQueue& commands = mScene.getCommandQueue();
    //mPlayer.handleEvent(event, commands);

    //Escape pressed, trigger the pause screen
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
        requestStackPush(States::Pause);
    }

    return true;
}
