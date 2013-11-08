#pragma once

// This will be the state directly after the intro
// Change it here and a few other places.
#include "../BaseClasses/BaseMenu.h"
#include "../StateClasses/MainMenuState.h"
class LoadGameState : public BaseMenu
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);


    void LoadGameState::LoadGameCallback(GameEngine* game);
    void LoadGameState::BackCallback(GameEngine* game);

    static LoadGameState* Instance()
    {
        return &m_LoadGameState;
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
    LoadGameState() {}

private:
    std::string m_sName;
    Timer* m_cImageTimer;
    static LoadGameState m_LoadGameState;
    SDL_Texture* m_cCurrentText;
    GameLog logger;
};
