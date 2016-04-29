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
  int n=file_size(argv[1]);
  int m=2;           
  char c;

in = open(argv[1],O_RDONLY);
out1 = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
out2 = open(argv[3],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

      read(in,&c,n/m); 
      write(out1,&c,n/m);
      lseek(in,1L,1);
      read(in,&c,(n-n/m)-1);
      write(out2,&c,(n-n/m)-1);

  exit(0);
}
