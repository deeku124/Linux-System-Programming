#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>

int main()
{
pid_t id;
int fd[2];
unsigned char buff[10];
pipe(fd);
id=fork();
if(id==0)
{
printf("child\n");
read(fd[0],buff,10);
printf("%s\n",buff);
}
else
{
printf("parent\n");
write(fd[1],"hello",9);
}
return 0;
}
