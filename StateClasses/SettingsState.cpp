#include "SettingsState.h"

// Singleton Yeah!
SettingsState SettingsState::m_SettingsState;

void SettingsState::Init(GameEngine* game)
{
    m_sName = "Settings";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    m_vMenuItems.push_back( new MenuItem("Toggle Fullscreen", boost::bind(&SettingsState::ToggleFullscreenCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Master Volume", boost::bind(&SettingsState::MasterVolumeCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Music Volume", boost::bind(&SettingsState::MusicVolumeCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Sound Volume", boost::bind(&SettingsState::SoundVolumeCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Brightness", boost::bind(&SettingsState::BrightnessCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Clear Save Data", boost::bind(&SettingsState::ClearSaveDataCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Resize Window", boost::bind(&SettingsState::ResizeWindowCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Back", boost::bind(&SettingsState::BackCallback, this, _1) ) );
}

void SettingsState::ClearSaveDataCallback(GameEngine* game)
{
}

void SettingsState::MasterVolumeCallback(GameEngine* game)
{
}
void SettingsState::SoundVolumeCallback(GameEngine* game)
{
}
void SettingsState::MusicVolumeCallback(GameEngine* game)
{
}
void SettingsState::BrightnessCallback(GameEngine* game)
{
}
void SettingsState::ToggleFullscreenCallback(GameEngine* game)
{
}
void SettingsState::ResizeWindowCallback(GameEngine* game)
{
}

void SettingsState::Cleanup( GameEngine* game )
{
    CleanupMenuItems(game);
}

void SettingsState::Update( GameEngine* game )
{
    UpdateMenuItems(game);
}

void SettingsState::Draw( GameEngine* game )
{
    DrawMenuItems(game);
}

void SettingsState::BackCallback( GameEngine* game )
{

}

void SettingsState::PauseState( GameEngine* game )
{

}

void SettingsState::ResumeState( GameEngine* game )
{

}

void SettingsState::HandleEvents( GameEngine* game )
{

}
