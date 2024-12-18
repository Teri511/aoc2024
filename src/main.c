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

//PUZZLE DATA
#include "puzzle_data/day1/left_data.h"
#include "puzzle_data/day1/right_data.h"

struct basic_answer {
	int part1;
	int part2;
};

// EXTERNAL ASM FUNCTIONS
extern struct basic_answer* day1_entrypoint(const unsigned int* ptr_left, const unsigned int* ptr_right, uint16 count);
extern struct basic_answer* day2_entrypoint(const unsigned char* ptr_list);

ARM void InterruptProcess(){
	return;
}

int AgbMain(){
	uint16 len = left_list_len;
	struct basic_answer* answer = day1_entrypoint(left_list,right_list,len);
	while(0==0){
		;;
	}
	return 0;
}
