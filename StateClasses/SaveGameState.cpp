#include "SaveGameState.h"

SaveGameState SaveGameState::m_SaveGameState;

void SaveGameState::Init(GameEngine* game)
{
    m_sName = "Save";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    //Foreach save file, make a save entry
    m_vMenuItems.push_back( new MenuItem("Save", boost::bind(&SaveGameState::SaveGameCallback, this, _1)) );
    m_vMenuItems.push_back( new MenuItem("Back", boost::bind(&SaveGameState::BackCallback, this, _1)) );
}
void SaveGameState::Cleanup(GameEngine* game)
{
}

void SaveGameState::PauseState(GameEngine* game)
{
}
void SaveGameState::ResumeState(GameEngine* game)
{
}

void SaveGameState::SaveGameCallback(GameEngine *game)
{
    //game->AssetHandler->SaveGame()
    game->PopState();
}
void SaveGameState::HandleEvents(GameEngine* game)
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
void SaveGameState::Update(GameEngine* game)
{
    UpdateMenuItems(game);
}
void SaveGameState::Draw(GameEngine* game)
{
    DrawMenuItems(game);
}