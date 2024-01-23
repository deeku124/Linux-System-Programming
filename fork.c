#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
pid_t id;
printf("before fork\n");
id=vfork();
if(id==0)
{
printf("child\n");
exit(1);
}
else
{
printf("parent\n");
}
return 0;
}

