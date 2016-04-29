#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>

int main()
{
int sockfd;
int len;
struct sockaddr_in address;
int result;
char ch[256]="A";

sockfd = socket(AF_INET,SOCK_STREAM,0);
address.sin_family = AF_INET;
address.sin_addr.s_addr = inet_addr("10.0.2.15");
address.sin_port = htons(9734);
len = sizeof(address);

result = connect(sockfd,(struct sockaddr *)&address,len);

      if(result == -1){
      perror ("oops:client1");
      exit(1);
                   }

write(sockfd,&ch,1024);
read(sockfd,&ch,1024);
printf("%d\n",len);
printf("receve from server:%s\n",ch);
close(sockfd);

exit(0);
}


