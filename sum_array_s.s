
.global sum_array_s


@ Function sum_array_s
@ Prototype:
@   int sum_array_s(int *array, int n)
sum_array_s:
    push {r4, lr}   @ save r4 and return address in stack

    mov r2, #0      @ intialize sum = 0

    mov r3, #0      @ initialize i = 0
for_loop:           @ for (i = 0; i < n; i++) {
    cmp r3, r1      @  compare i with n
    bge end_for     @  if i>=n, end the loop

    ldr r4, [r0, r3, lsl #2]    @ load value from array[i]
    add r2, r2, r4  @    sum = sum + array[i];

    add r3, r3, #1  @  i++
    b for_loop      @  repeat the for loop
                    @ }
end_for:
    mov r0, r2      @ return sum
    pop {r4, lr}    @ restore r4 and return address from stack
    bx lr           @ return to caller
