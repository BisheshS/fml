#include<stdio.h>
#include<string.h>



struct inode* ptr = inode_table[LIMIT];

void print(int *st, char *st_name, int *perm, bool *b)
{
	printf("    %-10d\t\t %-12s\t\t %8d\t %8.2f\n\n", st.id, st_name.name, perm.permission, b.mode);
}
int x=0;
struct inode* endPtr = data + sizeof(data)/sizeof(data[0]);
while ( ptr < endPtr ){
   	print(inode_table[x])
	ptr++;
	x++;
}
