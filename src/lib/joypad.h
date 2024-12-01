/*****************************************************************************
 * Name: lib/joypad.h
 * Desc: holds commonly used structs and pointers pertaining to the joypad
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef JOYPAD_H
#define JOYPAD_H

#include "asm/joypad.h"

//Pre-dereferenced registers
#define REG_KEYINPUT *((volatile uint16 *)(IO_REG_BASE + KEYINPUT_OFFSET))
#define REG_KEYCNT   *((volatile uint16 *)(IO_REG_BASE + KEYCNT_OFFSET))


#endif
