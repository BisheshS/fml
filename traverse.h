#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int length(char *path){
	int count = 0;
	int i = 0;
	while(path[i]!='\0'){
		if(path[i] == '/')
			count++;
		i++;
	}
	return(count+1);
}
char** traverse_down(char *path){
	int l = 0;
	int k = 0;
	int len = length(path);
	char **alldirec;
	alldirec = (char**)malloc(len*sizeof(char*));
	for(k = 0; k<len; k++){
		alldirec[k] = (char*)malloc(50*sizeof(char));}
	
	while(path[l]!='\0'){
		int i=0;
		static int j = 0;
		char *subpath = (char*)malloc(10*sizeof(char)); 
		while(path[i]!='/' && path[i]!='\0'){
			subpath[i] = path[i];
			i++;
		}
		path = path + strlen(subpath)+1;
		alldirec[j] = subpath;
		j++;
	        l++;
	}
	return(alldirec);
}

	

	
