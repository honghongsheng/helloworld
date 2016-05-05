#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc,char* argv[])
{
int in,out;
char block[1024];
int nread;
 if(argc >3)
  {
  printf("Cp:Input format is wrong,too much files!\n");
  }
  else if(argc == 2)
  {
  printf("Cp:missing destination file operand after '%s'!\n",argv[1]);
   }
  else if(argc==1)
  {
   printf("Cp:missing file operand!\n");
  }
 else{
 if((in = open(argv[1],O_RDONLY))<0)
  printf("Cp:open '%s' failed!\n",argv[1]);
 if((out = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))<0)
  printf("Cp:open '%s' failed!\n",argv[2]);

 while((nread = read(in,block,sizeof(block)))>0)
     write(out,block,nread);
 exit(0);
  }
}
