#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	
	FILE *fp1;

        //Creates a file to store history of commands
        fp1 = fopen("history" , "w");
        fclose(fp1);

	char command[50];
	printf("SHELL >> ");
	scanf("%s", command);
	int child;

	while(1){
		child = fork();
		if(child == -1){ // failed to fork child process
			printf("Failed to fork child\n");
			return 1;
		}
		if(child == 0){ // child process
			
			//saves command to history file
			fp1 = fopen("history" , "a+");
			fprintf(fp1,"%s\n",command);
			fclose(fp1);

			if(strcmp(command, "tree") != 0 && strcmp(command, "list") != 0 &&  
			   strcmp(command, "path") != 0 && strcmp(command, "exit") != 0){
				
				printf("Invalid Input\n"); 
				printf("This shell supports the commands: {'tree', 'list', 'path', 'exit'}\n");
				exit(0);
			}
			else{ // have child process run the command 
				char * arg[2]; 
				arg[0] = command; 
				arg[1] = NULL;
				execv(arg[0], arg);
			}
		}
		else{ // parent process
			wait(NULL);
			if (strcmp(command, "exit") == 0){ // if input was "exit" then exit the infinite loop
				exit(0);
			}
			else{ // keep asking for user input to shell 
				memset(command, 0, 50); // clear out previous user input
				printf("SHELL >> ");
				scanf(" %s", command);
			}
		}
	}
	return 0;
}
