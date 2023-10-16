#ifndef GAME_HPP
#define GAME_HPP

#include "engine/common.hpp"
#include "engine/engine.hpp"
#include "engine/graphics.hpp"
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <stdbool.h>
#include <stdint.h>

class Game {
public:
    Game(uint32_t skipTicks, uint32_t maxFrameskip)
    {
        Engine engine = Engine();
        Graphics gfx = Graphics();

        engine.skipTicks = skipTicks;
        engine.maxFrameskip = maxFrameskip;
    };

    Graphics gfx;
    Engine engine;
    SceCtrlData ctrl;

    bool isRunning = true;

    int score;

    // =======
    // Structs
    // =======

    struct Directions {
        int16_t X = 0;
        int16_t Y = 0;
    } Direction;

    struct Player {
        uint16_t X = 100;
        uint16_t Y = 100;
        uint16_t W = 20;
        uint16_t H = 20;
        uint8_t Velocity = 1;
        Directions Direction;
        SDL_Texture* Texture = NULL;
    } player;

    // =======
    // Methods
    // =======

    void init();
    void reset();
    void handleInputs();
    void handleLogic();
    void handleGraphics();
    void movePlayer(int directionX, int directionY);
};

#endif
