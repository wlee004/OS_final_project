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

    int child1;   
    int child2;

    if((child1= fork()) == -1){
        printf("ERROR: First Child \n");
        return -1;
    }
    
    if(child1==0){
		execlp("ls","ls","-l",NULL);
        printf("Ls FAILED \n");
        exit(0);
    }       
    else{
        if((child2= fork()) == -1){
            printf("ERROR: Second Child \n");
            return -1;
        }

        if(child2==0){
           execlp("/bin/sh","sh","-c","tail -4 ~/.bash_history",NULL);
           printf("history Failed!");
           exit(0);
        }
        else{
            int status;
            waitpid(child1,&status,0);
            waitpid(child2,&status,0);
			printf("\nPress [ENTER] to exit....");
            getchar();
            exit(0);
        }
    }
   
    return 0;
}

