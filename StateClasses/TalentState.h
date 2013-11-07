#pragma once

// This will be the state directly after the intro
// Change it here and a few other places.
#include "../BaseClasses/BaseMenu.h"

class TalentState : public BaseMenu
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    static TalentState* Instance()
    {
        return &m_TalentState;
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
    TalentState() {}

private:
    std::string m_sName;
    Timer* m_cImageTimer;
    static TalentState m_TalentState;
    SDL_Texture* m_cCurrentText;
    GameLog logger;
};
