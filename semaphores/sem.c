#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int count=10;
int semid,ret;

struct sembuff{ 
unsigned short sem_num;  /* semaphore number */
short sem_op;   /* semaphore operation */
short sem_flg; 
}sbuf;


void *inc_thread(void*arg)
{
    while(1)
    {
    semop(semid,&sbuf,1);
    count++;
    printf("IncThread: %d\n",count);
    sbuf.sem_op=1;
    semop(semid,&sbuf,1);
    }
}
void *dec_thread(void*arg)
{
    while(1)
    {
    semop(semid,&sbuf,1);
    count--;
    printf("DecThread: %d\n",count);
    sbuf.sem_op=1;
    semop(semid,&sbuf,1);
    }
}
int main()
{
    pthread_t incID,decID;
union semun {
    int val; 	
	
    struct semid_ds *buf; 	
    unsigned short *array;	
    struct seminfo *__buf; 
    };
    union semun sun;
    sun.val=1;

sbuf.sem_num=0 ; // it is an array.. starts with zero
sbuf.sem_op= -1 ; // -1 for wait operation ; 1 for signal operation
sbuf.sem_flg=SEM_UNDO;
key_t key=ftok("sem",65);
    semid=semget(key,1,0666|IPC_CREAT);
	if(semid<0)
	{
	printf("semaphore not created\n");
	}
    semctl(semid,0,sun.val,sun);
    pthread_create(&incID, NULL, inc_thread, NULL);
    pthread_create(&decID, NULL, dec_thread, NULL);
    pthread_join(incID, NULL);
    pthread_join(decID, NULL);
    semctl(semid,0,IPC_RMID);
    return 0;
}
