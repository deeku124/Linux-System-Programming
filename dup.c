#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
  
int main()
{
    int file_desc = open("dup.txt", O_WRONLY);    
    if(file_desc < 0)
        {
		printf("Error opening the file\n");
	}
   /* int copy_desc = dup(file_desc);
    write(copy_desc,"This will be output written using copy_desc\n", 46);*/
    write(file_desc,"This will be output written using file_desc\n", 51);
      close(file_desc);
    return 0;
}
