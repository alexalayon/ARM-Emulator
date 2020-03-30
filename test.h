/*
-----------------------------
Testing Header
-----------------------------
*/

#ifndef TEST_H
#define TEST_H

#include "quadratic_c.h"
#include "sum_array_c.h"
#include "find_max_c.h"
#include "fib_iter_c.h"
#include "fib_rec_c.h"
#include "strlen_c.h"

#include "functions.h"
#include "cache.h"



//Structures
struct emulator_struct	{
	unsigned int regs[16];
	int cpsr;
	unsigned int stack[1024];
};

struct emulator_analysis {
	unsigned int total_instructions;
	unsigned int data_instructions;
	unsigned int branch_instructions;
	unsigned int branches_taken;
	unsigned int memory;
};

struct cpsr{
	unsigned int neg;
	unsigned int zero;
	unsigned int carry;
	unsigned int overf;
};


/***********************
Print Results of Emulator Test
***********************/
void print_emulation(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis);



/* ----------------------- Program Functions ---------------*/

/***********************
Quadratic Emulator Test
***********************/
void quadratic_test();

/***********************
Sum Array Emulator Test
***********************/
void sum_array_test();

/***********************
Find Max Emulator Test
***********************/
void find_max_test();

/***********************
Fibonacci Iterative Sequence Program
***********************/
void fib_iter_test();

/***********************
Fibonacci Recursive Sequence Program
***********************/
void fib_rec_test();

/***********************
String Length Program
***********************/
void strlen_test();


/* ----------------------- Assembly Emulation ---------------*/

/***********************
Assembly Initialization
***********************/
void assembly_init(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int *func);

/***********************
Assembly Emulator Start
***********************/
void assembly_emulate(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis);

/***********************
Instruction execution
***********************/
void execute_instruction(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis);

/***********************
Multiply execution
***********************/
void execute_multip(struct emulator_struct *emu_struct, unsigned int instruction);

/***********************
Data Process execution
***********************/
void execute_data_process(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction);

/***********************
Branch execution
***********************/
void execute_branch(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction);

/***********************
Memory Instruction execution
***********************/
void execute_memory(struct emulator_struct *emu_struct, unsigned int instruction);

/***********************
Add Instruction execution
***********************/
void execute_add(struct emulator_struct *emu_struct, unsigned int instruction);

/***********************
Sub Instruction execution
***********************/
void execute_sub(struct emulator_struct *emu_struct, unsigned int instruction);

/***********************
MOV Instruction execution
***********************/
void execute_mov(struct emulator_struct *emu_struct, unsigned int instruction);

/***********************
CMP Instruction execution
***********************/
void execute_cmp(struct emulator_struct *emu_struct, unsigned int instruction);

/***********************
BX Instruction execution
***********************/
void execute_bx(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction);

/***********************
Block Data Transfer Instruction execution
***********************/
void execute_blockdata_transfer(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction);



#endif

/* --------------------------------- TEST.H --------------- */