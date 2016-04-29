#include<stdio.h>

#define N 200  

int main(int argc, char *argv[])
{
    char totalLine[N];               //定义可存放Ｎ个字符的数组来临时存放每行的数据
    FILE *fpSrc, *fpDest;
    fpSrc = fopen(argv[1], "r");     //直接用只读方式打开源文件
  
    fpDest = fopen(argv[2], "w");
  
    while(fgets(totalLine, N-1, fpSrc)){     //将每行依次读取到数组中
        fputs(totalLine, fpDest);            //依次写入每行的数据，包括换行
                        }

    fclose(fpSrc);
    fclose(fpDest);
    return 0;
}
