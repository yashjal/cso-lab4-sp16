#include "lab4.h"

int run;
//SIGINT handler
void INThandler(int sig) {
    run = 1;
}

/* Shell input line */
int process(void)
{
    //fix4
    run = 0;
    signal(SIGINT,INThandler);
    if (run)
        return 0;

    char *arg[MAXARG + 1];  /* pointer array for runcommand *///
    int toktype;            /* type of token in command */
    //fix1
    int narg=0;              /* number of arguments so far */
    int type;               /* type = FOREGROUND or BACKGROUND */

    while (1) 
    {
        /* Take action according to token type */
        switch(toktype = gettok(&arg[narg]))
        {
            case ARG:
                if(narg < MAXARG) 
                {
                    narg++;
                }
                break;

            case EOL:
            
            case SEMICOLON:
            
            case AMPERSAND:
                type = toktype == AMPERSAND ? BACKGROUND : FOREGROUND;
                
                if(narg != 0)
                {
                    arg[narg] = 0;

                    //fix2
                    if(strcmp(arg[0], "cd") == 0){
                        chdir(getenv("HOME"));
                    }

                    else if(strcmp(arg[0], "cd..") == 0){
                        chdir("..");
                    }

                    else {
                        runcommand(arg,type);
                    }
                }

                if(toktype == EOL)
                {
                    return;   
                }

                narg = 0;
                
                break;
        }
    }
}
