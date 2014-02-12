#include <GameState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Events::EventRouter mainRouter;
Events::EventRouter* routerPtr = &mainRouter;

GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mWorld(*context.window, *context.fonts, routerPtr)
, mSystem(*context.textures, *context.window, routerPtr, &mWorld.mMapLoader)
, mainCam(mWorld, mSystem, *context.window, routerPtr)

{

    mSystem.createEntity<Player>();
    routerPtr->Broadcast("playerCreated");


}

void GameState::draw()
{
    //camera draws background layers
    mainCam.draw();

    //system draws entities
    mSystem.draw();
    //world draws top layers
    mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
    //camera queries map quadtree for map collisions
    mainCam.update(dt);

    mSystem.update(dt);

    mWorld.update(dt);

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

void GameState::clearGameState()
{
    std::cout << "Clearing Game State" << std::endl;
    //World::cleanup();
    delete routerPtr;
}
