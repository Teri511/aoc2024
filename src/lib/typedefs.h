
/*****************************************************************************
 * Name: lib/typedefs.h
 * Desc: holds commonly used typedefs and macros to make programming for the
 *       GBA easier
 * Author: Will Martens
 */

#ifndef TYPEDEF_H
#define TYPEDEF_H

//TODO: Why? All I saw was "interrupts are handled by arm specific code"
#define ARM __attribute__((__target__("arm")))
//this is for structs, to ensure they are aligned to a certain
#define ALIGN(n) __attribute__((aligned(n)))

//GBA toolchain doesn't have a clue what uint8-32 are, quick typedef here
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;

//set up a fnpointer typedef because C stuff I still don't fully get
typedef void (*fnpointer)(void);

#endif