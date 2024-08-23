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
  int portNumber;
  int nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddress;
  socklen_t addressSize;
  
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
  
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(22119);
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);
  addressSize = sizeof serverAddress;
  
  while(1){
    int option;
    printf("=== Options ===\n");
    printf("1. Convert characters to uppercase letters.\n");
    printf("2. Convert characters to lowercase letters.\n");
    printf("3. Reverse the order of characters.\n");
    printf("4. Print the sockaddr_in structure.\n");
    printf("Your option: ");

    scanf("%d", &option);
    getchar();
    sendto(clientSocket, &option, sizeof(option), 0, (struct sockaddr *) &serverAddress, addressSize);
    
    if(option >= 1 && option <=3){
    
      printf("Your message: ");
      fgets(buffer, 1024, stdin);
      if(buffer[strlen(buffer) - 1] == '\n') buffer[strlen(buffer) - 1] = '\0';
      nBytes = strlen(buffer) + 1;
      sendto(clientSocket, buffer, nBytes, 0, (struct sockaddr *) &serverAddress, addressSize);
      //printf("a");
      nBytes = recvfrom(clientSocket, buffer, 1024, 0, NULL, NULL);
      printf("Server reply: %s", buffer);
      printf("\n");
    }
    else if(option == 4){
    
      printf("sockaddr_in structure: \n");
      printf("sin_family = %d\n", serverAddress.sin_family);
      printf("sin_port = %d\n", ntohs(serverAddress.sin_port));
      printf("sin_addr.s_addr = %s\n", inet_ntoa(*(struct in_addr *) &serverAddress.sin_addr.s_addr));
    }
    else printf("Invalid option!\n");
    
    printf("\n");
  }
  close(clientSocket);
  return 0;
}
