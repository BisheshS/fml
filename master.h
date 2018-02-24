#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define BLOCK_SIZE 4096
#define TOTAL_SIZE 1048576 //1 GB
#define TOTAL_BLOCKS (TOTAL_SIZE / BLOCK_SIZE)

#define ERROR() printf("\nCOMMON ERROR : If you are seeing this, then Vishal is a lodu\n")

static char buffer[BLOCK_SIZE];

#define LIMIT 30 //Limit of length names of files and number of files in subdirectories

typedef struct inode {
    int block_id;
    char name[LIMIT];
    int permissions;
    bool mode; //true if it's a directory. in our implementation this is always false
}inode;

typedef struct directory {
    //int id; //idk if we need this
    char name[LIMIT]; //directory name
    struct directory *parent; //We might need this if you want to open a file in parent directory
    inode *inode_list[LIMIT]; //pointer to all the files (in this dir)
    struct directory *directory_list[LIMIT]; //pointer to all subdirectories
}directory;

typedef struct open_file {
    inode *file; 
    bool is_open; //close when its false
    int permissions; //copy unix, bitwise
    int offset;  
}open_file;

static open_file open_file_table[LIMIT];
static inode inode_table[LIMIT];
