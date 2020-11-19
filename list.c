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
    pid_t child_1, child_2; // create all process id
    
    int mypipe[2];
    pipe(mypipe);

    chdir("./Dir0"); // Changes Directory

    child_1 = fork();
    if (child_1 < 0)
    {
        perror("[ERROR] child_1");
        return 1;
    }
    else if (child_1 == 0)
    {
        // no need for pipe
        close(mypipe[0]);
        close(mypipe[1]);

        char *argv1[] = {"clear",NULL};
		execvp(argv1[0], argv1);
    }
    else{
		wait(0);
	}

	child_2 = fork();
	if (child_2 < 0)
	{
		perror("[ERROR] child_2");
		return 1;
	}
	else if (child_2 == 0)
	{
		close(mypipe[0]);
		char *argv1[] = {"ls","-la",NULL};
		execvp(argv1[0], argv1);
		close(mypipe[1]);
	}
	else{
		wait(0);
	}
	//As the system() call uses a shell to execute the command
	system("ls -la > t1.txt");
	int ret = rename("t1.txt", "tree.txt");
	
    return 0;
}
