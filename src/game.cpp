#include "game.hpp"
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <stdbool.h>
#include <stdint.h>

void Game::init()
{
    // player.Texture = IMG_LoadTexture(gfx.gRenderer, "app0:/res/teste.png");
    reset();
    int MW = 30;
    int NH = 17;
}

void Game::reset()
{
    engine.currentTime = 0;

    score = 0;
    currentSize = 5;

    // player reset
    player->X = player->Y = 100;
    player->Velocity = 1;
    player->LastDirection = Directions::RIGHT;
}

void Game::handleInputs()
{
    sceCtrlPeekBufferPositive(0, &ctrl, 1);

    if (ctrl.buttons & SCE_CTRL_START) {
        isRunning = false;
    }

    if (ctrl.buttons & SCE_CTRL_UP)
        player->LastDirection = Directions::UP;

    if (ctrl.buttons & SCE_CTRL_DOWN)
        player->LastDirection = Directions::DOWN;

    if (ctrl.buttons & SCE_CTRL_LEFT)
        player->LastDirection = Directions::LEFT;

    if (ctrl.buttons & SCE_CTRL_RIGHT)
        player->LastDirection = Directions::RIGHT;

    if (ctrl.buttons & SCE_CTRL_LTRIGGER) {
        player->Velocity -= 1;
    }

    if (ctrl.buttons & SCE_CTRL_RTRIGGER) {
        player->Velocity += 1;
    }

    if (ctrl.buttons & SCE_CTRL_CIRCLE) {
        reset();
    }

    if (ctrl.buttons & SCE_CTRL_SQUARE) {
        // player.randColor();
    }
}

void Game::movePlayer(Directions currentDirection)
{
    player->LastDirection = currentDirection;

    if (currentDirection == Directions::UP)
        player[0].Y += -1 * player[0].Velocity;

    if (currentDirection == Directions::DOWN)
        player[0].Y += +1 * player[0].Velocity;

    if (currentDirection == Directions::LEFT)
        player[0].X += -1 * player[0].Velocity;

    if (currentDirection == Directions::RIGHT)
        player[0].X += +1 * player[0].Velocity;
}

void Game::handleLogic()
{
    // update player tail
    for (int i = currentSize; i > 0; --i) {
        player[i].X = player[i - 1].X;
        player[i].Y = player[i - 1].Y;
    }

    // move player, dah
    movePlayer(player->LastDirection);

    // get fruit and add new
    if ((player[0].X == fruit.X) && (player[0].Y == fruit.Y)) {
        currentSize++;
        fruit.X = rand() % MW;
        fruit.Y = rand() % NH;
    }

    // turn the screen
    if (player[0].X > MW)
        player[0].X = 0;

    if (player[0].X < 0)
        player[0].X = MW;

    if (player[0].Y > NH)
        player[0].Y = 0;

    if (player[0].Y < 0)
        player[0].Y = NH;

    // add player size
    for (int i = 1; i < currentSize; i++) {
        if (player[0].X == player[i].X && player[0].Y == player[i].Y)
            currentSize = i;
    }
}

void Game::handleGraphics()
{
    // TODO: toda logica de tamanho 32 deve ser aplicada somente aqui!
    // cenario
    for (int i = 0; i < VITA_SCREEN_WIDTH / 32; i++) {
        for (int j = 0; j < VITA_SCREEN_HEIGHT / 32; j++) {
            gfx.fillRect(i * 32, j * 32, player->W, player->H, 50, 50, 50);
        }
    }

    // player
    for (int i = 0; i < currentSize; i++) {
        if (i == 0)
            gfx.fillRect(
                player[0].X * 32, player[0].Y * 32, player->W, player->H, 150, 50, 50); // cabeça vermelha
        else
            gfx.fillRect(
                player[i].X * 32, player[i].Y * 32, player->W, player->H, 50, 150, 50); // calda verde
    }

    // fruta
    gfx.fillRect(fruit.X, fruit.Y, fruit.W, fruit.H, 50, 50, 150);

    // TODO: colocar pontuação em algum lugar da tela.
}
