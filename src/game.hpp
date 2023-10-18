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
    Game()
    {
        Engine engine = Engine();
        Graphics gfx = Graphics();
    };

    Graphics gfx;
    Engine engine;
    SceCtrlData ctrl;

    bool isRunning = true;

    int score;
    int currentSize;
    int MW;
    int NH;

    // =======
    // Structs
    // =======

    enum Directions {
        STOPPED = 0,
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4,
    };

    struct Player {
        uint16_t X = 4;
        uint16_t Y = 4;
        uint16_t W = 32;
        uint16_t H = 32;
        uint8_t Velocity = 1;
        Directions LastDirection = Directions::STOPPED;
        SDL_Texture* Texture = NULL;
    } player[50];

    struct Fruit {
        uint16_t X = 4;
        uint16_t Y = 4;
        uint16_t W = 32;
        uint16_t H = 32;
        int8_t Timer = -1;
        SDL_Texture* Texture = NULL;
    } fruit;

    // =======
    // Methods
    // =======

    void init();
    void reset();
    void handleInputs();
    void handleLogic();
    void handleGraphics();
    void movePlayer(Directions currentDirection);
};

#endif
