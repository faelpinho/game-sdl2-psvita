#include "graphics.hpp"
#include "common.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

bool Graphics::init(uint16_t screen_width, uint16_t screen_height)
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

void Graphics::destroy()
{
    // SDL_DestroyTexture(imageTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    // framebuffer = NULL;
    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

void Graphics::clearScreen()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gRenderer);
}

void Graphics::render()
{
    //
    SDL_RenderPresent(gRenderer);
}

void Graphics::fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b)
{
    SDL_Rect fillRect = { x, y, w, h };
    SDL_SetRenderDrawColor(gRenderer, r, g, b, 255);
    SDL_RenderFillRect(gRenderer, &fillRect);
}

void Graphics::drawImage(int x, int y, int w, int h, SDL_Texture* texture)
{
    SDL_Rect imagePos = { x, y, w, h };
    SDL_RenderCopy(gRenderer, texture, NULL, &imagePos);
}
