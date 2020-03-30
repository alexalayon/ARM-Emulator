/*
-------------------------
Testing Program 
-------------------------
*/

#include "test.h"
#include "definitions.h"

//Variables
int stack_counter = 0;
struct cpsr cpsr_f;

/***********************
Print results of Emulator Test
***********************/
void print_emulation(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis)
{
	//Emulator print function
	int cache_hits, cache_misses;
	
	cache_hits = get_cache_count();
	cache_misses = emu_analysis->memory - cache_hits;
	emu_struct->cpsr = ((cpsr_f.neg << 31) | (cpsr_f.zero << 30) | (cpsr_f.carry << 29) | (cpsr_f.overf << 28));		//Add the flags to the CPSR variable
	printf("Emulator solution: %d\n", emu_struct->regs[0]);
	printf("Registers: \n");
	for (int i = 0; i < REGISTER_MAX; i++)																				//Print Registers
	{
		printf("R%d= %d		", i, emu_struct->regs[i]);
	}
	printf("CPSR: %d\n", emu_struct->cpsr);																				//Print CPSR
	printf("Stack Memory:\n");
	for (int i = 0; i < STACK_SIZE; i++)																				//Print Stack
	{
		if (emu_struct->stack[i] != 0)
		{
			printf("0x%x: %d\n", i, emu_struct->stack[i]);
		}
	}
	print_cache();
	printf("Dynamic Analysis:\n");																						//Print analysis
	printf("Total Instructions:	%d\n", emu_analysis->total_instructions);
	printf("Data processing Instructions:	%d  (%d%c)\n", emu_analysis->data_instructions, get_percentage(emu_analysis->data_instructions, emu_analysis->total_instructions) ,37);
	printf("Branches Instructions:	%d\n", emu_analysis->branch_instructions);
	printf("Branches Taken:	%d  (%d%c)\n", emu_analysis->branches_taken, get_percentage(emu_analysis->branches_taken, emu_analysis->branch_instructions) ,37);
	printf("Cache Hits:	%d  (%d%c)\n", cache_hits, get_percentage(cache_hits, emu_analysis->memory) ,37);
	printf("Cache Misses:	%d  (%d%c)\n", cache_misses, get_percentage(cache_misses, emu_analysis->memory) ,37);
}



/* ----------------------- Program Functions ---------------*/

/***********************
Quadratic Emulator Test
***********************/
void quadratic_test()
{
	//Quadratic Program
	for (int i = 0; i < NUMBER_TEST_MAX; i++)
	{
		struct emulator_struct emu_struct;
		struct emulator_analysis emu_analysis;
		assembly_init(&emu_struct, &emu_analysis, (unsigned int *)quadratic_s);				//Assembly emulator variables init
		emu_struct.regs[0] = quad_x[i];									//Registers filled with parameters
		emu_struct.regs[1] = quad_a[i];
		emu_struct.regs[2] = quad_b[i];
		emu_struct.regs[3] = quad_c[i];
		run_quadratic(quad_x[i], quad_a[i], quad_b[i], quad_c[i]);			//Run the assembly program
		assembly_emulate(&emu_struct, &emu_analysis);							//Emulation program
	}
}

/***********************
Sum Array Emulator Test
***********************/
void sum_array_test()
{
	struct emulator_struct emu_struct;
	struct emulator_analysis emu_analysis;	
	for (int i = 0; i < NUMBER_TEST_MAX; i++)
	{
		assembly_init(&emu_struct, &emu_analysis, (unsigned int *)sum_array_s);
		if (i < 3)
		{
			emu_struct.regs[0] = array1;										//Assembly emulator variables init
			emu_struct.regs[1] = sumarray_test[i];								//Registers filled with parameters
			run_sum_array(array1, sumarray_test[i]);							//Run the assembly program
			assembly_emulate(&emu_struct, &emu_analysis);							//Emulation program
		}
		else if (i < 4)
		{
			emu_struct.regs[0] = array2;
			emu_struct.regs[1] = sumarray_test[i];
			run_sum_array(array2, sumarray_test[i]);
			assembly_emulate(&emu_struct, &emu_analysis);				
		}
		else
		{
			emu_struct.regs[0] = sumarray_random;
			emu_struct.regs[1] = sumarray_test[i];
			run_sum_array(sumarray_random, sumarray_test[i]);
			assembly_emulate(&emu_struct, &emu_analysis);				
		}
	}
}

/***********************
Find Max Emulator Test
***********************/
void find_max_test()
{
	struct emulator_struct emu_struct;
	struct emulator_analysis emu_analysis;
	for (int i = 0; i < NUMBER_TEST_MAX; i++)
	{
		assembly_init(&emu_struct, &emu_analysis, (unsigned int *)find_max_s);
		switch (i)
		{
			case 0:
			case 1:
				emu_struct.regs[0] = array1;										//Assembly emulator variables init
				emu_struct.regs[1] = findmax_test[i];								//Registers filled with parameters
				run_find_max(array1, findmax_test[i]);								//Run the assembly program
				assembly_emulate(&emu_struct, &emu_analysis);							//Emulation program
				break;
			case 2:
				emu_struct.regs[0] = array2;
				emu_struct.regs[1] = findmax_test[i];
				run_find_max(array2, findmax_test[i]);
				assembly_emulate(&emu_struct, &emu_analysis);				
				break;
			case 3:
				emu_struct.regs[0] = findmax_array;
				emu_struct.regs[1] = findmax_test[i];
				run_find_max(findmax_array, findmax_test[i]);
				assembly_emulate(&emu_struct, &emu_analysis);		
				break;
			case 4:
				emu_struct.regs[0] = findmax_random;
				emu_struct.regs[1] = findmax_test[i];
				run_find_max(findmax_random, findmax_test[i]);
				assembly_emulate(&emu_struct, &emu_analysis);		
				break;
			default:
				break;
		}
	}
}

/***********************
Fibonacci Iterative Sequence Program
***********************/
void fib_iter_test()
{
	struct emulator_struct emu_struct;
	struct emulator_analysis emu_analysis;
	for (int i = 0; i < FIB_TEST_MAX; i++)
	{
		assembly_init(&emu_struct, &emu_analysis, (unsigned int *)fib_iter_s);		//Assembly emulator variables init
		emu_struct.regs[0] = fib_test[i];										//Registers filled with parameters
		run_fib_iter(fib_test[i]);											//Run the assembly program
		assembly_emulate(&emu_struct, &emu_analysis);							//Emulation program
	}
	assembly_init(&emu_struct, &emu_analysis, (unsigned int *)fib_iter_s);
	emu_struct.regs[0] = FIB_SEQ_MAX - 1;
	run_fib_iter_seq(FIB_SEQ_MAX);
	assembly_emulate(&emu_struct, &emu_analysis);							
}

/***********************
Fibonacci Recursive Sequence Program
***********************/
void fib_rec_test()
{
	struct emulator_struct emu_struct;
	struct emulator_analysis emu_analysis;
	for (int i = 0; i < FIB_TEST_MAX; i++)
	{
		assembly_init(&emu_struct, &emu_analysis, (unsigned int *)fib_rec_s);				//Assembly emulator variables init
		emu_struct.regs[0] = fib_test[i];												//Registers filled with parameters
		run_fib_rec(fib_test[i]);														//Run the assembly program
		assembly_emulate(&emu_struct, &emu_analysis);							//Emulation program
	}
	assembly_init(&emu_struct, &emu_analysis, (unsigned int *)fib_rec_s);
	emu_struct.regs[0] = FIB_SEQ_MAX - 1;
	run_fib_rec_seq(FIB_SEQ_MAX);
	assembly_emulate(&emu_struct, &emu_analysis);						
}

/***********************
String Length Program
***********************/
void strlen_test()
{
	struct emulator_struct emu_struct;
	struct emulator_analysis emu_analysis;
	for (int i = 0; i < STRING_TEST_MAX; i++)
	{
		assembly_init(&emu_struct, &emu_analysis, (unsigned int *)strlen_s);			//Assembly emulator variables init
		emu_struct.regs[0] = message[i];										//Registers filled with parameters
		run_strlen(message[i]);													//Run the assembly program
		assembly_emulate(&emu_struct, &emu_analysis);							//Emulation program
	}
}


/* ----------------------- Assembly Emulation ---------------*/

/***********************
Assembly Initialization
***********************/
void assembly_init(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int *func)
{
	for (int i = 0; i < REGISTER_MAX; i++)												//Set registers to zero
	{
		emu_struct->regs[i] = 0;
	}
	for (int i = 0; i < STACK_SIZE; i++)												//Set stack to zero
	{
		emu_struct->stack[i] = 0;
	}
	
	emu_struct->regs[PC] = (unsigned int)func;											//Get the program control of the function
	emu_struct->regs[SP] = (unsigned int)emu_struct->stack[STACK_SIZE];					//Get the stack size into the SP
	emu_struct->cpsr = 0;																//Set CPSR to zero
	
	emu_analysis->total_instructions = 0;										//Set all analysis to zero
	emu_analysis->data_instructions = 0;
	emu_analysis->branch_instructions = 0;
	emu_analysis->branches_taken = 0;
	emu_analysis->memory = 0;
	
	cache_init();
	
}

/***********************
Assembly Emulator Start
***********************/
void assembly_emulate(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis)
{
	while(emu_struct->regs[PC] != 0)													//Execute all instructions
	{
		emu_analysis->total_instructions += 1;											//Add instruction to counter
		execute_instruction(emu_struct, emu_analysis);
	}
	print_emulation(emu_struct, emu_analysis);											//Print results
}



/***********************
Instruction execution
***********************/
void execute_instruction(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis)
{
	unsigned int op, instruction, cond, run;
	instruction = *((unsigned int *) emu_struct->regs[PC]);								//Get the instruction pointer
	op = (instruction >> 26) & 0b11;													//Get the operation command
    cond = (instruction >> 28) & 0xF;													//Get the condition command
	
	run = run_command(cond, cpsr_f.zero, cpsr_f.neg, cpsr_f.carry, cpsr_f.overf);		//Verify if the next operation would run
	
	if (run == 0)
	{
		emu_struct->regs[PC] = emu_struct->regs[PC] + 4;									//Skip to the next instruction
	}
	switch(op)																			//Verify the operation command
	{
		case 0:
			emu_analysis->data_instructions += 1;
			if (run == 1)
			{
				if (ismultip(instruction))
				{	
					execute_multip(emu_struct, instruction);							//Multiply operation
				}
				else
				{
					execute_data_process(emu_struct, emu_analysis, instruction);		//Data process command
				}
			}
			break;
		case 1:
			emu_analysis->memory += 1;
			if (run == 1)
			{
				//emu_analysis->cache_hits += 1;
				execute_memory(emu_struct, instruction);								//Memory process command
			}
			break;
		case 2:
			emu_analysis->branch_instructions += 1;
			if (run == 1)
			{
				emu_analysis->branches_taken += 1;
				execute_branch(emu_struct, emu_analysis, instruction);					//Branch process command
			}
			break;
		default:
			printf("Error command\n");
			break;
	}
}

/***********************
Multiply execution
***********************/
void execute_multip(struct emulator_struct *emu_struct, unsigned int instruction)
{
	unsigned int a, s, rd, rn, rs, rm;
	a = (instruction >> 21) & 1;																			//Get the data from the instruction
	s = (instruction >> 20) & 1;
	rd = (instruction >> 16) & 15;
	rn = (instruction >> 12) & 15;
	rs = (instruction >> 8) & 15;
	rm = (instruction) & 15;
	if (a)																									//Checks if the multiplication is accumulative
	{
		emu_struct->regs[rd] = emu_struct->regs[rm] * emu_struct->regs[rs] + emu_struct->regs[rn];
	}
	else
	{
		emu_struct->regs[rd] = emu_struct->regs[rm] * emu_struct->regs[rs];
	}
	if (s)																									//Checks the CPSR will be modified
	{
		cpsr_f.neg = get_negative(emu_struct->regs[rd]);													//Set the CPSR flags
		cpsr_f.zero = get_zero(emu_struct->regs[rd]);
	}
	
	emu_struct->regs[PC] = emu_struct->regs[PC] + 4;														//Increment the program counter to the next operation
}

/***********************
Data Process execution
***********************/
void execute_data_process(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction)
{
	int operation;
	
	if (is_bx_inst(instruction)) 																			//Verify the branch exchange
	{
        execute_bx(emu_struct, emu_analysis, instruction);													//Execute the branch exchange command
    }
	else
	{
		operation = get_instruction(instruction);															//Get the operation
		switch (operation)
		{
			case 1:
				execute_add(emu_struct, instruction);														//Add operation
				break;
			case 2:
				execute_sub(emu_struct, instruction);														//Sub operation
				break;
			case 3:
				execute_mov(emu_struct, instruction);														//Mov operation
				break;
			case 4:
				execute_cmp(emu_struct, instruction);														//CMP operation
				break;	
			default:
				break;
		}
	}
}

/***********************
Branch execution
***********************/
void execute_branch(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction)
{
	unsigned int type, link_bit;
	
	if (is_block_data_transfer(instruction))															//Verify the block data transfer instruction
	{
		execute_blockdata_transfer(emu_struct, emu_analysis, instruction);								//Execute the block data transfer instruction
	}
	else
	{
		unsigned int type, link_bit;
		int imm24;
		imm24 = instruction & 0xFFFFFF;																	//Get the immediate offset
		type = (instruction >> 23) & 0b1;																//Get the type offset
		link_bit = (instruction >> 24) & 0b1;															//Get the bit link
	
		if (link_bit == 1) 																				//Verify if the link is set
		{
			emu_struct->regs[LR] = emu_struct->regs[PC] + 4;											//Save the next instruction into LR
		}

		imm24 = imm24 << 2;
		for (int i = 31; i >= 25; i--) 
		{
			imm24 = (type << i) | imm24;																//Set the orientation and the value of the offset
		}
		

		if (type == 1) 																					//Verify if the offset is positive or negative
		{
			imm24 = ~(imm24) + 1;																		//Go back to the operation the branch is pointing
			emu_struct->regs[PC] += 8;
			emu_struct->regs[PC] -= imm24;
		} 
		else 
		{
			emu_struct->regs[PC] += 8;																	//Continue to the next operation the branch is pointing
			emu_struct->regs[PC] += imm24;
		}
	}
}

/***********************
Memory instruction execution
***********************/
void execute_memory(struct emulator_struct *emu_struct, unsigned int instruction)
{
	unsigned int load, byte, rn, rd, u, immediate, sh, rm, offset;
	
	load = (instruction >> 20) & 0b1;																	//Get the instruction flags
	byte = (instruction >> 22) & 0b1;
	rn = (instruction >> 16) & 0xF;
	rd = (instruction >> 12) & 0xF;
	u = (instruction >> 23) & 0b1;
	
	immediate = (instruction >> 25) & 1;																//Get the immediate offset flag
	
	if (immediate == 0) 
	{
		offset = instruction & 0xFFF;																	//Set the offset as the 12 less significative bits
	} 
	else 
	{  
		sh = (instruction >> 5) & 0b11;																	//Get the shift value
		rm = (instruction >> 7) & 0b11111;																//Get the shift rm value
		if (sh == 1) 																					//Verify the shifttype
		{
			offset = emu_struct->regs[(instruction & 0xF)];												//Set the offset with the shift left
		} 
		else 
		{
			offset = (emu_struct->regs[instruction & 0xF] << rm);										//Set the offset with the shift left and the rm						
		}
	}
 
	if (load == 0 && byte == 0) 																			//Store memory instruction
	{
		if (u == 1) 																						//Verify the orientation of the memory stack up/down
		{
			if (byte == 0) 																						//Verify the write back of the address
			{
				*((unsigned int *) (emu_struct->regs[rn] + offset)) = emu_struct->regs[rd];					//Store the data from a register
			} 
			else 
			{
				*((unsigned char *) (emu_struct->regs[rn] + offset)) = emu_struct->regs[rd];				//Store the data from a register
			}
		} 
		else 
		{
			if (byte == 0) 
			{
				*((unsigned int *) (emu_struct->regs[rn] - offset)) = emu_struct->regs[rd];					//Store the data from a register
			} 
			else 
			{
				*((unsigned char *) (emu_struct->regs[rn] - offset)) = emu_struct->regs[rd];				//Store the data from a register
			}
		}
	} 
	else if (load == 1) 																					//Load memory instruction
	{
		if (u == 1) 																						//Verify the orientation of the memory stack up/down
		{
			if (byte == 0) 																					//Verify the write back of the address
			{
				emu_struct->regs[rd] = *((unsigned int *) (emu_struct->regs[rn] + offset));					//Load the data from a register to another register
			} 
			else 
			{
				emu_struct->regs[rd] = *((unsigned char *) (emu_struct->regs[rn] + offset));				//Load the data from a register to another register
			}
		} 
		else 
		{	
			if (byte == 0) 
			{
				emu_struct->regs[rd] = *((unsigned int *) (emu_struct->regs[rn] - offset));					//Load the data from a register to another register
			} 
			else 
			{
				emu_struct->regs[rd] = *((unsigned char *) (emu_struct->regs[rn] - offset));				//Load the data from a register to another register
			}
		}
	}
	emu_struct->regs[PC] = emu_struct->regs[PC] + 4;														//Set the next instruction
	
}


/***********************
Add instruction execution
***********************/
void execute_add(struct emulator_struct *emu_struct, unsigned int instruction)
{
	unsigned int i, rd, rn, rm, s, op;	
	s = (instruction >> 20) & 1;																			//Get the instruction flags
    i = (instruction >> 25) & 1;
    rd = (instruction >> 12) & 0xF;
    rn = (instruction >> 16) & 0xF;
    rm = get_rm_value(instruction, i, rd, rn);																//Get rm value

    if (i == 1) 																							//Check if the instruction is with a constant or a variable
	{
		op = rm;																							//Set the constant value
    } 
	else 
	{
		op = emu_struct->regs[rm];																			//Set the variable value
    }
	emu_struct->regs[rd] = emu_struct->regs[rn] + op;														//Add the values
	
    if (rd != PC) 																							//Verify that the rd register does not content the next instruction
	{
		if (s == 1)																							//Verify the CPSR flags
		{
			cpsr_f.neg = get_negative(emu_struct->regs[rd]);													//Set the CPSR flags
			cpsr_f.zero = get_zero(emu_struct->regs[rd]);
			cpsr_f.carry = get_carry(emu_struct->regs[rn], op);
		}
		
		emu_struct->regs[PC] = emu_struct->regs[PC] + 4;													//Set the next instruction
    }
	
}

/***********************
Sub instruction execution
***********************/
void execute_sub(struct emulator_struct *emu_struct, unsigned int instruction)
{
	unsigned int rd, rn, rm, i, rot;
	
    i = (instruction >> 25) & 1;																			//Get the instruction flags
    rd = (instruction >> 12) & 0xF;
    rn = (instruction >> 16) & 0xF;
    rm = get_rm_value(instruction, i, rd, rn);																//Get rm value
    
    if (i == 1) 																							//Check if the instruction is with a constant or a variable
	{
		emu_struct->regs[rd] = emu_struct->regs[rn] - rm;													//Substract the constant from the variable
    } 
	else 
	{
		emu_struct->regs[rd] = emu_struct->regs[rn] - emu_struct->regs[rm];									//Substract the variable from the main variable
    }
	
    if (rd != PC) 																							//Verify that the rd register does not content the next instruction
	{
      emu_struct->regs[PC] = emu_struct->regs[PC] + 4;														//Set the the next instruction
    }
}

/***********************
Mov instruction execution
***********************/
void execute_mov(struct emulator_struct *emu_struct, unsigned int instruction)
{
	unsigned int rd, rm, i, rot, rsr, shamt5, sh;														
    i = (instruction >> 25) & 1;																			//Get the instruction flags
    rd = (instruction >> 12) & 0xF;	
    if (i == 1) 																							//Check the immediate operand
	{
        rot = (instruction >> 8) & 0xF;																		//Get the rotation value
        rm = instruction & 0xFF;																			//Get the rm value
        rot = rot * 2;
        rm = (rm >> rot) | (rm << (32 - rot));																//Set the rotation of the rm value
        emu_struct->regs[rd] = rm;																			//Save the data into the rd register
    } 
	else 
	{
        rsr = (instruction >> 4) & 0b1;																		//Get the rsr value
        rm = instruction & 0xF;																				//Get the rm value
        if (rsr == 0) {
            shamt5 = (instruction >> 7) & 0b11111;
            sh = (instruction >> 5) & 0b11;																	//Get the shift value
            if (sh == 0) 
			{
                emu_struct->regs[rd] = emu_struct->regs[rm] << shamt5;										//Save the data with the applied shift into the rd register
            }
        } 
		else 
		{
            emu_struct->regs[rd] = emu_struct->regs[rm];													//Save the data from rm into rd
        }
    }

    if (rd != PC) {
        emu_struct->regs[PC] = emu_struct->regs[PC] + 4;													//Set the the next instruction
    }
}

/***********************
CMP instruction execution
***********************/
void execute_cmp(struct emulator_struct *emu_struct, unsigned int instruction)
{
	unsigned int rd, rn, rm, i, op;
    int res;

    i = (instruction >> 25) & 1;																			//Get the instruction flags
    rd = (instruction >> 12) & 0xF;
    rn = (instruction >> 16) & 0xF;

    if (i == 1) 																							//Check the immediate operand
	{
        rm = instruction & 0xFF;																			//Get the rm value
		op = rm;
        res = emu_struct->regs[rn] - rm;																	//Substract rm from the register rn
    } 
	else 
	{
        rm = instruction & 0xF;																				//Get the rm value
		op = emu_struct->regs[rm];
        res = emu_struct->regs[rn] - emu_struct->regs[rm];													//Substract the value of the register rm from the register rn
    }
	
	cpsr_f.neg = get_negative(res);																				//Set the CPSR flags
	cpsr_f.zero = get_zero(res);
	cpsr_f.carry = get_carry(emu_struct->regs[rn], op);

    if (rd != PC) 
	{
        emu_struct->regs[PC] = emu_struct->regs[PC] + 4;													//Set the the next instruction
    }
}

/***********************
BX instruction execution
***********************/
void execute_bx(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction)
{
	emu_analysis->data_instructions -= 1;																	//Change the analysis counters
	emu_analysis->branch_instructions += 1;
	emu_analysis->branches_taken += 1;
	
    unsigned int rn;
    rn = instruction & 0b1111;																				//Get the rn value

    emu_struct->regs[PC] = emu_struct->regs[rn];															//Save the rn register into the program counter
}

/***********************
Block Data Transfer instruction execution
***********************/
void execute_blockdata_transfer(struct emulator_struct *emu_struct, struct emulator_analysis *emu_analysis, unsigned int instruction)
{
	//emu_analysis->cache_hits += 1;																		//Change the analysis counters
	emu_analysis->branch_instructions -= 1;
	emu_analysis->branches_taken -= 1;
	
	unsigned int l, u, rn, rl, count, cache;
	l = (instruction >> 20) & 1;																			//Get the instruction flags
	u = (instruction >> 23) & 1;
	rn = (instruction >> 16) & 0xF;
	rl = (instruction & 0xFFFF);
	
	if (l == 0)																								//Store Data
	{
		for (int i = 0; i < REGISTER_MAX; i++)
		{
			if (u == 0)																						//Substract offset
			{
				if (((rl >> i ) & 1) == 1)																	//Verify the register to be stored
				{
					emu_analysis->memory += 1;															
					
					stack_counter = stack_counter + 1;														//Move the counter of the stack
					emu_struct->stack[rn + stack_counter] = emu_struct->regs[i];							//Store the data to stack
					cache_load(rn + stack_counter, emu_struct->regs[i]);
				}
			}
			else																							//Add offset
			{
				if (((rl >> i ) & 1) == 1)																	//Verify the register to be stored
				{
					emu_analysis->memory += 1;		
					stack_counter = stack_counter - 1;														//Move the counter of the stack
					emu_struct->stack[rn - stack_counter] = emu_struct->regs[i];							//Store the data to stack
					cache_load(rn - stack_counter, emu_struct->regs[i]);
					stack_counter = stack_counter + 1;
					
				}
			}
		}
	}
	else																									//Load Data
	{
		for (int i = REGISTER_MAX - 1; i >= 0; i--)
		{
			if (u == 1)																						//Substract offset
			{
				if (((rl >> i ) & 1) == 1)																	//Verify the register to be loaded
				{
					emu_analysis->memory += 1;		
					emu_struct->regs[i] = emu_struct->stack[rn + stack_counter];							//Load the data from stack
					cache_store(rn + stack_counter, emu_struct->regs[i]);
					stack_counter = stack_counter - 1;														//Move the counter of the stack
				}
			}
			else																							//Add offset
			{
				if (((rl >> i ) & 1) == 1)																	//Verify the register to be loaded
				{	
					emu_analysis->memory += 1;		
					emu_struct->regs[i] = emu_struct->stack[rn - stack_counter];							//Load the data from 
					cache_store(rn - stack_counter, emu_struct->regs[i]);
					stack_counter = stack_counter + 1;														//Move the counter of the stack
				}
			}
		}
	}
	
	emu_struct->regs[PC] = emu_struct->regs[PC] + 4;
}