/******************************************************************************
 * Name: main.c
 * Desc: Entrypoint for GBA Program
 * Note: This can be replaced with whatever you like, provided both an AgbMain 
 *       and InterruptProcess function are provided 
 */

#include "lib/asm/base_addr.h"
#include "lib/typedefs.h"
#include "lib/disp.h"
#include "lib/joypad.h"
#include "lib/interrupts.h"
#include "lib/dma.h"
#include "lib/timers.h"

ARM void InterruptProcess(){
	return;
}

int AgbMain(){
	return 0;
}
