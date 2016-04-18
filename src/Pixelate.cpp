#include "Pixelate.hpp"
#include "NodeEngine/Core/World.hpp"

Pixelate::Pixelate()
{
}

void Pixelate::apply(sf::RenderTexture const& input, sf::RenderTarget& output)
{
    sf::Shader& shader = NWorld::getResources().getShader("pixel");
    shader.setParameter("texture",input.getTexture());
    applyShader(shader,output);
}
