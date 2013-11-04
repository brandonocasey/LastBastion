#include "Utils.h"

// State which we are testing
#include "StateClasses/IntroState.h"
#include "Classes/GameEngine.h"

int main ( int argc, char** argv )
{
    GameEngine game;

    // initialize the engine, if there is an error return 1 for failure
    if( game.Init(GAME_NAME, 640, 640, false) )
    {
        return 1;
    }

    // load the intro
    game.ChangeState( IntroState::Instance() );

    // main loop
    while ( game.Running() )
    {
        game.Run();
    }

    // cleanup the engine
    game.Cleanup();

    return 0;
}