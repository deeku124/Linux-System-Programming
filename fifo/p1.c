#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
int fd;
fd=open("fifo",O_WRONLY);
write(fd,"xyz",5);
close(fd);
return 0;
}
