#include "PauseGameState.h"

void PauseGameState::ResumeState(GameEngine* game)
{
}
void PauseGameState::Cleanup(GameEngine* game)
{
    CleanupMenuItems(game);
}
void PauseGameState::Draw(GameEngine* game)
{
    DrawMenuItems(game);
}
void PauseGameState::Update(GameEngine* game)
{
    UpdateMenuItems(game);
}
void PauseGameState::HandleEvents(GameEngine* game)
{
}

void PauseGameState::QuitGameCallback(GameEngine* game)
{
    game->Quit();
}
void PauseGameState::QuitToMenuCallback(GameEngine* game)
{
    game->ChangeState( LevelSelectState::Instance() );
}
void PauseGameState::SaveCallback(GameEngine* game)
{
    game->PushState( SaveGame::Instance() );
}
void PauseGameState::LoadCallback(GameEngine* game)
{
    game->PushState( LoadGameState::Instance() );
}
void PauseGameState::SettingsCallback(GameEngine* game)
{
    game->PushState( SettingsState::Instance() );
}
void PauseGameState::BackToGame(GameEngine* game)
{
    game->PopState();
}

void PauseGameState::Init(GameEngine* game)
{
    m_sName = "Pause";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    m_vMenuItems.push_back( new MenuItem("Quit Game", boost::bind(&PauseState::QuitGameCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Quit to Menu", boost::bind(&PauseState::QuitToMenuCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Save", boost::bind(&PauseState::SaveCallback, this, _1) ) );

    bool games_to_load = false;
    if( game->AssetLoader->SaveFilesExist() )
    {
        games_to_load = true;
    }
    m_vMenuItems.push_back( new MenuItem("Load", boost::bind(&PauseState::LoadCallback, this, _1), games_to_load ) );
    m_vMenuItems.push_back( new MenuItem("Settings", boost::bind(&PauseState::SettingsCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Return to Game", boost::bind(&PauseState::BackToGame, this, _1) ) );
}