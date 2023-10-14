#include "common.hpp"
#include <psp2/kernel/processmgr.h>

/** Delay em segundos */
void delay(uint16_t segundos) { sceKernelDelayThread(segundos * 1000 * 1000); }

/** Delay em milisegundos */
void delayMiliseconds(uint16_t milisegundos) { sceKernelDelayThread(milisegundos * 1000); }

/** Delay em microsegundos */
void delayMicroseconds(uint16_t microsegundos) { sceKernelDelayThread(microsegundos); }
