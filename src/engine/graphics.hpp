#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

class Graphics {
public:
    Graphics()
    {
        gWindow = NULL;
        gRenderer = NULL;
    }

    SDL_Window* gWindow;

    /** Similar ao tipo Canvas2DContext (Javascript) ou Arduino_ST7735 (Arduino) */
    SDL_Renderer* gRenderer;

    // =======
    // Methods
    // =======
    bool init(uint16_t screen_width, uint16_t screen_height);
    void destroy();
    void clearScreen();
    void render();
    void fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b);
    void drawImage(int x, int y, int w, int h, SDL_Texture* texture);
};

#endif
