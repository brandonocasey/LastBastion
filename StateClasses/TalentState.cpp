#include "TalentState.h"

TalentState TalentState::m_TalentState;

void TalentState::Init(GameEngine* game)
{
    m_sName = "Talent";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);
}
void TalentState::Cleanup(GameEngine* game)
{
}

void TalentState::PauseState(GameEngine* game)
{
}
void TalentState::ResumeState(GameEngine* game)
{
}

void TalentState::HandleEvents(GameEngine* game)
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            // If they hit a key we change to the press start state
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
            logger.Log("User Has Exited Shop");
            game->PopState();
            break;
        }
    }
}
void TalentState::Update(GameEngine* game)
{
}
void TalentState::Draw(GameEngine* game)
{
}