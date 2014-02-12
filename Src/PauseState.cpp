#include <PauseState.hpp>
#include <Button.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
, mBackgroundSprite()
, mPausedText()
, mGuiContainer()
{
    sf::Font& font = context.fonts->get(Fonts::Main);
    sf::Vector2f windowSize(context.window->getSize());

    mPausedText.setFont(font);
    mPausedText.setString("Game Paused");
    mPausedText.setCharacterSize(70);
    centerOrigin(mPausedText);
    mPausedText.setPosition(0.5f * windowSize.x, 0.4f * windowSize.y);

    auto returnButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    returnButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 75);
    returnButton->setText("Return", 20);
    returnButton->setCallBack([this] ()
                              {
                                  requestStackPop();
                              });

    auto backToMenuButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    backToMenuButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 125);
    backToMenuButton->setText("Main Menu", 20);
    backToMenuButton->setCallBack([this] ()
                                  {
                                      //need to add some functionality here to reset or clear game state.
                                      GameState::clearGameState();
                                      requestStateClear();
                                      requestStackPush(States::Menu);
                                  });
    mGuiContainer.pack(returnButton);
    mGuiContainer.pack(backToMenuButton);
}

void PauseState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());

    sf::RectangleShape backgroundShape;
    backgroundShape.setFillColor(sf::Color(0,0,0,150));
    backgroundShape.setSize(window.getView().getSize());

    window.draw(backgroundShape);
    window.draw(mPausedText);
    window.draw(mGuiContainer);
}

bool PauseState::update(sf::Time)
{
    return false;
}

bool PauseState::handleEvent(const sf::Event& event)
{
    mGuiContainer.handleEvent(event);
    return false;
}
