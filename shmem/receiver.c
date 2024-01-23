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
printf("date read from shared mem is:%s\n",str);
shmdt(str);
shmctl(shmid,IPC_RMID,NULL);
return 0;
}

