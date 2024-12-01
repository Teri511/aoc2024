/*****************************************************************************
 * Name: lib/asm/disp.h
 * Desc: holds commonly used static values and offsets pertaining to the GBA
 *       display
 * Author: Will Martens
 * Credit: NOA AGB Programming Manual
 */

#ifndef ASM_DISP_H
#define ASM_DISP_H

//Common display constants
#define DISP_MODE0 0x00
#define DISP_MODE1 0x01
#define DISP_MODE2 0x02
#define DISP_MODE3 0x03
#define DISP_MODE4 0x04
#define DISP_MODE5 0x05

#define DISP_USE_FB0 0x0000
#define DISP_USE_FB1 0x0010

#define DISP_ALL_HBLK_PROC_OBJ  0x0000
#define DISP_DISP_HBLK_PROC_OBJ 0x0020

#define DISP_2D_OBJ_VRAM_MAP 0x0000
#define DISP_1D_OBJ_VRAM_MAP 0x0040

#define DISP_DISABLE_FORCE_BLANK 0x0000
#define DISP_ENABLE_FORCE_BLANK  0x0080

#define DISP_BG0_ENABLE 0x0100
#define DISP_BG1_ENABLE 0x0200
#define DISP_BG2_ENABLE 0x0400
#define DISP_BG3_ENABLE 0x0800
#define DISP_OBJ_ENABLE 0x1000

#define DISP_SHOW_WIN0    0x2000
#define DISP_SHOW_WIN1    0x4000
#define DISP_SHOW_WIN_OBJ 0x8000

//I/O register offsets
#define DISPCNT_OFFSET  0x00000000
#define DISPSTAT_OFFSET 0x00000004
#define VCOUNT_OFFSET   0x00000006

#define BG0CNT_OFFSET   0x00000008
#define BG1CNT_OFFSET   0x0000000A
#define BG2CNT_OFFSET   0x0000000C
#define BG3CNT_OFFSET   0x0000000E

#define BG0HOFS_OFFSET  0x00000010
#define BG1HOFS_OFFSET  0x00000014
#define BG2HOFS_OFFSET  0x00000018
#define BG3HOFS_OFFSET  0x0000001C

#define BG0VOFS_OFFSET  0x00000012
#define BG1VOFS_OFFSET  0x00000016
#define BG2VOFS_OFFSET  0x0000001A
#define BG3VOFS_OFFSET  0x0000001C

#define BG2PA_OFFSET    0x00000020  //BG Starting Point Register Offsets
#define BG2PB_OFFSET    0x00000022
#define BG2PC_OFFSET    0x00000024
#define BG2PD_OFFSET    0x00000026

#define BG2X_L_OFFSET   0x00000028  //BG Direction Register Offsets
#define BG2X_H_OFFSET   0x0000002A
#define BG2Y_L_OFFSET   0x0000002C
#define BG2Y_H_OFFSET   0x0000002E

#define BG3PA_OFFSET    0x00000030  //BG Starting Point Register Offsets
#define BG3PB_OFFSET    0x00000032
#define BG3PC_OFFSET    0x00000034
#define BG3PD_OFFSET    0x00000036

#define BGX3_L_OFFSET   0x00000038  //BG Direction Register Offsets
#define BGX3_H_OFFSET   0x0000003A
#define BGY3_L_OFFSET   0x0000003C
#define BGY3_H_OFFSET   0x0000003E

#define WAITCNT_OFFSET  0x00000204

#define OBJ_VRAM_OFFSET 0x010000

#define OBJ_PRAM_OFFSET 0x0200
#define BG_PRAM_OFFSET  0x0000

//Various sizes
#define DISP_CHAR_MODE_BG_SZ    0x10000
#define DISP_CHAR_MODE_CHAR_SZ  0x08000

#define DISP_BG_MODE_FULL_FB_SZ 0x14000
#define DISP_BG_MODE_CHAR_SZ    0x04000

#endif