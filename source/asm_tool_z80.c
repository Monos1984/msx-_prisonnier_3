#include "header\game.h"

unsigned char regR;

void getR()
{
__asm
    LD HL, #_regR
    LD A, R
    LD (HL), A
__endasm;    
}