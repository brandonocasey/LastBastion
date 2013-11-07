#pragma once
#include "../Utils.h"
#include "../Classes/GameEngine.h"

class TileSet
{
public:
    void Init(GameEngine* game, int tile_width, int tile_height, std::string tile_source);
    bool GetCollision(int tile_id);
    void DrawTile(GameEngine* game, int x, int y, int tile_id);
    void SetCollision(int tile_id, bool collision);
private:
    int m_iTileSetWidth;
    int m_iTileSetHeight;
    int m_iTileWidth;
    int m_iTileHeight;
    SDL_Texture* m_cTexture;
    std::hash_map<int, bool> m_hTileProperties;
};
