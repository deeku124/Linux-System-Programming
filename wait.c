#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main ()
{
  int i = 0, j = 0; 
  pid_t ret;
  int status;
  ret = fork ();
  if (ret == 0)
    {
  //  exit(1);
      for (i = 0; i < 5; i++)
        printf ("Child: %d\n", i);
      printf ("Child ends\n");
    }
  else
    {
      wait(&status);
   //   waitpid (ret,&status,0);
      printf("status=%d\n",WIFEXITED(status));
      printf ("Parent resumes.\n");
      for (j = 0; j < 5; j++)
        printf ("Parent: %d\n", j);
    }
    return 0;
}
