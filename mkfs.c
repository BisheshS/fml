#include "disk_emulator.h"
#include "mkfs.h"
#include "master.h"

bool mkfs() {
	if (init_disk_emulator() == false)
	{
		ERROR();
		return false;
	}
	root = (directory*)malloc(sizeof(directory));
	if (root == NULL)
		return false;
	strcpy(root->name, "root");
	root->parent = NULL;
	return true;
}

int main()
{
	printf("%d\n", (int)mkfs());
}
