#include "Pixelate.hpp"
#include "NodeEngine/Core/World.hpp"

Pixelate::Pixelate()
{
}

void Pixelate::apply(sf::RenderTexture const& input, sf::RenderTarget& output)
{
    sf::Shader& shader = NWorld::getResources().getShader("pixelate");
    float x = NWorld::getPointerPositionScreen().x / NWorld::getWindow().getSize().x;
    float y = NWorld::getPointerPositionScreen().y / NWorld::getWindow().getSize().y;
    shader.setParameter("texture",input.getTexture());
    shader.setParameter("pixel_threshold", (x + y) / 30);
    applyShader(shader,output);
}
