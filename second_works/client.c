#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>
#include<time.h>
#include <errno.h>

int main()
{
   int sockfd;
   int len;
   struct sockaddr_in address;
   struct tm *tm_ptr;
   time_t the_time;
   int result;
   char ch[1024]="A";

   if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
        {
        perror("socket");
        exit(errno);
    }else
        printf("socket create success!\n");
   address.sin_family = AF_INET;
   address.sin_addr.s_addr = inet_addr("10.0.2.15");
   address.sin_port = htons(9734);
   len = sizeof(address);

   if((result = connect(sockfd,(struct sockaddr *)&address,len)) == -1)
    {   
        perror("connect");
        exit(errno);
    }else
        printf("conncet success!\n");

  (void) time(&the_time);
  tm_ptr = gmtime(&the_time);
  write(sockfd,&ch,1024);
  read(sockfd,&ch,1024);

   printf("receve from server:%s ",ch);
   printf("  (%02d:%02d:%02d)",tm_ptr->tm_hour,tm_ptr->tm_min,tm_ptr->tm_sec);
   printf("  (IP:%s)\n",inet_ntoa(address.sin_addr));
   close(sockfd);
   exit(0);
}


