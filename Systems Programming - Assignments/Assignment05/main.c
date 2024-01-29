#include "defs.h"


/*
  Function name: main
  Purpose: Entry point of the program. Initializes the random number generator, checks command line arguments to determine if the program should run as a server or client, and executes the corresponding code.
  Parameters:
    in: int argc - Number of command line arguments.
        char* argv[] - Array of command line argument strings.
    out: None
    in/out: None
    return: int - Returns 0 on successful execution, -1 on incorrect command line usage.
*/
int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));

    if (argc == 1) {

        runEscape();
    } else if (argc == 2) {

        viewEscape(argv[1]);
    } else {

        printf("Usage: %s [server_ip]\n", argv[0]);
        return -1;
    }

    return 0;
}
