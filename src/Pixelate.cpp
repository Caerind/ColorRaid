#include "Pixelate.hpp"
#include "NodeEngine/Core/World.hpp"

Pixelate::Pixelate()
{
}

void Pixelate::apply(sf::RenderTexture const& input, sf::RenderTarget& output)
{
    sf::Shader& shader = NWorld::getResources().getShader("pixelate");
    shader.setParameter("texture",input.getTexture());
    shader.setParameter("pixel_threshold", 0.004f);
    applyShader(shader,output);
}
