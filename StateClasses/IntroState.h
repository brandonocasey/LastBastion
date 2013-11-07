#pragma once

// This will be the state directly after the intro
// Change it here and a few other places.
#include "../BaseClasses/BaseGameState.h"
#include "StartState.h"

class IntroState : public BaseGameState
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    void NextState(GameEngine* game);
    void SetCurrentTextures(GameEngine* game);
    static IntroState* Instance()
    {
        return &m_IntroState;
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
    IntroState() {}

private:

    std::string m_sName;
    Timer m_cImageTimer;
    static IntroState m_IntroState;
    std::vector<std::string> m_vBackgrounds;
    std::vector<std::string> m_vTexts;
    SDL_Texture* m_cCurrentTexture;
    SDL_Texture* m_cCurrentText;
    GameLog logger;
};
