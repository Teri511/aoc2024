/*****************************************************************************
 * Name: lib/joypad.h
 * Desc: holds commonly used static values and offsets pertaining to joypad
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef ASM_JOYPAD_H
#define ASM_JOYPAD_H

//Joypad byte location
#define JOY_MASK 0x03FF
#define JOY_A    0x0001
#define JOY_B    0x0002
#define JOY_SEL  0x0004
#define JOY_SRT  0x0008
#define JOY_RT   0x0010
#define JOY_LF   0x0020
#define JOY_UP   0x0040
#define JOY_DN   0x0080
#define JOY_R    0x0100
#define JOY_L    0x0200

#define JOY_KEYCNT_IRE      0x4000
#define JOY_KEYCNT_IRQ_AND  0x8000

//I/O register offsets
#define KEYINPUT_OFFSET 0x0130
#define KEYCNT_OFFSET   0x0132

#endif
