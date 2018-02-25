#include "disk_emulator.h"
#include "master.h"


static char **block_data;

bool init_disk_emulator() { // just for in memory simulation; substitue code for opening disk here
	if (block_data)
		return false; // Disk already allocated

	block_data = (char**)malloc(TOTAL_BLOCKS * sizeof(char*));
	int i;
	for (i = 0; i < TOTAL_BLOCKS; i++)
		block_data[i] = (char*)malloc(BLOCK_SIZE * sizeof(char));
	if (!block_data) //if malloc gives null
		return false;
	return true;
}

bool free_disk_emulator(void) { // just for in memory simulation; substitue code for closing disk here
	if (block_data) {
		int i;
		for (i = 0; i < TOTAL_BLOCKS; i++) {
			free(block_data[i]);
		}
		free(block_data);
		block_data = NULL;
	}
	return true; //freed already fam
}

bool read_block(long block_id, void *buffer) {
	if (block_id < TOTAL_BLOCKS) {
		memcpy(buffer, block_data[block_id], BLOCK_SIZE);
		return true;
	}
	return false;
}

bool write_block(long block_id, void *buffer) {
	if (block_id < TOTAL_BLOCKS) {
		memcpy(block_data[block_id], buffer, BLOCK_SIZE);
		return true;
	}
	return false;
}
