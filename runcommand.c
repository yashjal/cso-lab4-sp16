#include "lab4.h"

//static char l[2] = {'c','d'}; char* j; int i ;

// Execute a command with optional wait
int runcommand(char** cline, int where)
{
    pid_t pid;
    int status;
    

        switch(pid = fork())
        {
            case -1:
                perror(SHELL_NAME);
                return (-1);
            case 0:

                // for (i = 0; i < 2; i++) {
                //     if (*cline[i] != l[i])
                //         break;

                //     if (i == 1 && *cline[2] == '\0')
                //         chdir(getenv("HOME"));

                //     else if (i == 1) {
                //         int count = 2;
                //         int count1 = 0;
                //         while(1) {
                //             j[count1++] = *cline[count++];
                //             if (*cline[count] == '\0')
                //                 break;
                //         }
                //         int x = chdir(j);
                //         if (x != 0)
                //             perror("No such dir exists");
                //     }
                        
                // }

                execvp(*cline,cline);
                //we should never get to this code, sice execve does not return
                perror(*cline);
                exit(1);
                
        }

    // Code for parent
    // If background process print pid and exit program is running in the background
    if(where == BACKGROUND)
    {
        printf("[Process id %d]\n",pid);
        //fix5
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }

    // Wait until process pid exits
    if (waitpid(pid,&status,0) == -1) 
    {
        return -1;
    } 
    else 
    {
        return status;
    }
}
