#include "sdl_wrap.hpp"
#include "common.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

bool SDLWrap::initSDL(uint16_t screen_width, uint16_t screen_height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    if ((gWindow = SDL_CreateWindow("MeuHello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
             screen_width, screen_height, SDL_WINDOW_SHOWN))
        == NULL)
        return false;

    if ((gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
        == NULL)
        return false;

    /*
    if ((framebuffer = SDL_CreateTexture(
             gRenderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, screen_width, screen_height))
        == NULL)
        return false;
    */

    return true;
}

void SDLWrap::destroy()
{
    SDL_Delay(100);
    // SDL_DestroyTexture(imageTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    // framebuffer = NULL;
    SDL_Quit();
}

void SDLWrap::clearScreen()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gRenderer);
}

void SDLWrap::fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect fillRect = { x, y, w, h };
    SDL_SetRenderDrawColor(gRenderer, r, g, b, 255);
    SDL_RenderFillRect(gRenderer, &fillRect);
    SDL_RenderPresent(gRenderer);
}

SDL_Surface* SDLWrap::loadImage(const char* path)
{
    SDL_Surface* image = SDL_LoadBMP(path);
    return image;
}
