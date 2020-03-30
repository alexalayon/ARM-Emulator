
.global strlen_s


@ Function strlen_s
@ Prototype:
@   int strlen_s(char *s)
strlen_s:
    mov r1, #0      @ initialize i = 0
while_loop:         @ while (s[i] != '\0') {
    ldrb r2, [r0, r1]   @ load s[i]
    cmp r2, #0      @ compare s[i] with \0
    beq end_while   @ if s[i] == \0, end while loop
    add r1, r1, #1  @   i++
    b while_loop    @ repeat while loop
                    @ }
end_while:
    mov r0, r1      @ return i
    bx lr           @ return to caller
