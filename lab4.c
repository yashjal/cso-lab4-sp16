#include "lab4.h"

/*
Bug 1: In process.c, after the first command is
executed, narg (which counts the number of arguments 
in the shell) is never reseted to 0 because process()
returns if EOL is detected (EOL is detected for first command) 
without resetting narg to 0. Easy fix was in line 19 when narg
is declared, we just initialize it to 0 so that everytime 
process() is called, narg is resetted to 0.

Bug 2:   

Bug 3: To quit the program if exit is typed, we check in
userin.c if in the 4th count, inpbuf (storing the shell
argument) matches 'exit' and the current character is the NULL
character. If it is, we return EOF and the program terminates.
The fix is in lines 27-35.

Bug 4: We need to catch and handle ctrl-C because the default
action of the kenrel terminates the program. It's a simple fix.
In process.c, we define a handler function in lines 5-7. If the
signal function in line 14 (process.c) catches the SIGINT
(ctrl-C) signal, then the function handler, changes boolean 
variable and after the signal function, the boolean variable is
checked and if detected process() returns thus terminating
the specific process and not the entire program.

Bug 5: To reap the background process, in runcommand.c line 54
waitpid() is used to remove the zombie background process after
which the exit status is returned. Before the fix, if the
process was in background, then the process id was printed and 
runcommand() was returned without reaping.

*/

int main()
{
    //run the shell until EOF (keyboard Ctrl+D) is detected
    while (userinput( ) != EOF)
    {
        process();
    }
    return 0;
}
