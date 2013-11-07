#include "EventHelper.h"
#include "../Classes/GameEngine.h"
void EventHelper::Init(GameEngine *game)
{
    // Show the cursor on the screen
    SDL_ShowCursor(1);

    SDL_SetEventFilter(EventHelper::ExitWatch, game);
}