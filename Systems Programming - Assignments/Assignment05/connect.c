#include "defs.h"

/*
  Function name: setupServerSocket
  Purpose: Initializes a listen socket on a server.
  Parameters:
    in: None
    out: int* s - Pointer to an integer that will store the listen socket.
    in/out: None
    return: None
*/
void setupServerSocket(int *s) {
  struct sockaddr_in serverAddr;
  int currPort = MIN_PORT;
  int i;

  // Create listen socket
  *s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (*s < 0) {
    printf("Could not open socket\n");
    exit(-1);
  }

  // Setup server address
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddr.sin_port = htons((unsigned short) currPort);

  // Bind listen socket 

  i = bind(*s, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  while (i < 0 && currPort <= MAX_PORT) {
    serverAddr.sin_port = htons((unsigned short) ++currPort);
    i = bind(*s, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  }

  if (i < 0) {
    printf("Could not bind socket\n");
    exit(-1);
  }

  // Listen on socket 
  i = listen(*s, 5);
  if (i < 0) {
    printf("Could not setup listening on socket\n");
    exit(-1);
  }
}

/*
  Function name: acceptConnection
  Purpose: Blocks until a connection request comes in on the listen socket and accepts the connection on the client socket.
  Parameters:
    in: int lSock - Listen socket.
    out: int* cSock - Pointer to an integer that will store the connected socket.
    in/out: None
    return: None
*/
void acceptConnection(int lSock, int *cSock) {
  struct sockaddr_in clientAddr;
  socklen_t addrSize;

  // Wait for connection request 
  addrSize = sizeof(clientAddr);

  *cSock = accept(lSock, (struct sockaddr *) &clientAddr, &addrSize);
  if (*cSock < 0) {
    printf("Could not accept the connection\n");
    exit(-1);
  }
}

/*
  Function name: setupClientSocket
  Purpose: Initializes a socket on the client and connects to the server at the given IP address.
  Parameters:
    in: int* s - Pointer to an integer that will store the connected socket.
        char* ip - IP address of the server.
    out: None
    in/out: None
    return: None
*/
void setupClientSocket(int *s, char *ip) {
  struct sockaddr_in addr;
  int i;
  int currPort = MIN_PORT;

  // Create socket 
  *s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (*s < 0) {
    printf("Could not open socket\n");
    exit(-1);
  }

  // Setup address
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons((unsigned short) currPort);

  // Connect to server

  i = connect(*s, (struct sockaddr *) &addr, sizeof(addr));

  while (i<0 && currPort <= MAX_PORT) {
    addr.sin_port = htons((unsigned short) ++currPort);
    i = connect(*s, (struct sockaddr *) &addr, sizeof(addr));
  }

  if (i<0) {
    printf("Client could not connect\n");
    exit(-1);
  }
}

/*
  Function name: sendData
  Purpose: Sends data over a connected TCP/IP socket.
  Parameters:
    in: int s - Connected socket.
        char* buffer - Pointer to a character array containing data to be sent.
    out: None
    in/out: None
    return: None
*/
void sendData(int s, char *buffer) {
  send(s, buffer, strlen(buffer), 0);
}

/*
  Function name: rcvData
  Purpose: Blocks and receives data over a connected TCP/IP socket.
  Parameters:
    in: int s - Connected socket.
    out: char* buffer - Pointer to a character array that will store the received data.
    in/out: None
    return: int - Returns the number of bytes received.
*/
int rcvData(int s, char *buffer) {
  char tmpBuff[MAX_BUFF];
  int bytesRcv;

  // Read message from client
  bytesRcv = recv(s, tmpBuff, sizeof(tmpBuff), 0);
  tmpBuff[bytesRcv] = 0;
  strcpy(buffer, tmpBuff);

  return(bytesRcv);

}
