#include"syscall.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

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
  int in1,in2,out;
  char c1,c2;
  int n1=file_size(argv[1]);
  int n2=file_size(argv[2]);
if(argc !=4)
 printf("mergef:Input format is wrong,please try again!\n\n");

else{

  if((in1 = open(argv[1],O_RDONLY))<0)
 printf("mergef:open '%s' failed!\n",argv[1]);
  if((in2 = open(argv[2],O_RDONLY))<0)
 printf("mergef:open '%s' failed!\n",argv[2]);
  if((out = open(argv[3],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))<0)
 printf("mergef:open '%s' failed!\n",argv[3]);

  read(in1,&c1,n1);
       write(out,&c1,n1);
      lseek(out,0,2);
  read(in2,&c2,n2);
       write(out,&c2,n2);
  exit(0);
    }
}
