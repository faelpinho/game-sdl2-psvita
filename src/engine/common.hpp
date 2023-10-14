#ifndef COMMON_HPP
#define COMMON_HPP

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <psp2common/ctrl.h>
#include <stdbool.h>
#include <stdint.h>

// screen size
enum { VITA_SCREEN_WIDTH = 960, VITA_SCREEN_HEIGHT = 544 };

// delay funcs
void delay(uint16_t segundos);
void delayMiliseconds(uint16_t milisegundos);
void delayMicroseconds(uint16_t microsegundos);

#endif
