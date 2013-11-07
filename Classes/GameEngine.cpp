#include "GameEngine.h"
#include "../BaseClasses/BaseGameState.h" // This is included here so that we can use it in both files
#include "../HelperClasses/EventHelper.h" // Breaks the damn circle dependency

/**
* This function initializes the game engine
* @param  title      The title for the games window
* @param  width      the width of our game screen
* @param  height     the height of our game screen
* @param  fullscreen true for fullscreen window
* @return            0 if everything was successful
*/
int GameEngine::Init(const char* title, int width = 640, int height = 640, bool fullscreen = false)
{
    // Spin up our logger for debugging
    m_sName = "GameEngine";

    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    // Initialize our SDL Session
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        logger.LogSdlError( "SDL_Init: " );
        return 1;
    }
    else
    {
        logger.Log("SDL_Init: SDL_Init_Everything work OK");
    }

    // Get Some Helpful Classes

    // Error Handling, needed badly
    AudioHelper = AudioHelper->GetAudioHelper();
    EventHelper->Init(this);
    RenderHelper = RenderHelper->GetRenderHelper(title, width, height, fullscreen);
    //SaveHelper = SaveHelper->GetSaveHelper();

    // Now We are ready to run
    m_bRunning = true;

    return 0;
}

/**
* This function cleans up all of the resources that we create in init and
* also cleans up all of our states
*/
void GameEngine::Cleanup()
{
    logger.Log("Attempting to cleanup all of the things in GameEngine");
    while( ! states.empty() )
    {
        logger.Log("Calling Cleanup function for " + states.back()->GetName());
        states.back()->Cleanup(this);
        states.pop_back();
    }

    RenderHelper->Cleanup();
    AudioHelper->Cleanup();

    SDL_Quit();
}

/**
* Change the games state completely, by getting rid of current states and
* cleaning them up. Followed by pushing a state and running its init function.
* @param state The state we want to go to
*/
void GameEngine::ChangeState(BaseGameState* state)
{
    if( ! states.empty() )
    {
        states.back()->Cleanup(this);
        states.pop_back();
        RenderHelper->ClearScreen();
    }

    states.push_back( state );
    states.back()->Init(this);
    logger.Log("Changing State to " + state->GetName());
}

/**
* Push a state onto the stack and pause the current state
* @param state The state to push
*/
void GameEngine::PushState(BaseGameState* state)
{
    // Pause the current State
    if ( !states.empty() )
    {
        states.back()->PauseState(this);
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init(this);
    logger.Log("Pushing a new State " + state->GetName());
}

/**
* Pop the current state off of the stack and and resume the previous state
*/
void GameEngine::PopState()
{
    // cleanup the current state
    if ( !states.empty() )
    {
        states.back()->Cleanup(this);
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() )
    {
        states.back()->ResumeState(this);
    }
    else
    {
        logger.LogError("Attempted to pop off a state when there are none");
    }
    logger.Log("Getting rid of the current state" + states.back()->GetName() );
}

/**
* Have the current state handle events
*/
void GameEngine::HandleEvents()
{
    if( ! states.empty() && m_bRunning )
    {
        states.back()->HandleEvents(this);
    }
}

/**
* Have the current state update
*/
void GameEngine::Update()
{
    if( ! states.empty() && m_bRunning )
    {
        states.back()->Update(this);
    }
}

/**
* Have the current state draw itself
*/
void GameEngine::Draw()
{
    if( ! states.empty() && m_bRunning )
    {
        states.back()->Draw(this);
    }
}

/**
* Returns the current status of the game
* @return a bool indicating the current status of the game
*/
bool GameEngine::Running()
{
    return m_bRunning;
}

/**
* Set the game status to false, meaning that the game should quit
*/
void GameEngine::Quit()
{
    logger.Log("Quit has been called");
    m_bRunning = false;
}

/**
* Call all of the function that are state needs to run with
*/
void GameEngine::Run()
{
    this->HandleEvents();
    this->Update();
    this->Draw();
}