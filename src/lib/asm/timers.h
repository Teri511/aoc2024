/*****************************************************************************
 * Name: lib/timers.h
 * Desc: holds commonly used static values and offsets pertaining to the GBA
 *       timers
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef ASM_TIMERS_H
#define ASM_TIMERS_H

//common constants

//I/O register offsets
#define TM_TICK_EVERY_CLOCK      0x00
#define TM_TICK_64_CLOCKS        0x01
#define TM_TICK_256_CLOCKS       0x02
#define TM_TICK_1024_CLOCKS      0x03

#define TM_USE_COUNT_INTERVAL    0x04
#define TM_IGNORE_COUNT_INTERVAL 0x00

#define TM_IRQ_REQ_FLAG          0x40
#define TM_ENABLE                0x80

//NOTE: Timers 0 and 1 are used for the FIFOs for direct sound streams A and B
//NOTE: Low is the count, high is settings
#define TM0CNT_L_OFFSET          0x0100
#define TM0CNT_H_OFFSET          0x0102
#define TM1CNT_L_OFFSET          0x0104
#define TM1CNT_H_OFFSET          0x0106
#define TM2CNT_L_OFFSET          0x0108
#define TM2CNT_H_OFFSET          0x010A
#define TM3CNT_L_OFFSET          0x010C
#define TM3CNT_H_OFFSET          0x010E

#endif