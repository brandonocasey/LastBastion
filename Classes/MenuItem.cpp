#include "MenuItem.h"

/**
* The constructor for MenuItem that sets everything up.
* @param name              the name of this menu item
* @param callback_function the function to call when the menu choice is selected
* @param visible           whether or not this item is selectable
*/
MenuItem::MenuItem( std::string name, boost::function<void(GameEngine* game)> callback_function, bool selectable)
{
    m_sText = name;
    logger = logger->GetLogger(m_sText);

    // Action function to run
    m_fMenuCallback = callback_function;

    m_CurrentTexture = nullptr;
    m_bSelectable = selectable;

    // 5 Second Fade Time
    m_iFadeTime = 5;

    if( m_bSelectable )
    {
        // White
        m_cCurrentColor.r = 255;
        m_cCurrentColor.g = 255;
        m_cCurrentColor.b = 255;
        m_cCurrentColor.a = 255;
    }
    else
    {
        // Grey
        m_cCurrentColor.r = 190;
        m_cCurrentColor.g = 190;
        m_cCurrentColor.b = 190;
        m_cCurrentColor.a = 255;
    }
    m_cFadeTimer.Init();
}

/**
* Takes in the game pointer from HandleEvents of the Menu State to call the
* callback that our menu state gave to this item
* @param game The GameEngine pointer that gets passed around
*/
void MenuItem::RunCallback(GameEngine* game)
{
    // Stored action function to run when clicked
    if( this->CheckCollison() )
    {
        logger->Log("User Clicked Me");
        m_fMenuCallback(game);
    }
}

/**
* Cleanup all of the assets that we have in use and null everything out
* through the use of the SAFE_DELETE macro in the Utils.h file
*/
void MenuItem::Cleanup()
{
    SDL_DestroyTexture(m_CurrentTexture);
    m_CurrentTexture = nullptr;

    m_sText.erase(NULL);
    m_bSelectable = false;
    m_iFadeTime = 0;
    m_cFadeTimer.Cleanup();
}

/**
* Draw ourself to the screen
* @param game The pointer to game containing all of the objects we need to use
* @param x    the x to draw ourselves at
* @param y    the y to draw ourselves at
*/
void MenuItem::Draw(GameEngine* game, int x, int y)
{
    m_cPosition.x = x;
    m_cPosition.y = y;

    // it will automatically make it the correct size
    game->RenderHelper->RenderTextureAutoSize(m_CurrentTexture, &m_cPosition, NULL);
}

/**
* Get the size of the menu item using the texture
* @param game The pointer to game which contains a helper object for doing this
* @param w    A pointer to an int that will be filled with the width
* @param h    A pointer to an int that will be filled with the height
*/
void MenuItem::GetSize(GameEngine *game, int *w, int *h)
{
    game->RenderHelper->GetTextureSize(m_CurrentTexture, w, h);
}

/**
* Update the current texture and color of that texture, by blinking the alpha
* when selected. It also plays a sound when first selected
* @param game a pointer to the game Object that will help us with this
*/
void MenuItem::Update(GameEngine* game)
{
    // if selected start a timer to use for blinking the menu item
    // Otherwise we have it blink back to white
    if( CheckCollison() )
    {
        if( ! m_cFadeTimer.Started() )
        {
            m_cFadeTimer.Start(m_iFadeTime);
            std::string sound_folder = SOUND_FOLDER;
            game->AudioHelper->PlaySound( sound_folder + "menu_select.wav");
        }

        if( m_cFadeTimer.Ended() )
        {
            m_cFadeTimer.Restart();
        }

        if( m_cFadeTimer.SecondsElapsed() < m_iFadeTime/2 )
        {
            m_cCurrentColor.a = FadeOut(m_cCurrentColor.a);
        }
        else
        {
            FadeIn(m_cCurrentColor.a);
        }
    }
    else
    {
        m_cFadeTimer.Cleanup();
        FadeIn(m_cCurrentColor.a);
    }

    m_CurrentTexture = game->RenderHelper->LoadText(m_sText, DEFAULT_FONT_FILE, DEFAULT_FONT_SIZE, m_cCurrentColor);
}

/**
* Take a color and minus it by itself to make it appear to fade out while drawn
* @param  current_alpha The Current Alpha value to change
*/
int MenuItem::FadeOut(int current_alpha)
{
    if( current_alpha > 120 )
    {
        current_alpha -= 1;
    }
    return current_alpha;
}

/**
* Fade a menu item in so that they appear to be blinking or reset
* @param  current_alpha [description]
*/
int MenuItem::FadeIn(int current_alpha)
{
    if( current_alpha < 255 )
    {
        current_alpha += 1;
    }

    return current_alpha;
}
/**
* Eventually we will want this to be handled by EventHelper
* @return true if colliding and false if not or not selectable
*/
bool MenuItem::CheckCollison()
{
    if( ! m_bSelectable )
    {
        return false;
    }

    int mouse_x = 0;
    int mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    if( ( mouse_x > m_cPosition.x ) && ( mouse_x < m_cPosition.x + m_cPosition.w ) && ( mouse_y > m_cPosition.y ) && ( mouse_y < m_cPosition.y + m_cPosition.h ) )
    {
        return true;
    }

    return false;
}