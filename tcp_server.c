#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

  int newSocket;
  int welcomeSocket;
  char buffer[1024];
  struct sockaddr_in serverAddress;
  struct sockaddr_in clientAddress;
  socklen_t addressSize;
  
  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(22119);
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);
  
  int bindValue = bind(welcomeSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
  if(bindValue == 0) printf("Bind success\n");
  else printf("Bind failed\n");
  
  if(listen(welcomeSocket,5)==0) printf("Listening\n");
  else printf("Error\n");
  
  addressSize = sizeof clientAddress;
  newSocket = accept(welcomeSocket, (struct sockaddr *) &clientAddress, &addressSize);
  while(1){
  
    recv(newSocket, buffer, 1024, 0);
    printf("Received message: %s", buffer);
    send(newSocket,buffer,1024,0);
    printf("The reply is sent.\n\n");
  }
  
  close(welcomeSocket);
  close(newSocket);
  return 0;
}
