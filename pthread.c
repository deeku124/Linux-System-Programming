#include<stdio.h>
#include <pthread.h>
int count=10;
pthread_mutex_t mutexCount; 
void *inc_thread(void *arg)
{
    
    while(1)
    {
    printf("inc grabbing mutex\n");
    pthread_mutex_lock (&mutexCount);
    printf("inc inside cs \n");
    count++;
    printf("inc_thread=%d\n",count);
    pthread_mutex_unlock (&mutexCount);
    printf("inc thread releasing mutex\n");
    } 
}


int main()
{
    pthread_t incID;
    pthread_t decID;
    printf("before creating both threads\n");
    pthread_mutex_init(&mutexCount,NULL); 
    pthread_create(&incID,NULL,inc_thread,NULL);
    pthread_create(&decID,NULL,inc_thread,NULL);
    pthread_join(incID,NULL);

    pthread_join(decID,NULL);
     pthread_mutex_destroy(&mutexCount);
    printf("after creating both threads\n");

    return 0;
}
