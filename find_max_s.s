
.global find_max_s


@ Function find_max_s
@ Prototype:
@   int find_max_s(int *array, int n)
find_max_s:
    push {r4, lr}   @ save r4 and return address in stack

    ldr r2, [r0]    @ intialize max = array[0]

    mov r3, #0      @ initialize i = 0
for_loop:           @ for (i = 0; i < n; i++) {
    cmp r3, r1      @  compare i with n
    bge end_for     @  if i>=n, end the loop

    ldr r4, [r0, r3, lsl #2]    @ load value from array[i]
    cmp r4, r2      @ compare array[i] with max
    ble next        @ if array[i] <= max, go to next value
    mov r2, r4      @    max = array[i];
next:
    add r3, r3, #1  @  i++
    b for_loop      @  repeat the for loop
                    @ }
end_for:
    mov r0, r2      @ return max
    pop {r4, lr}    @ restore r4 and return address from stack
    bx lr           @ return to caller
