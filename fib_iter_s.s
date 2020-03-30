
.global fib_iter_s


@ Function fib_iter_s
@ Prototype:
@   int fib_iter_s(int n)
fib_iter_s:
    push {r4, lr}   @ save r4 and return address in stack

    cmp r0, #0      @ compare n with 0
    beq fib_return  @ if n == 0 return 0

    mov r1, #0      @ prev_prev_num = 0
    mov r2, #0      @ prev_num = 0
    mov r3, #1      @ cur_num = 1
    mov r4, #1      @ initialize i = 1
for_loop:           @ for (int i = 1; i < n ; i++) {
    cmp r4, r0      @  compare i with n
    bge end_for     @  if i>=n, end the loop

    mov r1, r2      @     prev_prev_num = prev_num;
    mov r2, r3      @     prev_num = cur_num;
    add r3, r1, r2  @     cur_num = prev_prev_num + prev_num;

    add r4, r4, #1  @  i++
    b for_loop      @  repeat the for loop
                    @ }
end_for:
    mov r0, r3      @ return cur_num
fib_return:
    pop {r4, lr}    @ restore r4 and return address from stack
    bx lr           @ return to caller
