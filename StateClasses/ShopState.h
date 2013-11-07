#pragma once

// This will be the state directly after the intro
// Change it here and a few other places.
#include "../BaseClasses/BaseMenu.h"

class ShopState : public BaseMenu
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    static ShopState* Instance()
    {
        return &m_ShopState;
    }
    std::string GetName()
    {
        if( m_sName.empty() )
        {
            m_sName = "Unknown";
        }
        return m_sName;
    }
protected:
    ShopState() {}

private:
    std::string m_sName;
    Timer* m_cImageTimer;
    static ShopState m_ShopState;
    SDL_Texture* m_cCurrentText;
    GameLog logger;
};
