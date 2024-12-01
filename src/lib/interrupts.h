/*****************************************************************************
 * Name: lib/interrupts.h
 * Desc: holds commonly used structs and pointers pertaining to the GBA
 *       interrupt handler
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "asm/interrupts.h"

//Pre-dereferenced registers
#define REG_IRQ_ENABLE_MASTER *((volatile uint16 *)(IO_REG_BASE + IRQ_ENABLE_MASTER_OFFSET))
#define REG_IRQ_ENABLE        *((volatile uint16 *)(IO_REG_BASE + IRQ_ENABLE_OFFSET))
#define REG_IRQ_REQUEST       *((volatile uint16 *)(IO_REG_BASE + IRQ_REQUEST_OFFSET))
#define REG_IRQ_HANDLER_LOC   *((volatile fnpointer *)(CPU_IWRAM_BASE + IRQ_INT_HANDLER_OFFSET))


#endif