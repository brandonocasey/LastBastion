#pragma once

#include "../Utils.h"
#include "../Classes/GameEngine.h"
class EventHelper
{
public:
    void Init(GameEngine *game);
    static int SDLCALL ExitWatch(void *game, SDL_Event *event)
    {
        if( event->type == SDL_QUIT )
        {
            static_cast<GameEngine*>(game)->Quit();
            return 0;
        }
        return 1;
    }
};
