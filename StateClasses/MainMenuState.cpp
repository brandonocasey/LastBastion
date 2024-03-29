#include "MainMenuState.h"

MainMenuState MainMenuState::m_MainMenuState;

void MainMenuState::QuitCallback( GameEngine* game )
{
    game->Quit();
}

void MainMenuState::NewGameCallback( GameEngine* game )
{
    game->PushState( NewGameState::Instance() );
}

void MainMenuState::LoadGameCallback( GameEngine* game )
{
    //game->PushState( LoadGameState::Instance() );
}

void MainMenuState::SettingsCallback( GameEngine* game )
{
    game->PushState( SettingsState::Instance() );
}

void MainMenuState::Init( GameEngine* game )
{
    m_sName = "MainMenu";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);
    m_vMenuItems.push_back( new MenuItem("New Game", boost::bind(&MainMenuState::NewGameCallback, this, _1)) );

    bool games_to_load = false;
    if( game->AssetLoader->SaveFilesExist() )
    {
        games_to_load = true;
    }
    m_vMenuItems.push_back( new MenuItem("Load Game", boost::bind(&MainMenuState::LoadGameCallback, this, _1), games_to_load ) );
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
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            for(MenuItem *it : m_vMenuItems)
            {
                it->RunCallback(game);
            }
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:

                BackCallback(game);
                break;
            }
            break;
        }
    }
}

void MainMenuState::Update( GameEngine* game )
{
    UpdateMenuItems(game);
}

void MainMenuState::Draw( GameEngine* game )
{
    DrawMenuItems(game);
}