#pragma once

// This will be the state directly after the intro
// Change it here and a few other places.
#include "../BaseClasses/BaseMenu.h"
#include "../StateClasses/LevelSelectState.h"
#include "../StateClasses/ShopState.h"
#include "../StateClasses/TalentState.h"
#include "../StateClasses/MapState.h"
#include "../StateClasses/MainMenuState.h"

class LevelSelectState : public BaseMenu
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);
    void TalentsCallback(GameEngine* game);

    void ShopCallback(GameEngine* game);
    void QuitGameCallback(GameEngine* game);

    void QuitToMenuCallback(GameEngine* game);
    void LevelCallback(GameEngine* game);

    void BackCallback(GameEngine* game);
    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    static LevelSelectState* Instance()
    {
        return &m_LevelSelectState;
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
    LevelSelectState() {}

private:
    std::string m_sName;
    static LevelSelectState m_LevelSelectState;
    GameLog logger;
};
