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
@ Name: radix_sort
@ Desc: A basic and rough implementation of LSB Radix sort
@ Note: This is designed to sort in place, not return an address of a seperate,
@       sorted list
@  I/O: r0: I/O : Address of the list to sort
@       r1: I   : Address of free RAM to work with
@       r2: I   : Number of items in the list

radix_sort:
    STMFD SP!, {r3-r12, lr}
    @ there are 32 bits, so get ready to rotate 32 times
    @ r3: current offset
    @ r4: count, max 32
    @ r5: offset to next 0 location
    @ r6: offset to next temp 1 location
    @ r7: value to work with
    MOV r4, #0
    @ Too lazy, jsut store len * for in some unused register for later
    MOV r8, #4
    MUL r8, r8, r2

top_of_list:
    MOV r3, #0
    MOV r5, #0
    MOV r6, #0

start_comparing:
    LDR r7, [r0, r3]
    ROR r7, r7, r4
    AND r7, #1

    CMP r7, #0
    LDR r7, [r0, r3]
    STREQ r7, [r0, r5]
    ADDEQ r5, r5, #4
    STRNE r7, [r1, r6]
    ADDNE r6, r6, #4

    ADD r3, r3, #4
    CMP r3, r8
    BLT start_comparing

    # if the 1 list is empty, dont bother and just start the next loop
    CMP r6, #0
    BEQ exit_check

    @ Zipper the 2 lists together here
    MOV r9, #0
cont_zippering:
    LDR r7, [r1, r9]
    STR r7, [r0, r5]
    ADD r5, r5, #4
    ADD r9, r9, #4
    CMP r5, r8
    BLT cont_zippering
exit_check:
    ADD r4, r4, #1
    CMP r4, #32
    BLT top_of_list


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

        BL radix_sort

        LDMFD SP!, {r3-r12, lr}
		BX lr