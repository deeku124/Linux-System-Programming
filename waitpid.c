#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main ()
{
  int i = 0, j = 0; 
  pid_t ret,ret1;
  int status;
  ret = fork ();
  ret1=fork();
  if (ret == 0)
    {
     // exit(1);
     printf ("Child1 starts\n");
     printf ("Child1 ends\n");
    }
  else if(ret1==0)
    { 
      printf ("Child2 starts\n");
      printf ("Child2 ends\n");
    }
  else
   {
      waitpid (ret,&status,0);
     // printf("status of child with pid %d is %d",ret1,WIFEXITED(status));
      printf ("parent starts");
      printf ("parent ends\n");
   }
return 0;
}
