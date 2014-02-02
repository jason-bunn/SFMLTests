#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP

//Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
    class Shader;
}

namespace Textures
{
    enum ID
    {
        TitleScreen,
        Buttons,
        Particle,
        PlayerBoy,
    };
}

namespace Shaders
{
    enum ID
    {
        BrightnessPass,
        DownSamplePass,
        GaussianBlurPass,
        AddPass,
    };
}

namespace Fonts
{
    enum ID
    {
        Main,
        InGame,
    };
}

//forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;
typedef ResourceHolder<sf::Texture, Textures::ID>       TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>             FontHolder;
typedef ResourceHolder<sf::Shader, Shaders::ID>         ShaderHolder;
#endif // RESOURCEIDENTIFIERS_HPP
