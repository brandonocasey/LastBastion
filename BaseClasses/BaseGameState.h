#pragma once
#include "../Utils.h"
#include "../Classes/GameEngine.h"
class BaseGameState
{
public:
    virtual void Init(GameEngine* game) = 0;
    virtual void Cleanup(GameEngine* game) = 0;

    virtual void PauseState(GameEngine* game) = 0;
    virtual void ResumeState(GameEngine* game) = 0;

    virtual void HandleEvents(GameEngine* game) = 0;
    virtual void Update(GameEngine* game) = 0;
    virtual void Draw(GameEngine* game) = 0;

    std::string GetName()
    {
        if( m_sName.empty() )
        {
            m_sName = "Unset";
        }
        return m_sName;
    }

protected:
    std::string m_sName;
    BaseGameState() { } // Constructor
};
