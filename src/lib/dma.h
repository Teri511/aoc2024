/*****************************************************************************
 * Name: lib/dma.h
 * Desc: holds commonly used structs and pointers pertaining to DMA tranfers
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef DMA_H
#define DMA_H

#include "asm/dma.h"

//Macros
//DMA only does up to 27 bits for the source/dest addr
#define DMA_ADDR_LOW(n)  ((uint32)(n) & 0x0000FFFFu)
#define DMA0_ADDR_HIGH(n) (((uint32)(n) & 0x07FF0000u) >> 16)
#define DMA1_ADDR_HIGH(n) (((uint32)(n) & 0x0FFF0000u) >> 16)

//Pre-dereferenced registers
#define REG_DMA0_SAD_L *((volatile uint16 *)(IO_REG_BASE + DMA0_SAD_L_OFFSET))
#define REG_DMA0_SAD_H *((volatile uint16 *)(IO_REG_BASE + DMA0_SAD_H_OFFSET))
#define REG_DMA0_DAD_L *((volatile uint16 *)(IO_REG_BASE + DMA0_DAD_L_OFFSET))
#define REG_DMA0_DAD_H *((volatile uint16 *)(IO_REG_BASE + DMA0_DAD_H_OFFSET))
#define REG_DMA0_CNT_L *((volatile uint16 *)(IO_REG_BASE + DMA0_CNT_L_OFFSET))
#define REG_DMA0_CNT_H *((volatile uint16 *)(IO_REG_BASE + DMA0_CNT_H_OFFSET))

#define REG_DMA1_SAD_L *((volatile uint16 *)(IO_REG_BASE + DMA1_SAD_L_OFFSET))
#define REG_DMA1_SAD_H *((volatile uint16 *)(IO_REG_BASE + DMA1_SAD_H_OFFSET))
#define REG_DMA1_DAD_L *((volatile uint16 *)(IO_REG_BASE + DMA1_DAD_L_OFFSET))
#define REG_DMA1_DAD_H *((volatile uint16 *)(IO_REG_BASE + DMA1_DAD_H_OFFSET))
#define REG_DMA1_CNT_L *((volatile uint16 *)(IO_REG_BASE + DMA1_CNT_L_OFFSET))
#define REG_DMA1_CNT_H *((volatile uint16 *)(IO_REG_BASE + DMA1_CNT_H_OFFSET))

#define REG_DMA2_SAD_L *((volatile uint16 *)(IO_REG_BASE + DMA2_SAD_L_OFFSET))
#define REG_DMA2_SAD_H *((volatile uint16 *)(IO_REG_BASE + DMA2_SAD_H_OFFSET))
#define REG_DMA2_DAD_L *((volatile uint16 *)(IO_REG_BASE + DMA2_DAD_L_OFFSET))
#define REG_DMA2_DAD_H *((volatile uint16 *)(IO_REG_BASE + DMA2_DAD_H_OFFSET))
#define REG_DMA2_CNT_L *((volatile uint16 *)(IO_REG_BASE + DMA2_CNT_L_OFFSET))
#define REG_DMA2_CNT_H *((volatile uint16 *)(IO_REG_BASE + DMA2_CNT_H_OFFSET))

#define REG_DMA3_SAD_L *((volatile uint16 *)(IO_REG_BASE + DMA3_SAD_L_OFFSET))
#define REG_DMA3_SAD_H *((volatile uint16 *)(IO_REG_BASE + DMA3_SAD_H_OFFSET))
#define REG_DMA3_DAD_L *((volatile uint16 *)(IO_REG_BASE + DMA3_DAD_L_OFFSET))
#define REG_DMA3_DAD_H *((volatile uint16 *)(IO_REG_BASE + DMA3_DAD_H_OFFSET))
#define REG_DMA3_CNT_L *((volatile uint16 *)(IO_REG_BASE + DMA3_CNT_L_OFFSET))
#define REG_DMA3_CNT_H *((volatile uint16 *)(IO_REG_BASE + DMA3_CNT_H_OFFSET))

#endif

