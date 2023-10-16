#include "game.hpp"
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <stdbool.h>
#include <stdint.h>

void Game::init()
{
    // player.Texture = IMG_LoadTexture(gfx.gRenderer, "app0:/res/teste.png");
    reset();
}

void Game::reset()
{
    engine.currentTime = 0;

    score = 0;

    // player reset
    player.X = player.Y = 100;
    player.Direction.X = 0;
    player.Direction.Y = 0;
    player.Velocity = 1;
}

void Game::handleInputs()
{
    sceCtrlPeekBufferPositive(0, &ctrl, 1);

    int directionX = 0;
    int directionY = 0;

    if (ctrl.buttons & SCE_CTRL_START) {
        isRunning = false;
    }

    if (ctrl.buttons & SCE_CTRL_UP) {
        directionY = -1;
    }

    if (ctrl.buttons & SCE_CTRL_DOWN) {
        directionY = 1;
    }

    if (ctrl.buttons & SCE_CTRL_LEFT) {
        directionX = -1;
    }

    if (ctrl.buttons & SCE_CTRL_RIGHT) {
        directionX = 1;
    }

    if (ctrl.buttons & SCE_CTRL_LTRIGGER) {
        player.Velocity -= 1;
    }

    if (ctrl.buttons & SCE_CTRL_RTRIGGER) {
        player.Velocity += 1;
    }

    if (ctrl.buttons & SCE_CTRL_CIRCLE) {
        reset();
    }

    if (ctrl.buttons & SCE_CTRL_SQUARE) {
        // player.randColor();
    }

    // executa
    if (directionX != 0 || directionY != 0)
        movePlayer(directionX, directionY);
}

void Game::movePlayer(int directionX, int directionY)
{
    player.X += directionX * player.Velocity;
    player.Y += directionY * player.Velocity;
}

void Game::handleLogic()
{
    //
    //
    //
}

void Game::handleGraphics()
{
    //
    gfx.fillRect(player.X, player.Y, player.W, player.H, 50, 150, 50);
    // gfx.drawImage(player.X, player.Y, player.W, player.H, player.Texture);
}
