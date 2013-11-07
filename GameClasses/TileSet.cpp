#include "TileSet.h"

void TileSet::Init(GameEngine* game, int tile_width, int tile_height, std::string tile_source)
{
    m_iTileWidth = tile_width;
    m_iTileHeight = tile_height;

    int last_slash = tile_source.find_last_of("/");

    if( last_slash > 0 )
    {
        tile_source = tile_source.substr(last_slash+1);
    }
    tile_source = SPRITES_FOLDER + tile_source;
    m_cTexture = game->RenderHelper->LoadImage(tile_source);
    game->RenderHelper->GetTextureSize(m_cTexture, &m_iTileSetWidth, &m_iTileSetHeight);
}

bool TileSet::GetCollision(int tile_id)
{
    if(m_hTileProperties[tile_id])
    {
        return m_hTileProperties[tile_id];
    }

    return false;
}

void TileSet::SetCollision(int tile_id, bool collision)
{
    m_hTileProperties[tile_id] = collision;
}

void TileSet::DrawTile(GameEngine* game, int x, int y, int tile_id)
{
    SDL_Rect source;

    int tiles_per_row = m_iTileSetWidth/m_iTileSetWidth;
    int column_for_id = ceil((float)tile_id/(float)tiles_per_row);

    source.x = (tile_id - tiles_per_row) * m_iTileSetWidth;
    source.y = column_for_id;
    source.h = m_iTileSetHeight;
    source.w = m_iTileSetWidth;

    SDL_Rect destination;
    destination.x = x * m_iTileWidth;
    destination.y = y * m_iTileHeight;
    destination.h = source.h;
    destination.w = source.w;

    game->RenderHelper->RenderTexture(m_cTexture, &source, &destination);
}
