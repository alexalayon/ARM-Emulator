/*
-----------------------------
Cache Memory Functions Code
-----------------------------
*/


#include "cache.h"


//Global Variables
unsigned int cache_memory[CACHE_SIZE];
struct cache_map map[CACHE_INDEX_SIZE];

unsigned int hit_counter;


void cache_init()
{
	for (int i = 0; i < CACHE_SIZE; i++)
	{
		cache_memory[i] = 0;
	}
	
	for (int i = 0; i < CACHE_INDEX_SIZE; i++)
	{
		map[i].valid = 0;
		map[i].tag = 0;
		map[i].block = 0;
		map[i].dirty_bit = 0;
	}
	
	hit_counter = 0;
}


void cache_store(unsigned int address, unsigned int data)
{
	unsigned int offset, index, tag, reg;
	offset = (address & 0x3);
	index = (address >> 2) & 0xF;
	tag = (address >> 6) & 0xF;
	
	reg = ((index & 0xF) << 2) | (offset & 0x3);
	
	if (map[index].valid == 1)
	{
		if (map[index].tag == tag)
		{
			hit_counter += 1;
		}
		else
		{
			map[index].tag = tag;
		}
		
		map[index].dirty_bit = 1;
	}
	else
	{
		map[index].valid = 1;
		map[index].tag = tag;
	}
	
	map[index].block = reg;
	cache_memory[reg] = data;
	
	//printf("\npush	%d	%d", address, data);
}

unsigned int cache_load(unsigned int address, unsigned int data_stack)
{
	unsigned int offset, index, tag, reg;
	unsigned int data;
	
	offset = (address & 0x3);
	index = (address >> 2) & 0xF;
	tag = (address >> 6) & 0xF;
	
	reg = ((index & 0xF) << 2) | (offset & 0x3);
	
	if (map[index].valid == 1)
	{
		if (map[index].tag == tag)
		{
			hit_counter += 1;
			if (map[index].block == reg)
			{
				if (map[index].dirty_bit == 1)
				{
					map[index].dirty_bit = 0;
				}
			}
			else
			{
				cache_memory[reg] = data_stack;
			}
		}
		else
		{
			map[index].tag = tag;
			cache_memory[reg] = data_stack;			
		}
	}
	else
	{
		map[index].valid;
		map[index].tag = tag;
		cache_memory[reg] = data_stack;
	}
	
	map[index].block = reg;
	data = cache_memory[reg];
	
	//printf("\npull	%d	%d", address, data);
	
	return data;
	
}


int get_cache_count()
{
	return hit_counter;
}

void print_cache()
{
	printf("Direct-mapped cache:\n");
	printf("Index	Valid	Tag	Block	DirtyBit\n");
	for (int i = 0; i < CACHE_INDEX_SIZE; i++)
	{
		printf("%d	%x	%x	%x	%x\n", i, map[i].valid, map[i].tag, i, map[i].dirty_bit);
	}
}