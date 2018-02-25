#include<stdbool.h>
bool init_disk_emulator(void);
bool free_disk_emulator(void);

bool read_block(long block_id, void* target);
bool write_block(long block_id, void* buffer);
