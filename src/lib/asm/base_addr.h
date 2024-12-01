/*****************************************************************************
 * Name: lib/asm/base_addr.h
 * Desc: holds base addresses and sizes for common memory locations on the GBA
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef BASE_ADDR_H
#define BASE_ADDR_H

// common memory locations & sizes

// CPU External Work RAM
#define CPU_EWRAM_BASE  0x02000000
#define CPU_EWRAM_SZ    0x00400000
// CPU Internal Work RAM
#define CPU_IWRAM_BASE  0x03000000
#define CPU_IRAM_SZ     0x00008000

// I/O Register Base Address
#define IO_REG_BASE     0x04000000

// Palette RAM
#define PRAM_BASE       0x05000000
#define PRAM_SZ         0x00000400

// VRAM
#define VRAM_BASE       0x06000000
#define VRAM_SZ         0x00018000

// Object Attribute Memory (OAM)
#define OAM_BASE        0x07000000
#define OAM_SZ          0x000003FF  //yes, its 0x3FF not 0x400

// Game Pak ROM Wait State 0
#define PAK_ROM_0_BASE        0x08000000
#define PAK_ROM_0_SRAM_OFFSET 0x01FDFFFF
#define PAK_ROM_0_SZ          0x01FFFFFF

// Game Pak ROM Wait State 1
#define PAK_ROM_1_BASE        0x0A000000
#define PAK_ROM_1_SRAM_OFFSET 0x00100000
#define PAK_ROM_1_SZ          0x01FFFFFF

// Game Pak ROM Wait State 2
#define PAK_ROM_2_BASE        0x0C000000
#define PAK_ROM_2_SRAM_OFFSET 0x00100000
#define PAK_ROM_2_SZ          0x01FFFFFF

// Game Pak RAM
#define PAK_RAM_BASE    0x0E000000
#define PAK_RAM_SZ      0x0000FFFF

#endif