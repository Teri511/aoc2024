/*****************************************************************************
 * Name: lib/interrupts.h
 * Desc: holds commonly used static values and offsets pertaining to the GBA
 *       interrupt handler
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef ASM_INTERRUPTS_H
#define ASM_INTERRUPTS_H

#define IRQ_TYPE_VBLANK 0x0001
#define IRQ_TYPE_HBLANK 0x0002
#define IRQ_TYPE_VCOUNT 0x0004
#define IRQ_TYPE_TIMER0 0x0008
#define IRQ_TYPE_TIMER1 0x0010
#define IRQ_TYPE_TIMER2 0x0020
#define IRQ_TYPE_TIMER3 0x0040
#define IRQ_TYPE_SERIAL 0x0080
#define IRQ_TYPE_DMA0   0x0100
#define IRQ_TYPE_DMA1   0x0200
#define IRQ_TYPE_DMA2   0x0400
#define IRQ_TYPE_DMA3   0x0800
#define IRQ_TYPE_KEY    0x1000
#define IRQ_TYPE_GPAK   0x2000

//I/O register offset
#define IRQ_ENABLE_MASTER_OFFSET 0x0208
#define IRQ_ENABLE_OFFSET        0x0200
#define IRQ_REQUEST_OFFSET       0x0202
#define IRQ_INT_HANDLER_OFFSET   0x7FFC

#endif