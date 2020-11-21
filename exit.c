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

    if((child1= fork()) == -1){ //Forks first child
        printf("ERROR: First Child \n");
        return -1;
    }
    
    if(child1==0){//First Child outputs last 4 commands to terminal
       printf("History");
       execlp("tail","tail", "-4", "history",NULL);
       printf("history Failed!");
       exit(0);
		
    }       
    else{
        if((child2= fork()) == -1){//Forks second child
            printf("ERROR: Second Child \n");
            return -1;
        }

        if(child2==0){//Second Child performs ls on current directory
            execlp("ls","ls","-l",NULL);
            printf("Ls FAILED \n");
            exit(0);
        }
        else{
            int status;
            waitpid(child1,&status,0);
            waitpid(child2,&status,0);
            
            //Parent waits for both child processes to finish then waits for user to press enter to exit
			printf("\nPress [ENTER] to exit....");
            getchar();
            exit(0);
        }
    }
   
    return 0;
}
