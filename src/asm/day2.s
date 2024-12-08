@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Name: day1.s
@ Desc: Functions used to solve the AOC day 1 puzzle
@ Author: Will Martens
@

    .TEXT
    .ALIGN
    .ARM
	.GLOBAL day2_entrypoint

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ Name: day2_entrypoint
@ Desc: location to jump into from C land
@  I/O: r0: I   : Location of left column of data to process
@       r1: I   : Location of right column of data to process
@       r2: I   : Number of entries in the dataset

day2_entrypoint:
    STMFD SP!, {r3-r12, lr}

    LDMFD SP!, {r3-r12, lr}
    BX lr
