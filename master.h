#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define BLOCK_SIZE 4096
#define TOTAL_SIZE 1048576 //1 GB
#define TOTAL_BLOCKS (TOTAL_SIZE / BLOCK_SIZE)

static char buffer[BLOCK_SIZE];
