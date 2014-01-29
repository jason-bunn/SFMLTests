#include <MenuState.hpp>
#include <Button.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mGuiContainer()
{
    //set background texture
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    mBackgroundSprite.setTexture(texture);

    //menu buttons
    auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    playButton->setPosition(768,300);
    playButton->setText("Play");
    playButton->setCallBack([this] ()
                            {
                                requestStackPop();
                                requestStackPush(States::Game);
                            });

    auto settingsButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    settingsButton->setPosition(768, 350);
    settingsButton->setText("Settings");
    //settingsButton->setCallBack([this] ()
    //                            {
     //                               requestStackPush(States::Settings);
     //                           });

    auto exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    exitButton->setPosition(768, 400);
    exitButton->setText("Exit");
    exitButton->setCallBack([this] ()
                            {
                                requestStackPop();
                            });

    mGuiContainer.pack(playButton);
    mGuiContainer.pack(settingsButton);
    mGuiContainer.pack(exitButton);
}

void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.setView(window.getDefaultView());

    window.draw(mBackgroundSprite);
    window.draw(mGuiContainer);
}

bool MenuState::update(sf::Time)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    mGuiContainer.handleEvent(event);
    return false;
}
