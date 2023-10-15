#include "game.hpp"
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <stdbool.h>
#include <stdint.h>

void Game::init()
{
    reset();
    player.Texture = IMG_LoadTexture(gfx.gRenderer, "app0:/res/teste.png");
}

void Game::reset()
{
    engine.currentTime = 0;

    score = 0;

    player.reset();
}

void Game::handleInputs()
{
    sceCtrlPeekBufferPositive(0, &ctrl, 1);

    player.Direction.X = 0;
    player.Direction.Y = 0;

    if (ctrl.buttons & SCE_CTRL_START) {
        isRunning = false;
    }

    if (ctrl.buttons & SCE_CTRL_UP) {
        player.Direction.Y = -1;
    }

    if (ctrl.buttons & SCE_CTRL_DOWN) {
        player.Direction.Y = 1;
    }

    if (ctrl.buttons & SCE_CTRL_LEFT) {
        player.Direction.X = -1;
    }

    if (ctrl.buttons & SCE_CTRL_RIGHT) {
        player.Direction.X = 1;
    }

    if (ctrl.buttons & SCE_CTRL_LTRIGGER) {
        player.Velocity -= 1;
    }

    if (ctrl.buttons & SCE_CTRL_RTRIGGER) {
        player.Velocity += 1;
    }

    if (ctrl.buttons & SCE_CTRL_CIRCLE) {
        player.X = player.Y = 0;
    }

    if (ctrl.buttons & SCE_CTRL_SQUARE) {
        // player.randColor();
    }

    // executa
    if (player.Direction.X != 0 || player.Direction.Y != 0) {
        movePlayer(player.Direction);
    }
}

void Game::movePlayer(Directions direction)
{
    player.X += direction.X * player.Velocity;
    player.Y += direction.Y * player.Velocity;
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

/*
void Game::renderPlayer(int x, int y, int w, int h, SDL_Texture* texture)
{
    SDL_Rect imagePos = { x, y, w, h };
    SDL_RenderCopy(gfx.gRenderer, texture, NULL, &imagePos);
}
*/
