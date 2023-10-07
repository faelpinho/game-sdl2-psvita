#ifndef SDL_WRAP_HPP
#define SDL_WRAP_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

class SDLWrap {
public:
    SDLWrap()
    {
        gWindow = NULL;
        gRenderer = NULL;
    }

    bool initSDL(uint16_t screen_width, uint16_t screen_height);
    void destroy();
    void clearScreen();
    void fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b);
    SDL_Surface* loadImage(const char* path);

    SDL_Window* gWindow;

    /** Similar ao tipo Canvas2DContext (Javascript) ou Arduino_ST7735 (Arduino) */
    SDL_Renderer* gRenderer;
};

#endif
