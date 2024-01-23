#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
pid_t id1,id2;
id1=getpid();
id2=getppid();
printf("process id is :%d\n",id1);
printf("parent process id is :%d\n",id2);
return 0;
}

