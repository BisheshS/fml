#include <stdio.h>
#include <stdlib.h>
#include "traverse.h"
int main(){
	char *s = "this/is/a/test";
	char **p = path_split(s);
	int i;
	for(i = 0; i<path_length(s); i++)
		printf("%s\n", p[i]);
	char *test = path_join(p);
	printf("%s\n", test);
	
}
