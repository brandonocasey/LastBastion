#pragma once

// This will be the state directly after the intro
// Change it here and a few other places.
#include "../BaseClasses/BaseMenu.h"
#include "../StateClasses/LevelSelectState.h"
class NewGameState : public BaseMenu
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);


    void BackCallback(GameEngine* game);

    void LevelSelectCallback(GameEngine* game);
    static NewGameState* Instance()
    {
        return &m_NewGameState;
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
    NewGameState() {}

private:
    std::string m_sName;
    static NewGameState m_NewGameState;
    GameLog logger;
};
