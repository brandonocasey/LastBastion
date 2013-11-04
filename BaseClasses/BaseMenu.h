#pragma once

/**
* @file BaseMenu
* Required Features:
* should tell menu items what to do
* Should have a header for the name of the menu that can be in picture or text format
* Should Animate off and on with alpha
* needs to be given staring location for menu items
* Needs to be given a starting location for the header
*
*/
#include "../Utils.h"
#include "BaseGameState.h"
#include "../Classes/MenuItem.h"
#include "../Classes/GameEngine.h"

class BaseMenu : public BaseGameState
{
public:
    virtual void Init(GameEngine* game) = 0;
    virtual void Cleanup(GameEngine* game) = 0;

    void UpdateMenuItems(GameEngine* game)
    {
        for(MenuItem *item : m_vMenuItems)
        {
            item->Update(game);
        }
    }

    void CleanupMenuItems(GameEngine* game)
    {
        while( ! m_vMenuItems.empty() )
        {
            m_vMenuItems.back()->Cleanup();
            m_vMenuItems.pop_back();
        }
    }

    void DrawMenuItems(GameEngine* game, int x_offset_from_center, int y_offset_from_center)
    {
        int screen_width = 0;
        int screen_height = 0;

        game->RenderHelper->GetWindowSize( &screen_width, &screen_height );

        int x = 0;
        int y = 0;

        for(MenuItem *item : m_vMenuItems)
        {
            int menu_item_height = 0;
            int menu_item_width = 0;

            item->GetSize(game, &menu_item_width, &menu_item_height);
            x = (screen_width /2) - (menu_item_height /2);
            y += menu_item_width;
            item->Draw(game, x, y);
        }
    }

    void DrawMenuItems(GameEngine* game)
    {
        DrawMenuItems( game, 0 , 0 );
    }

    virtual void PauseState(GameEngine* game) = 0;
    virtual void ResumeState(GameEngine* game) = 0;

    virtual void HandleEvents(GameEngine* game) = 0;
    virtual void Update(GameEngine* game) = 0;
    virtual void Draw(GameEngine* game) = 0;

protected:
    GameLog *logger;
    float m_fCurrentAlpha;
    SDL_Texture* m_cCurrentTexture;
    std::vector<MenuItem*> m_vMenuItems;
};