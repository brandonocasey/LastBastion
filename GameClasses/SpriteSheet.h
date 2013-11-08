#pragma once
#include "../Utils.h"
#include "../HelperClasses/RenderHelper.h"

class SpriteSheet
{
public:
    SpriteSheet(std::string spritesheet_source, int sprite_height, int sprite_width);
    ~SpriteSheet();
    void GetSpritePosition(int sprite_id, int *sprite_x, int *sprite_y);
    void DrawTile(SDL_Renderer* current_renderer, int sprite_id, int x, int y);
    int RoundUp(int number, int multiple);
private:
    int m_iSpriteHeight;
    int m_iSpriteWidth;
    int m_iTotalWidth;
    int m_iTotalHeight;
    SDL_Texture* m_cTexture;
    RenderHelper* m_cRenderHelper;
};
