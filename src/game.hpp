#ifndef GAME_HPP
#define GAME_HPP

#include "engine/common.hpp"
#include "engine/engine.hpp"
#include "engine/graphics.hpp"
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
        uint16_t X = 10;
        uint16_t Y = 10;
        uint16_t W = 50;
        uint16_t H = 50;
        uint8_t Velocity = 1;
        uint8_t R = 100;
        uint8_t G = 0;
        uint8_t B = 0;
        Directions Direction;

        void reset()
        {
            uint16_t X = 50;
            uint16_t Y = 50;
            uint16_t W = 20;
            uint16_t H = 20;
            uint8_t Velocity = 1;
            uint8_t R = 100;
            uint8_t G = 0;
            uint8_t B = 0;
        }

        void randColor()
        {
            int randValueR = (rand() % 5) * 50;
            int randValueG = (rand() % 5) * 50;
            int randValueB = (rand() % 5) * 50;

            R = randValueR;
            G = randValueG;
            B = randValueB;
        }
    } Player;

    // =======
    // Métodos
    // =======

    void reset();
    void handleInputs();
    void handleLogic();
    void handleGraphics();
    void movePlayer(Directions direction);
};

#endif
