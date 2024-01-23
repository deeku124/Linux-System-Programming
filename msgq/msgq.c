 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
 #include<stdio.h>
#include<string.h>

struct msgbuf {
               long int mtype;      
               char mtext[20];   
           };
int main()
{
int msgid,snd_flg;
struct msgbuf data;
char buffer[20];

msgid=msgget((key_t)1234,0666|IPC_CREAT);
while(1)
{
printf("enter some data\n");
fgets(buffer,20,stdin);
data.mtype=1;
strcpy(data.mtext,buffer);
//printf("%s\n",data.mtext);
snd_flg=msgsnd(msgid,(void*)&data,20,0);
if(snd_flg==-1)
{
printf("msg queue dat send error\n");
}
else
printf("data sent\n");
}
}



