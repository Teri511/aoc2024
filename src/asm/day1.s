@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Name: day1.s
@ Desc: Functions used to solve the AOC day 1 puzzle
@ Author: Will Martens
@


@@@@@@@@@@@@@@
@ Game Logic @
@@@@@@@@@@@@@@

    .TEXT
    .ALIGN
    .ARM
	.GLOBAL day1_entrypoint

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Name: bad_radix_sort
@ Desc: A wildly inefficient rendition of a MSB Radix sort
@ Note: This is designed to sort in place, not return an address of a seperate,
@       sorted list
@  I/O: r0: I/O : Address of the list to sort
@       r1: I   : Address of free RAM to work with
@       r2: I   : Number of items in the list

bad_radix_sort:
    STMFD SP!, {r3-r12, lr}

    STR r1, [r1]

    LDMFD SP!, {r3-r12, lr}
    BX lr

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Name: day1_entrypoint
@ Desc: location to jump into from C land
@  I/O: r0: I   : Location of left column of data to process
@       r1: I   : Location of right column of data to process
@       r2: I   : Number of entries in the dataset

day1_entrypoint:
		STMFD SP!, {r3-r12, lr}

@ Load the left list into RAM
        LDR r3,=0x02000000
        MOV r4, #0
        MOV r5, #0
        MOV r6, #4
left_load_loop:
        MUL r5, r4, r6
        LDR r7, [r0, r5]
        STR r7, [r3, r5]
        ADD r4, #1
        CMP r4, r2
        BLT left_load_loop

@ right list is always (02000000 + length + 1) away
@ Load the right list into RAM
        ADD r5, #4
        ORR r3, r3, r5
        MOV r4, #0
        MOV r5, #0
        MOV r6, #4
right_load_loop:
        MUL r5, r4, r6
        LDR r7, [r1, r5]
        STR r7, [r3, r5]
        ADD r4, #1
        CMP r4, r2
        BLT right_load_loop

@ save off r0-r2 and get ready to call sort on the left list
        MOV r9, r0
        MOV r10, r1

        LDR r0,=0x02000000
        LDR r1,=0x02000000
        ADD r1,r1,r2
        ADD r1,r1,r2
        ADD r1,r1,r2
        ADD r1,r1,r2
        ADD r1,r1,r2
        ADD r1,r1,r2
        ADD r1,r1,r2
        ADD r1,r1,r2

        BL bad_radix_sort

        LDMFD SP!, {r3-r12, lr}
		BX lr