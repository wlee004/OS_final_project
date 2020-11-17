#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <wait.h>
#include <unistd.h>

int main(void){
	chdir("./Dir0");
	// creating child by using fork()
	int child_1, child_2;
	// creating child by using fork()
	
	child_1 = fork();
	if(child_1 == 0){
		char *argv1[] = {"clear",NULL};
		execvp(argv1[0], argv1);
	}
	else{
		child_2 = fork();
		if(child_2 == 0){
			char *argv1[] = {"ls","-la",NULL};
			execvp(argv1[0], argv1);
		}
	}
	
	int ret = rename("t1.txt", "tree.txt");
	
	// wait for the childrens to end 
	wait(0);
	wait(0);
}
