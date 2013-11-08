#include "LoadGameState.h"

LoadGameState LoadGameState::m_LoadGameState;

void LoadGameState::Init(GameEngine* game)
{
    m_sName = "Load";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    //Foreach save file, make a load entry
    bool games_to_load = false;
    if( game->AssetLoader->SaveFilesExist() )
    {
        games_to_load = true;
    }
    m_vMenuItems.push_back( new MenuItem("Load", boost::bind(&LoadGameState::LoadGameCallback, this, _1), games_to_load) );
    m_vMenuItems.push_back( new MenuItem("Back", boost::bind(&LoadGameState::BackCallback, this, _1)) );
}
void LoadGameState::Cleanup(GameEngine* game)
{
}

void LoadGameState::PauseState(GameEngine* game)
{
}
void LoadGameState::ResumeState(GameEngine* game)
{
}

void LoadGameState::LoadGameCallback(GameEngine* game)
{
    //game->AssetHandler->LoadGame()
    game->ChangeState( LevelSelectState::Instance() );
}

void LoadGameState::BackCallback(GameEngine* game)
{
    //game->AssetHandler->LoadGame()
    game->PopState();
}
void LoadGameState::HandleEvents(GameEngine* game)
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            // If they hit a key we change to the press start state
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
void LoadGameState::Update(GameEngine* game)
{
    UpdateMenuItems(game);
}
void LoadGameState::Draw(GameEngine* game)
{
    DrawMenuItems(game);
}