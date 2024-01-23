#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int main()
{
//const char *ps_envp[] = {"PATH=/bin:/usr/bin", "TERM=console", 0};
printf("execvp function\n");
char *arg[]={"-al","/home/ubuntu/Downloads",NULL};
execvp("ls",arg);
//execv("/bin/ls",arg);
//execve("/bin/ls",arg,ps_envp);
//char *arg1="-al";
//char *arg2="/home";
//execle("/bin/ls",arg1,arg2,0,ps_envp);
//execlp("ls",arg1,arg2,0);
printf("Done");
return 0;
}



