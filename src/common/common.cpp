#include "common.hpp"
#include <psp2/kernel/processmgr.h>

/** Delay em segundos */
void delay(uint16_t tempo) { sceKernelDelayThread(tempo * 1000 * 1000); }

/** Delay em milisegundos */
void delayMiliseconds(uint16_t tempo) { sceKernelDelayThread(tempo * 1000); }

/** Delay em microsegundos */
void delayMicroseconds(uint16_t tempo) { sceKernelDelayThread(tempo); }
