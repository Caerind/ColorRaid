#ifndef PIXELATE_HPP
#define PIXELATE_HPP

#include "NodeEngine/Core/Effect.hpp"

class Pixelate : public NEffect
{
    public:
        Pixelate();

        void apply(sf::RenderTexture const& input, sf::RenderTarget& output);

};
#endif // PIXELATE_HPP
