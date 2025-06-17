#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct msgbuf {
    long mtype;
    char mtext[40];
};

int main() {
    int msqid, len, type, ret;
    struct msgbuf msgread = {0, "\0"};

    msqid = msgget((key_t)7, IPC_CREAT | 0666);

    printf("Enter the message type to read: ");
    scanf("%d", &type);

    len = sizeof(msgread.mtext);

    //Main line
    ret = msgrcv(msqid, &msgread, len, type, 0);

    if (ret == -1) {
        perror("msgrcv");
        exit(1);
    } else {
        printf("Message type = %ld, Message text = %s\n", msgread.mtype, msgread.mtext);
    }

    return 0;
}

OUTPUT:

Enter the message type to read: 5
Message type = 5, Message text = hello

