
.global quadratic_s


@ Function quadratic_s
@ Prototype:
@   int quadratic_s(int x, int a, int b, int c)
quadratic_s:
    mul r2, r0, r2  @ calculate b*x
    mul r1, r0, r1  @ calculate a*x
    mul r1, r0, r1  @ calculate a*x*x
    add r0, r1, r2  @ add b*x + a*x*x
    add r0, r0, r3  @ add c to previous result to get answer: (a * (x * x)) + (b * x) + c;
    bx lr           @ return to caller
