

.global fib_rec_s


@ Function fib_rec_s
@ Prototype:
@   int fib_rec_s(int n)
fib_rec_s:
    push {r4, r5, lr}   @ save r4, r5 and return address in stack

    cmp r0, #0      @ compare n with 0
    beq fib_return  @ if n == 0 return 0
    cmp r0, #1      @ compare n with 1
    beq fib_return  @ if n == 1 return 1

    mov r4, r0      @ save n in r4
    sub r0, r4, #1  @ calculate n - 1
    bl fib_rec_s    @ calculate fib_rec_c(n - 1)
    mov r5, r0      @ save result in r5

    sub r0, r4, #2  @ calculate n - 2
    bl fib_rec_s    @ calculate fib_rec_c(n - 2)

    add r0, r0, r5  @ return fib_rec_c(n - 1) + fib_rec_c(n - 2);
fib_return:
    pop {r4, r5, lr}    @ restore r4, r5 and return address from stack
    bx lr           @ return to caller
