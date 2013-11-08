#include "NewGameState.h"

NewGameState NewGameState::m_NewGameState;

void NewGameState::Init(GameEngine* game)
{
    m_sName = "NewGame";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    m_vMenuItems.push_back( new MenuItem("Confirm", boost::bind(&NewGameState::LevelSelectCallback, this, _1)) );
    m_vMenuItems.push_back( new MenuItem("Back", boost::bind(&NewGameState::BackCallback, this, _1)) );
}
void NewGameState::Cleanup(GameEngine* game)
{
    CleanupMenuItems(game);
}

void NewGameState::LevelSelectCallback(GameEngine* game)
{
    game->ChangeState( LevelSelectState::Instance() );
}

void NewGameState::BackCallback(GameEngine* game)
{
    game->PopState();
}

void NewGameState::PauseState(GameEngine* game)
{
}
void NewGameState::ResumeState(GameEngine* game)
{
}

void NewGameState::HandleEvents(GameEngine* game)
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
void NewGameState::Update(GameEngine* game)
{
    UpdateMenuItems(game);
}
void NewGameState::Draw(GameEngine* game)
{
    DrawMenuItems(game);
}