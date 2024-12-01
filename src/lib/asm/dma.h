/*****************************************************************************
 * Name: lib/asm/dma.h
 * Desc: holds commonly used static values and offsets pertaining to DMA 
 *       transfer
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef ASM_DMA_H
#define ASM_DMA_H

//I/O register offsets

//DMA0 is only RAM to RAM, can't do cart to RAM. Highest priority
#define DMA0_SAD_L_OFFSET 0x00B0
#define DMA0_SAD_H_OFFSET 0x00B2
#define DMA0_DAD_L_OFFSET 0x00B4
#define DMA0_DAD_H_OFFSET 0x00B6
#define DMA0_CNT_L_OFFSET 0x00B8
#define DMA0_CNT_H_OFFSET 0x00BA

//DMA1 and DAM2 can copy from anywhere to RAM, including the direct sound FIFO
#define DMA1_SAD_L_OFFSET 0x00BC
#define DMA1_SAD_H_OFFSET 0x00BE
#define DMA1_DAD_L_OFFSET 0x00C0
#define DMA1_DAD_H_OFFSET 0x00C2
#define DMA1_CNT_L_OFFSET 0x00C4
#define DMA1_CNT_H_OFFSET 0x00C6

#define DMA2_SAD_L_OFFSET 0x00C8
#define DMA2_SAD_H_OFFSET 0x00CA
#define DMA2_DAD_L_OFFSET 0x00CC
#define DMA2_DAD_H_OFFSET 0x00CE
#define DMA2_CNT_L_OFFSET 0x00D0
#define DMA2_CNT_H_OFFSET 0x00D2

//DMA1 and DAM2 can copy from anywhere to RAM. Lowest priority
#define DMA3_SAD_L_OFFSET 0x00D4
#define DMA3_SAD_H_OFFSET 0x00D6
#define DMA3_DAD_L_OFFSET 0x00D8
#define DMA3_DAD_H_OFFSET 0x00DA
#define DMA3_CNT_L_OFFSET 0x00DC
#define DMA3_CNT_H_OFFSET 0x00DE

#endif