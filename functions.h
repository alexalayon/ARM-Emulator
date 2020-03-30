/*
-----------------------------
Helper Functions Header
-----------------------------
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>


//Get Command
unsigned int run_command(unsigned int cond, unsigned int zero, unsigned int neg, unsigned int carry, unsigned int overf);

//Get instruction
int get_instruction(unsigned int instruction);

//Valuate if is bx command
bool is_bx_inst(unsigned int instruction);

//Value if is a multiply command
bool ismultip(unsigned int instruction);

//Get rm value
unsigned int get_rm_value(unsigned int instruction, unsigned int i, unsigned int rd, unsigned int rn);

//Get negative flag
unsigned int get_negative(unsigned int operator);

//Get zero flag
unsigned get_zero(unsigned int operator);

//Get carry flag
unsigned int get_carry(unsigned int op1, unsigned int op2);

//Get percentage value
int get_percentage(unsigned int part, unsigned int total);

//Valuete if is a block data transfer command
bool is_block_data_transfer(unsigned int instruction);

#endif FUNCTIONS_H

/* --------------------------------- FUNCTIONS.H --------------- */