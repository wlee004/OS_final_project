#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

 int path(){
	char cwd[PATH_MAX]; // used to hold our cwd
	chdir("./Dir0");
	getcwd(cwd, sizeof(cwd)); //get the current directory and store in cwd
	printf("Current working directory: %s\n", cwd);

        FILE* t2 = fopen("t2.txt", "r+"); // open t2.txt in read and write mode so we can write the cwd to it

	if(t2 == NULL){ // if t2.txt doesn't exist
		printf("File t2.txt not found\n");
		return 1;
	}

	fputs(cwd, t2); // write current directory to t2.txt
	fclose(t2);
	rename("t2.txt", "path-info.txt"); // rename t2.txt to path-info.txt
	printf("t2.txt renamed to path-info.txt\n");

	FILE* tree = fopen("tree.txt", "r"); // open tree.txt to read contents and store into t3
	FILE* path = fopen("path-info.txt", "r"); // open path-info.txt to read contents and store into t3
	FILE* t3 = fopen("t3.txt", "r+"); // open t3.txt in read and write mode to get contents from tree.txt and path-info.txt

	if(tree == NULL){ // tree.txt doesn't exist
		printf("File tree.txt not found\n");
		return 1;
	}

        if(t3 == NULL){ // t3.txt doesn't exist  
              printf("File t3.txt not found\n");
                return 1;
        }

	char ch = fgetc(tree); // used to get file contents from tree.txt
	while(ch != EOF){ // while the file hasn't reached the end
		fputc(ch, t3); // write the contents from tree.txt into t3.txt
		ch = fgetc(tree);
	}
         
	ch = fgetc(path); // used to get file contents from path-info.txt
	while(ch != EOF){ // while the file hasn't reached the end
		fputc(ch, t3); // write the contents from path-info.txt into t3.txt
		ch = fgetc(path);
	}

        fclose(tree);
        fclose(path);
        fclose(t3);
        printf("tree.txt and path-info.txt concatenated into t3.txt\n");
	rename("t3.txt", "log.txt");
	printf("t3.txt renamed to log.txt\n");

	remove("tree.txt"); // delete tree.txt
	remove("path-info.txt"); // delete path-info.txt
	printf("Deleted tree.txt and path-info.txt files.\n");
	return 0;
}

int main(int agrc, char *argv[]){
    path(); // call the path function
}
