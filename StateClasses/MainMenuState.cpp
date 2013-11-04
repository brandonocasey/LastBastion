#include "MainMenuState.h"

MainMenuState MainMenuState::m_MainMenuState;

void MainMenuState::QuitCallback( GameEngine* game )
{
    game->Quit();
}

void MainMenuState::NewGameCallback( GameEngine* game )
{
    //game->ChangeState( NewGameState::Instance() );
}

void MainMenuState::LoadGameCallback( GameEngine* game )
{
    //game->ChangeState( LoadGameState::Instance() );
}

void MainMenuState::SettingsCallback( GameEngine* game )
{
    //game->ChangeState( SettingsState::Instance() );
}

void MainMenuState::Init( GameEngine* game )
{
    m_sName = "MainMenu";
    logger = logger->GetLogger(m_sName);
    m_vMenuItems.push_back( new MenuItem("New Game", boost::bind(&MainMenuState::NewGameCallback, this, _1)) );
    m_vMenuItems.push_back( new MenuItem("Load Game", boost::bind(&MainMenuState::LoadGameCallback, this, _1), false ) );
    m_vMenuItems.push_back( new MenuItem("Settings", boost::bind(&MainMenuState::SettingsCallback, this, _1)) );
    m_vMenuItems.push_back( new MenuItem("Quit", boost::bind(&MainMenuState::QuitCallback, this, _1)) );
}

void MainMenuState::Cleanup( GameEngine* game )
{
    CleanupMenuItems(game);
}

void MainMenuState::PauseState( GameEngine* game )
{
}

void MainMenuState::ResumeState( GameEngine* game )
{
}

void MainMenuState::HandleEvents( GameEngine* game )
{
}

void MainMenuState::Update( GameEngine* game )
{
    UpdateMenuItems(game);
}

void MainMenuState::Draw( GameEngine* game )
{
    DrawMenuItems(game);
}