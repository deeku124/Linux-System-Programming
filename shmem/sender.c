#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
int shmid;
key_t key=ftok("sender",65);
shmid=shmget(key,1024,0666|IPC_CREAT) ;
if(shmid <0)
{
printf("memory cannot be allocated\n");
}

char *str=(char*) shmat(shmid,NULL,0);
printf("enter a string of characters\n");
gets(str);
shmdt(str);
return 0;
}

