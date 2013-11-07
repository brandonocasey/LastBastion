#pragma once
#include "../Utils.h"
// Tutorial on showing current FPS etc
//http://lazyfoo.net/SDL_tutorials/lesson15/index.php

class RenderHelper
{
public:
    bool Init(const char* title, int width, int height, bool fullscreen);
    void Cleanup();
    TTF_Font* LoadFont(std::string font_location, int font_size);
    SDL_Texture* LoadText(std::string text, std::string font_location = DEFAULT_FONT_FILE, int font_size = DEFAULT_FONT_SIZE, SDL_Color font_color = ColorWhite );
    SDL_Texture* LoadImage(std::string image_location);
    void GetFontSize(TTF_Font* font, std::string text, int *width, int *height);
    void GetTextureSize(SDL_Texture* texture, int *width, int *height);

    void GetCenterForTexture(SDL_Texture* texture, int *x, int *y);
    void RenderTextureScale(SDL_Texture* texture);
    void RenderTextureAutoSize(SDL_Texture* texture, SDL_Rect* destination, SDL_Rect* source);
    void RenderTexture(SDL_Texture* text_texture, SDL_Rect* destination, SDL_Rect* source = nullptr);

    void GetWindowSize(int *width, int *height);

    void ToggleFullscreen();
    void ToggleFullscreen(bool fullscreen);

    void FullscreenOn();
    void FullscreenOff();

    void ClearScreen();

    void ResizeWindow(int width, int height);

    void RenderHelper::RenderText(std::string font_location, int font_size, std::string text, SDL_Color color, SDL_Rect* destination, SDL_Rect* source = nullptr);
    void RenderHelper::RenderImage(std::string image_location, SDL_Rect* destination, SDL_Rect* source = nullptr);

    static RenderHelper* GetRenderHelper(const char* title, int width, int height, bool fullscreen);
private:
    static RenderHelper m_RenderHelper;
    GameLog logger;
    std::string m_sName;
    SDL_Renderer* m_cRenderer;
    SDL_Window* m_cWindow;
    int m_iWindowHeight;
    int m_iWindowWidth;
    bool m_bFullscreen;
    int m_iPreviousWindowWidth;
    int m_iPreviousWindowHeight;
};
