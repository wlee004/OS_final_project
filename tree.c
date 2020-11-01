#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

void tree()
{
    int dir0;
    dir0 = mkdir("Dir0", 0777); // create the directory nameed dir0

    // if dir0 exist

    if (dir0 == 0)
    {
        printf("Successfully create Dir0 directory\n");

        FILE *fp = fopen("Dir0//t1.txt", "a"); // create t1.txt inside dir0
        if (fp != NULL)
        {
            fclose(fp);
            printf("Successfully create t1.txt\n");
        }
        else
        {
            printf("Creating t1.txt failed!\n");
        }

        FILE *fp1 = fopen("Dir0//t2.txt", "a"); // create t2.txt inside dir0
        if (fp1 != NULL)
        {
            fclose(fp1);
            printf("Successfully create t2.txt\n");
        }
        else
        {
            printf("Creating t2.txt failed!\n");
        }

        FILE *fp2 = fopen("Dir0//t3.txt", "a"); // create t3.txt inside dir0
        if (fp2 != NULL)
        {
            fclose(fp2);
            printf("Successfully create t3.txt\n");
        }
        else
        {
            printf("Creating t3.txt failed!\n");
        }

        int dir1;
        dir1 = mkdir("Dir0/Dir1", 0777); // create the directory dir1 inside dir0
        if (dir1 == 0)
        {
            printf("Successfully create Dir1 directory!\n");
        }
        else
        {
            printf("Creating Dir1 failed!\n");
        }
    }
    else
    {
        printf("Creating Dir0 failed!\n");
    }
}

int main(int agrc, char *argv[])
{

    tree(); // run tree function

    return 0;
}
