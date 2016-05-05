#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include"syscall.h"
#include<fcntl.h>
#include<sys/stat.h>
#include <errno.h>
int main()
{
 int server_sockfd,client_sockfd;
 int Ip;
 int server_len,client_len;
 int i;
 struct sockaddr_in server_address,client_address;

 if((server_sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
  {      
        perror("socket"); 
        exit(errno); 
 }else 
        printf("socket create success!\n"); 

 server_address.sin_family = AF_INET;
 server_address.sin_addr.s_addr = htonl(INADDR_ANY);
 server_address.sin_port = htons(9734);
 server_len = sizeof(server_address);
 if((bind(server_sockfd,(struct sockaddr *)&server_address,server_len)) == -1)
  {
        perror("bind"); 
        exit(errno); 
 }else 
        printf("bind success!\n"); 
 if((listen(server_sockfd,5)) == -1)
{
        perror("listen"); 
        exit(errno); 
}else 
        printf("the server is listening!\n");

 while(1){

   char ch;
   printf("server waiting...\n");
   client_len = sizeof(client_address);
   if((client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address,&client_len)) == -1)
{           
    perror("accept"); 
    exit(errno); 
}else 
   printf("Accept success,the client's IP:%s\n",inet_ntoa(client_address.sin_addr)); 

   read(client_sockfd,&ch,256);
      write(client_sockfd,&ch,256);

                   }
}


