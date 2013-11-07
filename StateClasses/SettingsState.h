#pragma once
#include "../BaseClasses/BaseMenu.h"
class SettingsState : public BaseMenu
{
public:
    void MasterVolumeCallback(GameEngine* game);
    void SoundVolumeCallback(GameEngine* game);
    void MusicVolumeCallback(GameEngine* game);
    void ToggleFullscreenCallback(GameEngine* game);
    void BrightnessCallback(GameEngine* game);
    void ResizeWindowCallback(GameEngine* game);
    void BackCallback(GameEngine* game);
    void ClearSaveDataCallback(GameEngine* game);

    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);

    static SettingsState* Instance()
    {
        return &m_SettingsState;
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
    SettingsState() { }

private:
    std::string m_sName;
    static SettingsState m_SettingsState;
    GameLog logger;
};
