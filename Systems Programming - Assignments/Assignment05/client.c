#include "defs.h"

/*
  Function name: viewEscape
  Purpose: Top-level function for the client process, given a server IP address. Sends a connection request to the server at the given IP address, loops, and waits for data that it prints out until a quit message is received.
  Parameters:
    in: char* serverIp - IP address of the server.
    out: None
    in/out: None
    return: None
*/
void viewEscape(char *serverIp) {
    int serverSocket;
    setupClientSocket(&serverSocket, serverIp);

    char buffer[MAX_BUFF];
    int bytesReceived;

    while ((bytesReceived = rcvData(serverSocket, buffer)) > 0) {
        printf("\033[2J\033[H");

        printf("%s", buffer);
        fflush(stdout);

        usleep(OUTPUT_INTERVAL);

        if (strstr(buffer, "EscapeOver") != NULL) {
            break;
        }
    }

    close(serverSocket);
}