#include "ShopState.h"

ShopState ShopState::m_ShopState;

void ShopState::Init(GameEngine* game)
{
    m_sName = "Shop";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);
}
void ShopState::Cleanup(GameEngine* game)
{
}

void ShopState::PauseState(GameEngine* game)
{
}
void ShopState::ResumeState(GameEngine* game)
{
}

void ShopState::HandleEvents(GameEngine* game)
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
void ShopState::Update(GameEngine* game)
{
}
void ShopState::Draw(GameEngine* game)
{
}