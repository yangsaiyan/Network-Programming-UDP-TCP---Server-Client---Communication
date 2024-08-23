#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

//Covert to Upper case char by char
void toUpperCase(char* str){
  
  for(int i = 0;  str[i] != '\0'; i++){
  
    str[i] = toupper(str[i]);
  }
}

//Covert to Lower case char by char
void toLowerCase(char* str){
  
  for(int i = 0; str[i] != '\0'; i++){
    str[i] = tolower(str[i]);
  }
}

//Reverse order, first char change position with last char, second char change position with second last char, and so on.
void reverseOrder(char* str){

  int length = strlen(str);
  char temp;

  for(int i = 0, j = length - 1; i < length/2; i++, j--){
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main(){

  int serverSocket;
  int nBytes;
  int option;
  char buffer[1024];
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t addressSize, clientAddressSize;
  
  serverSocket = socket(PF_INET, SOCK_DGRAM, 0);
  
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(22119);
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddress.sin_zero, '\0', sizeof serverAddress.sin_zero);
  
  bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
  addressSize = sizeof clientAddressSize;
  
  while(1){
  
    nBytes = recvfrom(serverSocket, &option, sizeof(option), 0, (struct sockaddr *) &clientAddress, &addressSize);
    if(option < 4 && option > 0){
      printf("Received a option: %d\n", option);
    
      nBytes = recvfrom(serverSocket, buffer, 1024, 0, (struct sockaddr *) &clientAddress, &addressSize);
      printf("Received a message: %s", buffer);
      printf("\n");
      if(option == 1) toUpperCase(buffer);
      else if(option == 2) toLowerCase(buffer);
      else if(option == 3) reverseOrder(buffer);
    
      printf("Send to client: %s", buffer);
      printf("\n\n");
      sendto(serverSocket, buffer, nBytes, 0, (struct sockaddr *) &clientAddress, addressSize);
    }
  }
  close(serverSocket);
  return 0;
}
