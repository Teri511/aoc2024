@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Name: day1.s
@ Desc: Functions used to solve the AOC day 1 puzzle
@ Author: Will Martens
@

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
    @ Too lazy, just store len * for in some unused register for later
    MOV r8, #4
    MUL r8, r2, r8

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

@ save off r0-r1 and get ready to call sort on the left list
    MOV r9, r0
    MOV r10, r1

    LDR r0,=0x02000000
    LDR r1,=0x02000000
@ TODO: really, 8 add instructions.... Clean this up
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2

    BL radix_sort

@ left list should be sorted, on to right list
@ reuse the same scrap RAM
    MOV r1, #4
    MUL r1, r2, r1
    ADD r0, r0, r1
    LDR r1, =0x02000000
@ TODO: really, 8 add instructions.... Clean this up
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2
    ADD r1,r1,r2

    BL radix_sort



@ both lists are now sorted, begin comparing
@ r0,r1: current position of left and right respectively
@    r4: count
@    r5: intermediate result
@    r6: l value
@    r7: r value
@    r3: running total, aka final result
@ TODO: theres a more efficient way that uses less instructions and registers
@       figure it out

    LDR r0,=0x02000000    @ r0 OK
    LDR r1,=0x02000000
    MOV r3, #4
    MUL r3, r2, r3
    ADD r1, r1, r3        @ r1 OK
    MOV r3, #0            @ r3 OK
    MOV r4, #0            @ r4 OK
    MOV r5, #0            @ r5 OK

begin_part_1:
    LDR r6, [r0]
    LDR r7, [r1]

    SUBS r5, r6, r7
    MVNLT r5, r5
    ADDLT r5, r5, #1
    ADD r3, r3, r5
    ADD r0, r0, #4
    ADD r1, r1, #4
    ADD r4, r4, #1

    CMP r4, r2
    BLT begin_part_1

@ part 2: instead of doing diffs, count the number of times a number appears in
@         the list and add it up. May run into issues if numbers go past the 32
@         bit limit
@ r0,r1: l and r list addrs
@    r2: Total
@    r3: Answer Part1
@    r4: Answer Part2
@    r5: l val
@    r6: r val
@    r7: l offset
@    r8: r offset
@   r11: encounter count

@ lets temporarily multiply total by 4, that way i can do easier offsetting

    ROR r2, #30
    LDR r0,=0x02000000    @ r0 OK
    LDR r1,=0x02000000
    ADD r1, r1, r2        @ r1 OK
    MOV r4, #0            @ r4 OK
    MOV r7, #0
    MOV r8, #0
    MOV r11, #0

begin_part_2:
    LDR r5, [r0, r7]

top_of_r:
    LDR r6, [r1, r8]
    CMP r5, r6
    ADDEQ r11, r11, #1

    ADD r8, r8, #4
    CMP r8, r2
    BLT top_of_r

    MUL r11, r5, r11
    ADD r4, r4, r11
    MOV r11, #0
    MOV r8, #0
    ADD r7, r7, #4
    CMP r7, r2
    BLT begin_part_2


@ dump the answers into RAM and exit
@ C side has the struct to interpret this answer

    @ TODO: can use rotates here
    LDR r1,=0x02000000
    ADD r1,r1,r2
    ADD r1,r1,r2
    STR r3, [r1]
    ADD r1, r1, #4
    STR r4, [r1]

    SUB r1, r1, #4
    MOV r0, r1

    LDMFD SP!, {r3-r12, lr}
    BX lr
