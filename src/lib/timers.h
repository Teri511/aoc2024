/*****************************************************************************
 * Name: lib/timers.h
 * Desc: holds commonly used structs and pointers pertaining to the GBA's
 *       timers
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef TIMERS_H
#define TIMERS_H

#include "asm/timers.h"

#define REG_TM0CNT_L *((volatile uint16 *)(IO_REG_BASE + TM0CNT_L_OFFSET))
#define REG_TM0CNT_H *((volatile uint16 *)(IO_REG_BASE + TM0CNT_H_OFFSET))
#define REG_TM1CNT_L *((volatile uint16 *)(IO_REG_BASE + TM1CNT_L_OFFSET))
#define REG_TM1CNT_H *((volatile uint16 *)(IO_REG_BASE + TM1CNT_H_OFFSET))
#define REG_TM2CNT_L *((volatile uint16 *)(IO_REG_BASE + TM2CNT_L_OFFSET))
#define REG_TM2CNT_H *((volatile uint16 *)(IO_REG_BASE + TM2CNT_H_OFFSET))
#define REG_TM3CNT_L *((volatile uint16 *)(IO_REG_BASE + TM3CNT_L_OFFSET))
#define REG_TM3CNT_H *((volatile uint16 *)(IO_REG_BASE + TM3CNT_H_OFFSET))

#endif