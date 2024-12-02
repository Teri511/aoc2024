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
@ Name: day1_entrypoint
@ Desc: location to jump into from C land
@  I/O: r0: I   : Location of left column of data to process
@       r1: I   : Location of right column of data to process
@       r2: I   : Number of entries in the dataset

day1_entrypoint:
		STMFD SP!, {r3-r12, lr}

        LDR r3,=0x02000000
        STR r0, [r3]

        LDMFD SP!, {r2-r12, lr}
		bx lr