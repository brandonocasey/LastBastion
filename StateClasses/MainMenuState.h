#pragma once
#include "../BaseClasses/BaseMenu.h"
class MainMenuState : public BaseMenu
{
public:
    void QuitCallback(GameEngine* game);
    void NewGameCallback(GameEngine* game);
    void LoadGameCallback(GameEngine* game);
    void SettingsCallback(GameEngine* game);

    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);

    static MainMenuState* Instance()
    {
        return &m_MainMenuState;
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
    MainMenuState() { }

private:
    std::string m_sName;
    static MainMenuState m_MainMenuState;
    GameLog *logger;
};
