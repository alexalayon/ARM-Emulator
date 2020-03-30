/*
-----------------------------
Helper Functions Code
-----------------------------
*/


#include "functions.h"

/***********************
Verify if the run command flag is set
***********************/
unsigned int run_command(unsigned int cond, unsigned int zero, unsigned int neg, unsigned int carry, unsigned int overf)
{
	//Verify the condition command, if true then the next operation will run, if false it will be skipped
	switch(cond)
	{
		case 0:
			return (zero);
			break;
		case 1:
			return (!zero);
			break;
		case 9:
			return (!carry || zero);
			break;
		case 10:
			return (neg == overf);
			break;
		case 11:
			return (neg != overf);
			break;
		case 13:
			return (zero || (neg != overf));
			break;
		case 14:
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

/***********************
Get the instruction operation
***********************/
int get_instruction(unsigned int instruction)
{
	//Get different operation data process
	unsigned int cmd;
	cmd = (instruction >> 21) & 0b1111;
	
	switch (cmd)
	{
		case 0b0100:
			return 1;
			break;
		case 0b0010:
			return 2;
			break;
		case 0b1101:
			return 3;
			break;
		case 0b1010:
			return 4;
			break;
		default:
			return 0;
			break;
	}
}

/***********************
Verify if the instruction is the bx
***********************/
bool is_bx_inst(unsigned int instruction) 
{
    unsigned int bx_code;

    bx_code = (instruction >> 4) & 0x00FFFFFF;

    return (bx_code == 0b000100101111111111110001);
}

/***********************
Verify if the instruction is multiply
***********************/
bool ismultip(unsigned int instruction)
{
	int mask2522 = 0x3C00000;
	int mask74 = 0xC000F0;
	int instr_copy = instruction;
	instr_copy =  instr_copy & mask74;
	instr_copy = instr_copy >> 4;
	int multPattern = 0x9;
	if(((mask2522 & instruction) == 0) && (multPattern == instr_copy)) 
	{
		return true;
	} 
	else 
	{
		return false;
	}
}

/***********************
Get RM register value
***********************/
unsigned int get_rm_value(unsigned int instruction, unsigned int i, unsigned int rd, unsigned int rn)
{
  unsigned int rot, rm;

    if (i == 1) 
	{
		rot = (instruction >> 8) & 0xF;
		rm = instruction & 0xFF;
		rot = rot * 2;
		rm = (rm >> rot) | (rm << (32 - rot));
    } 
	else 
	{
		rm = instruction & 0xF;
    }
	
    return rm;
}

/***********************
Get the negative flag of the result
***********************/
unsigned int get_negative(unsigned int operator)
{
	return (operator >> 31) & 1;
}

/***********************
Get the zero flag of the result
***********************/
unsigned get_zero(unsigned int operator)
{
	return (operator == 0);
}

/***********************
Get the carry flag of the result
***********************/
unsigned int get_carry(unsigned int op1, unsigned int op2)
{
	int msbOp1 =  (op1 >> 31) & 1;
	int msbOp2 = (op2 >> 31) & 1;
	int result = op1 + op2;
	int msbResult = (result >> 31) & 1;
	if((msbOp1 + msbOp2) != msbResult) 
	{
		return 1;
	} 
	else 
	{
		return 0;
	}
}

/***********************
Get the percentage of two values
***********************/
int get_percentage(unsigned int part, unsigned int total)
{
	float value = (part / (float) total) * 100;
    return (int) value;
}

bool is_block_data_transfer(unsigned int instruction)
{
	unsigned int data_transfer_code;
	data_transfer_code = (instruction >> 25) & 7;
	
	return (data_transfer_code == 4);
}