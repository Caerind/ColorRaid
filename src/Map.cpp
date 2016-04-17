#include "Map.hpp"

Map::Map()
{
    mMap.create("tileset",getChunkSize(),getTileSize(),NLayerComponent::Orthogonal);
    mMap.setPosition(-32.f,-32.f,-100.f);

    gen();
}

void Map::gen()
{
    int type = NMath::random(0,2);

    // Ground
    sf::Vector2i itr;
    for (itr.x = 0; itr.x < mMap.getMapSize().x; itr.x++)
    {
        for (itr.y = 0; itr.y < mMap.getMapSize().y; itr.y++)
        {
            mMap.setTileId(itr,1 + 18 * type);
        }
    }

    // Deco
    for (int n = 0; n < 80; n++)
    {
        itr.x = NMath::random(0,mMap.getMapSize().x);
        itr.y = NMath::random(0,mMap.getMapSize().y);
        if (NMath::random(0,1) == 0)
        {
            mMap.setTileId(itr,2 + 18 * type);
        }
        else
        {
            mMap.setTileId(itr,4 + 18 * type);
        }
    }

    // Wall
    for (itr.x = 0; itr.x < mMap.getMapSize().x; itr.x++)
    {
        for (itr.y = 0; itr.y < mMap.getMapSize().y; itr.y++)
        {
            if (itr.x == 0 || itr.y == 0 || itr.x == getChunkSize().x-1 || itr.y == getChunkSize().y-1)
            {
                mMap.setTileId(itr,3);
            }
        }
    }
}

sf::Vector2i Map::getChunkSize()
{
    return sf::Vector2i(40,40);
}

sf::Vector2i Map::getTileSize()
{
    return sf::Vector2i(32,32);
}

