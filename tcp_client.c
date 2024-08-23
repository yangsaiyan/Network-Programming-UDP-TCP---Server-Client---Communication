#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

  int clientSocket;
  int nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddress;
  socklen_t addressSize;
  
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(22119);
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);
  addressSize = sizeof serverAddress;
  connect(clientSocket, (struct sockaddr *) &serverAddress, addressSize);
  
  while(1){
  
    printf("Message: ");
    fgets(buffer, 1024, stdin);
    nBytes = strlen(buffer) + 1;
    send(clientSocket, buffer, nBytes, 0);
    recv(clientSocket, buffer, 1024, 0);
    printf("Server reply: %s",buffer);
    printf("\n");
    
    memset(buffer, 0, 1024);
  }
  close(clientSocket);
  return 0;
}


