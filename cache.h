/*
-----------------------------
Cache Memory Functions Header
-----------------------------
*/

#ifndef CACHE_H
#define CACHE_H

//Definitions
#define CACHE_SIZE	64
#define CACHE_INDEX_SIZE	16


struct cache_map {
	unsigned int valid;
	unsigned int tag;
	unsigned int dirty_bit;
	unsigned int block;
};

void cache_init();

void cache_store(unsigned int reg, unsigned int data);

unsigned int cache_load(unsigned int address, unsigned int data_stack);

int get_cache_count();

void print_cache();


#endif CACHE_H

/* --------------------------------- CACHE_H --------------- */