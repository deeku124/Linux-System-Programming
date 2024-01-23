#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int count=10;
sem_t semCount;
void *inc_thread(void*arg)
{
    while(1)
    {
    sem_wait(&semCount);
    count++;
    printf("IncThread: %d\n",count);
    sem_post(&semCount);
    }
}
void *dec_thread(void*arg)
{
    while(1)
    {
    sem_wait(&semCount);
    count--;
    printf("DecThread: %d\n",count);
    sem_post(&semCount);
    }
}
int main()
{
    pthread_t incID,decID;
    sem_init(&semCount, 0, 1);
    pthread_create(&incID, NULL, inc_thread, NULL);
    pthread_create(&decID, NULL, dec_thread, NULL);
    pthread_join(incID, NULL);
    pthread_join(decID, NULL);
    sem_destroy(&semCount);
    return 0;
}
