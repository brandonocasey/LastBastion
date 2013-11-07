class Player : BaseMovingObject
{
    SDL_Rect* CursorLocation;
    current_cursor;

    DropTower()
    {
        m_bTowerSelected = false;
        //get rid of cursor texture
    }
    PickUp()
    {
    }
    HandleInput()
    {
        if( MOUSEBUTTONUP )
        {
            // Check if the user clicked the tower building interface
            if( m_bTowerSelected )
            {
                if( TowerBuildCollsion() || RightClick() )
                {
                    // if tower is clicked over towerbuild ui drop it
                    // Or rightclick is the button pressed
                    DropTower();
                }
            }

            if( TowerBuildCollsion() )
            {
                PickUpTower(x, y); // pickup tower at ui coordinates
            }

            // Check if the user clicked the next wave button
            if( NextWaveCollision )
            {
                NextWaveEarly();
            }

            // Check if the user clicked the Pause button
            if( PauseButton() )
            {
                Pause();
            }
        }
        if( MOUSEWHEEL_UP )
        {
            // Zoom In
        }
        if( MOUSEWHEEL_DOWN )
        {
            // Zoom Out
        }
    }
    Update()
    {
        // we only need the cursor if they have a tower selected
        if( m_bTowerSelected )
        {
            GetMouseLocation(cursor_x, cursor_y);
            texture = game->LoadImage(cursor);
            SDL_Rect* location;

#include <math.h>       /* ceil */
            tile_x == ceil(cursor_x/TILE_SIZE)
                tile_y = ceil(cursor_y/TILE_SIZE)

                map->[tile_x][tile_y].GetPosition(location->x, location->y)
                location->h = TILE_SIZE;
            location->w = TILE_SIZE;
        }
        // MoveCamera if the mouse is trying to move past the edge
    }
    Draw()
    {
        DrawCursor(game)
    }
    DrawCursor // we the map to be passed here for this
    {
        render current_cursor
    }
};
