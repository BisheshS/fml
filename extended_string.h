#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "master.h"
int split_array_length(char **splitted_path){
	int j = 0;
	int count = 0;
	while(splitted_path[j]!=NULL){
		count++;
		j++;
	}
	return(count);
}
int path_length(char *path){
	int count = 0;
	int i = 0;
	while(path[i]!='\0'){
		if(path[i] == '/')
			count++;
		i++;
	}
	return(count+1);
}
char** path_split(char *path){
	char *copy = (char*)malloc(LIMIT*sizeof(char));
	int l = 0;
	int k = 0;
	for(k = 0; k<strlen(path); k++){
		copy[k] = path[k];
	}
	//printf("%s\n", copy);
	int len = path_length(copy);
	char **alldirec;
	alldirec = (char**)malloc(len*sizeof(char*));
	for(k = 0; k<len; k++){
		alldirec[k] = (char*)malloc(LIMIT*sizeof(char));}
	
	while(copy[l]!='\0'){
		int i=0;
		static int j = 0;
		char *subpath = (char*)malloc(LIMIT*sizeof(char)); 
		while(copy[i]!='/' && copy[i]!='\0'){
			subpath[i] = copy[i];
			i++;
		}
		copy = copy + strlen(subpath)+1;
		alldirec[j] = subpath;
		j++;
	        l++;
	}
	//printf("%s\n", path);
	
	return(alldirec);


}
/*char* get_filename_from_path(char* path){
	char **split = path_split(path);
	int len = path_length(path);
	static char *filename;
	filename = split[len-1];
	return(filename); we'll fix it later.*/



char* path_join(char ** splitted_path){
	int count = split_array_length(splitted_path);	
	int i = 0;
	char *slash = "/";
	char* join = (char*)malloc(sizeof(char)*LIMIT);
	char* temp = NULL;
	while(splitted_path[i]!= NULL){
		temp = splitted_path[i];
		strcat(temp, slash);
		strcat(join, splitted_path[i]);
		i++;
		//printf("%s\n", join);
	}
	join[strlen(join)-1] = '\0';
	
	return(join);
}
		

	

	
