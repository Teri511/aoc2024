/*****************************************************************************
 * Name: lib/disp.h
 * Desc: holds commonly used static values and addresses pertaining to the GBA
 *       display
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef DISP_H
#define DISP_H

#include "asm/disp.h"

//Useful structs and globals
/* NOTE:
 * Character Name [attr2 bits 00 - 09] is a misleading title, its actually 
 * what section in OBJ VRAM to grab sprite data from. In 1D mode, it 
 * increments the pointer to OBJ VRAM by 0x20 each step
 * 
 * The GBA renders everything, so if you dont point the unused OAM entries'
 * Character Names to some blank spot in OBJ memory, you'll end up with 
 * garbage in the top right of the screen
 */
struct OAM_attributes {
    uint16 attr0;
    uint16 attr1;
    uint16 attr2;
    uint16 pad;
} ALIGN(4);

//4 char blocks, 32 screen blocks
#define VRAM_CHAR_BLOCK_ADDR(n)   (VRAM_BASE + (0x4000 * n))
#define VRAM_SCREEN_BLOCK_ADDR(n) (VRAM_BASE + (0x0800 * n))

//Pre-dereferenced registers
#define REG_DISPCNT  *((volatile uint16 *)(IO_REG_BASE + DISPCNT_OFFSET))
#define REG_DISPSTAT *((volatile uint16 *)(IO_REG_BASE + DISPSTAT_OFFSET))
#define REG_VCOUNT   *((volatile uint16 *)(IO_REG_BASE + VCOUNT_OFFSET))
#define REG_BG0CNT   *((volatile uint16 *)(IO_REG_BASE + BG0CNT_OFFSET))
#define REG_BG1CNT   *((volatile uint16 *)(IO_REG_BASE + BG1CNT_OFFSET))
#define REG_BG2CNT   *((volatile uint16 *)(IO_REG_BASE + BG2CNT_OFFSET))
#define REG_BG3CNT   *((volatile uint16 *)(IO_REG_BASE + BG3CNT_OFFSET))
#define REG_WAITCNT  *((volatile uint16 *)(IO_REG_BASE + WAITCNT_OFFSET))


#define REG_BG0HOFS  *((volatile uint16 *)(IO_REG_BASE + BG0HOFS_OFFSET))
#define REG_BG1HOFS  *((volatile uint16 *)(IO_REG_BASE + BG1HOFS_OFFSET))
#define REG_BG2HOFS  *((volatile uint16 *)(IO_REG_BASE + BG2HOFS_OFFSET))
#define REG_BG3HOFS  *((volatile uint16 *)(IO_REG_BASE + BG3HOFS_OFFSET))

#define REG_BG0VOFS  *((volatile uint16 *)(IO_REG_BASE + BG0VOFS_OFFSET))
#define REG_BG1VOFS  *((volatile uint16 *)(IO_REG_BASE + BG1VOFS_OFFSET))
#define REG_BG2VOFS  *((volatile uint16 *)(IO_REG_BASE + BG2VOFS_OFFSET))
#define REG_BG3VOFS  *((volatile uint16 *)(IO_REG_BASE + BG3VOFS_OFFSET))

#define PRAM_OBJ_ADDR (PRAM_BASE + OBJ_PRAM_OFFSET)
#define PRAM_BG_ADDR (PRAM_BASE + BG_PRAM_OFFSET)

#define VRAM_OBJ_ADDR (VRAM_BASE + OBJ_VRAM_OFFSET)

//#define PRAM_OBJ(n) *((volatile uint32 *)(PRAM_OBJ_ADDR + (0x0010 * n)))
//#define PRAM_BG(n)  *((volatile uint32 *)(PRAM_BG_ADDR + (0x0010 * n)))
#define PRAM_OBJ(n) (PRAM_OBJ_ADDR + (0x0020 * n))
#define PRAM_BG(n)  (PRAM_BG_ADDR + (0x0020 * n))
#define OAM_LOC(n) (OAM_BASE + (0x0040 * n))

#define VRAM_OBJ *((volatile uint32 *)(VRAM_OBJ_ADDR))

#endif