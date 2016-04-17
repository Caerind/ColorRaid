#ifndef MAP_HPP
#define MAP_HPP

#include "NodeEngine/Core/Actor.hpp"
#include "NodeEngine/Core/LayerComponent.hpp"

class Map : public NActor
{
    public:
        Map();

        void gen();

        static sf::Vector2i getChunkSize();
        static sf::Vector2i getTileSize();

    private:
        NLayerComponent mMap;
};

#endif // MAP_HPP
