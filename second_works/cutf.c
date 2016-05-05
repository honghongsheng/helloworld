#include"syscall.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int file_size(char* filename)  
{  
    FILE *fp=fopen(filename,"r");  
    if(!fp) return -1;  
    fseek(fp,0L,SEEK_END);  
    int size=ftell(fp);  
    fclose(fp);       
    return size;  
}  

int main(int argc,char* argv[])
{
  int in,out1,out2;
  int nread1,nread2;
  int n=file_size(argv[1]);
  int m=2;           
  char c;
if(argc != 4)
printf("cutf:Input format is wrong,please try again!\n");
else
{
if((in = open(argv[1],O_RDONLY))<0)
 printf("cutf:open '%s' failed!\n",argv[1]);
if((out1 = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))<0)
 printf("cutf:open '%s' failed!\n",argv[2]);
if((out2 = open(argv[3],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))<0)
 printf("cutf:open '%s' failed!\n",argv[3]);

      read(in,&c,n/m);
      write(out1,&c,n/m);
      lseek(in,1L,1);
      read(in,&c,(n-n/m)-1);
      write(out2,&c,(n-n/m)-1);

  exit(0);

}
}
