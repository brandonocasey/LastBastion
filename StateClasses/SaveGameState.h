#pragma once

// This will be the state directly after the intro
// Change it here and a few other places.
#include "../BaseClasses/BaseMenu.h"
#include "../StateClasses/MainMenuState.h"
class SaveGameState : public BaseMenu
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    void SaveGameCallback(GameEngine* game);

    static SaveGameState* Instance()
    {
        return &m_SaveGameState;
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
    SaveGameState() {}

private:
    std::string m_sName;
    Timer* m_cImageTimer;
    static SaveGameState m_SaveGameState;
    SDL_Texture* m_cCurrentText;
    GameLog logger;
};
