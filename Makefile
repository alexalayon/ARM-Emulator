# A useful makefile which factors names and flags into make variables
# so the rules can be as generic as possible
# $@ is make's built-in variable for the target (left of :)
# $^ is make's built-in variable for the prereqs (right of :)
# $< is make's built-in variable for the first item in the prereqs

all: emulator

PROGS=quadratic_c.o quadratic_s.o sum_array_c.o sum_array_s.o find_max_c.o find_max_s.o fib_iter_c.o fib_iter_s.o fib_rec_c.o fib_rec_s.o strlen_c.o strlen_s.o functions.o test.o cache.o
CC=gcc
CFLAGS=-g
ASM=as
ASMFLAGS=-g

# Assemble assembly language source files into object files
%.o: %.s
	$(ASM) $(ASMFLAGS) -o $@ $<
	
# Compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Link the object files together into the executable
emulator : emulator.c ${PROGS}
	gcc ${CFLAGS} -o emulator emulator.c ${PROGS}

clean:
	rm -rf quadratic sum_array find_max fib_iter fib_rec strlen *.o
