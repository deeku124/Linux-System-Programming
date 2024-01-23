#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
int fd;
unsigned char buff[5];
fd=open("fifo",O_RDONLY);
read(fd,buff,5);
printf("%s",buff);
close(fd);
return 0;
}
