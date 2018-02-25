#include <stdio.h>
#include <stdlib.h>
#include "traverse.h"
int main(){
	char *s = "this/is/a/test";
	char **p = traverse_down(s);
	printf("%s\n", p[3]);
}
