#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>

 struct msgbuf {
               long int mtype;       /* message type, must be > 0 */
               char mtext[20];    /* message data */
           };
int main()
{
int msgid,rcv_flg;
struct msgbuf data;
char buffer[20];

msgid=msgget((key_t)1234,0666|IPC_CREAT);
while(1)
{
rcv_flg=msgrcv(msgid,(void*)&data,20,0,0);
if(rcv_flg==-1)
{
printf("recv error\n");
}
else
{
printf("%s\n",data.mtext);
}
}
msgctl(msgid,IPC_RMID,0);
}

