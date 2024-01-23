#include<stdio.h>
#include <pthread.h>
int count=10;
pthread_mutex_t mutexCount; 
/*void square()
{
     printf("inc grabbing mutex IN FUNCTION\n");
    pthread_mutex_lock (&mutexCount);
    count=count*count;
     pthread_mutex_unlock (&mutexCount);
      printf("inc RELEASING mutex IN FUNCTION\n");
}*/
void *inc_thread(void *arg)
{
    
    while(1)
    {
    printf("inc grabbing mutex\n");
    pthread_mutex_lock (&mutexCount);
    printf("inc inside cs \n");
    count++;
   // square();
    printf("inc_thread=%d\n",count);
    pthread_mutex_unlock (&mutexCount);
    printf("inc thread releasing mutex\n");
    } 
}

void *dec_thread(void *arg)
{
    while(1)
    {
    printf("dec grabbing mutex\n");
    pthread_mutex_lock (&mutexCount);
    printf("dec inside cs\n");
    count--;
    printf("dec_thread=%d\n",count); 
    pthread_mutex_unlock (&mutexCount);

    }
}

int main()
{
    pthread_t incID;
    pthread_t decID;
    printf("before creating both threads\n");
    pthread_mutex_init(&mutexCount,NULL); 
    pthread_create(&incID,NULL,inc_thread,NULL);
    pthread_create(&decID,NULL,dec_thread,NULL);
    pthread_join(incID,NULL);

    pthread_join(decID,NULL);
     pthread_mutex_destroy(&mutexCount);
    printf("after creating both threads\n");

    return 0;
}
