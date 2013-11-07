#pragma once
/**
* @file MenuItem
* Needs to be passed a callback
* Needs to be passed a name
* Should be possible to make an item unselectable but visible
* Needs to grow when selected and shrink when unselected
* Needs to change colors when selected and unselected
*/

#include "../Utils.h"
#include "../Classes/GameEngine.h"

class MenuItem
{
public:

    MenuItem( std::string text, boost::function<void(GameEngine* game)> callback_function, bool selectable = true );
    bool CheckCollison();
    void GetSize(GameEngine *game, int *w, int *h);

    void Update(GameEngine* game);
    void Draw(GameEngine* game, int x, int y);
    void RunCallback(GameEngine* game);
    void Cleanup();

private:
    int FadeOut(int current_alpha);
    int FadeIn(int current_alpha);

    bool m_bSelected;
    GameLog logger;
    std::string m_sText;
    SDL_Texture* m_CurrentTexture;
    bool m_bSelectable;
    boost::function<void(GameEngine* game)> m_fMenuCallback;
    SDL_Color m_cCurrentColor;
    SDL_Rect m_cPosition;
    Timer m_cFadeTimer;
    int m_iFadeTime;
};
