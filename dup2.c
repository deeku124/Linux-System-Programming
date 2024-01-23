#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
char str[100];
    int file_desc = open("hello.txt",O_RDONLY);
  //  dup2(file_desc, 1) ; 
   // printf("I will be printed in the file hello.txt\n");
read(file_desc, str,100);
printf("%s\n",str);
    close(file_desc);
    return 0;
}
