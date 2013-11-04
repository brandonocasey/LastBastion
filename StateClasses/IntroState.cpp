#include "IntroState.h"

// Singleton Yeah!
IntroState IntroState::m_IntroState;

/**
* Init our m_vBackgrounds and m_vTexts, by filling them with values
* @param game our game engine pointer
*/
void IntroState::Init(GameEngine* game)
{
    m_sName = "Intro";
    logger = logger->GetLogger(m_sName);
    m_cCurrentTexture = nullptr;
    m_cCurrentText = nullptr;
    m_cImageTimer.Init();

    std::string image_folder = IMAGE_FOLDER;
    m_vBackgrounds.push_back( image_folder + "logo.jpg" );
    m_vTexts.push_back( "3nD Studios" );
}

/**
* Cleanup everything from this state
* @param game our game engine pointer
*/
void IntroState::Cleanup(GameEngine* game)
{
    SDL_DestroyTexture(m_cCurrentTexture);
    SDL_DestroyTexture(m_cCurrentText);
    m_cCurrentText = nullptr;
    m_cCurrentTexture = nullptr;

    while( ! m_vTexts.empty() )
    {
        m_vTexts.pop_back();
    }

    while( ! m_vBackgrounds.empty() )
    {
        m_vBackgrounds.pop_back();
    }

    m_cImageTimer.Cleanup();
}

/**
* Put the state into the background and clean it up
* @param game our game engine pointer
*/
void IntroState::PauseState(GameEngine* game)
{
    Cleanup(game);
    game->RenderHelper->ClearScreen();
}

/**
* Resume our state from the background
* @param game  our game engine pointer
*/
void IntroState::ResumeState(GameEngine* game)
{
    Init(game);
}

/** Handle an event where the user wants to skip the intro */
void IntroState::HandleEvents(GameEngine* game)
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            // If they hit a key we change to the press start state
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
            logger->Log("User has skipped intro");
            NextState(game);
            break;
        }
    }
}

/**
* Push a new state onto the stack, keeping this one in the background
* @param game  our game engine pointer
*/
void IntroState::NextState(GameEngine* game)
{
    game->PushState( StartState::Instance() );
}

/**
* Update the current texture and text that we are using
* @param game our game engine pointer
*/
void IntroState::Update(GameEngine* game)
{
    if( ! m_cImageTimer.Started() )
    {
        m_cImageTimer.Start(5);
        SetCurrentTextures(game);
    }
    else if( m_cImageTimer.Ended() && ! m_vBackgrounds.empty() )
    {
        m_cImageTimer.Restart();
        SetCurrentTextures(game);
    }
    else if( m_cImageTimer.Ended() && m_vBackgrounds.empty() )
    {
        NextState(game);
    }

    m_cImageTimer.Increment();
}

/**
* Save us from typing the same thing in two places
*/
void IntroState::SetCurrentTextures(GameEngine* game)
{
    if( ! m_vBackgrounds.empty() )
    {
        m_cCurrentTexture = game->RenderHelper->LoadImage( m_vBackgrounds.back() );
        m_vBackgrounds.pop_back();
    }
    if( ! m_vTexts.empty() )
    {
        m_cCurrentText = game->RenderHelper->LoadText( m_vTexts.back(), DEFAULT_FONT_FILE, 40, ColorBlack );
        m_vTexts.pop_back();
    }
}

/**
* Draw our current texture and text
* @param game  our game engine pointer
*/
void IntroState::Draw(GameEngine* game)
{
    if( m_cCurrentTexture )
    {
        game->RenderHelper->RenderTextureScale(m_cCurrentTexture);
        SDL_DestroyTexture(m_cCurrentTexture);
        m_cCurrentTexture = nullptr;
    }
    if( m_cCurrentText )
    {
        SDL_Rect text_destination;
        int x, y;
        game->RenderHelper->GetCenterForTexture(m_cCurrentText, &x, &y);
        text_destination.x = x;
        text_destination.y = y;
        game->RenderHelper->RenderTextureAutoSize(m_cCurrentText, &text_destination, NULL);
        SDL_DestroyTexture(m_cCurrentText);
        m_cCurrentText = nullptr;
    }
}