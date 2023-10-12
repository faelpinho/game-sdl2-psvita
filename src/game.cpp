#include "game.hpp"
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <stdbool.h>
#include <stdint.h>

void Game::reset()
{
    engine.currentTime = 0;

    Player.reset();
    score = 0;
}

void Game::handleInputs()
{
    sceCtrlPeekBufferPositive(0, &ctrl, 1);

    Player.Direction.X = 0;
    Player.Direction.Y = 0;

    if (ctrl.buttons & SCE_CTRL_START) {
        isRunning = false;
    }

    if (ctrl.buttons & SCE_CTRL_UP) {
        Player.Direction.Y = -1;
    }

    if (ctrl.buttons & SCE_CTRL_DOWN) {
        Player.Direction.Y = 1;
    }

    if (ctrl.buttons & SCE_CTRL_LEFT) {
        Player.Direction.X = -1;
    }

    if (ctrl.buttons & SCE_CTRL_RIGHT) {
        Player.Direction.X = 1;
    }

    if (ctrl.buttons & SCE_CTRL_LTRIGGER) {
        Player.Velocity -= 1;
    }

    if (ctrl.buttons & SCE_CTRL_RTRIGGER) {
        Player.Velocity += 1;
    }

    if (ctrl.buttons & SCE_CTRL_CIRCLE) {
        Player.X = Player.Y = 0;
    }

    if (ctrl.buttons & SCE_CTRL_SQUARE) {
        Player.randColor();
    }

    // executa
    if (Player.Direction.X != 0 || Player.Direction.Y != 0) {
        movePlayer(Player.Direction);
    }
}

void Game::movePlayer(Directions direction)
{
    Player.X += direction.X * Player.Velocity;
    Player.Y += direction.Y * Player.Velocity;
}

void Game::handleLogic()
{
    //
    //
    //
}

void Game::handleGraphics()
{
    gfx.clearScreen();
    //

    gfx.fillRect(Player.X, Player.Y, 20, 20, Player.R, Player.G, Player.B);
}
