#include "StartState.h"

StartState StartState::m_StartState;

void StartState::Init(GameEngine* game)
{
    m_sName = "Start";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);
}
void StartState::Cleanup(GameEngine* game)
{
}

void StartState::PauseState(GameEngine* game)
{
}
void StartState::ResumeState(GameEngine* game)
{
}

void StartState::HandleEvents(GameEngine* game)
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            // If they hit a key we change to the press start state
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
            logger.Log("User Has Pushed Start");
            game->PushState( MainMenuState::Instance() );
            break;
        }
    }
}
void StartState::Update(GameEngine* game)
{
}
void StartState::Draw(GameEngine* game)
{
}