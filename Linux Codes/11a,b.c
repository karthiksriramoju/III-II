#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msgbuf {
    long mtype;
    char mtext[40];
};

int main() {
    int msqid, len, ret;
    struct msgbuf msgsend = {0, "\0"};

    msqid = msgget((key_t)7, IPC_CREAT | 0666);

    printf("Enter msg type: ");
    scanf("%ld", &msgsend.mtype);

    printf("Enter msg text: ");
    scanf("%s", msgsend.mtext);

    len = strlen(msgsend.mtext);

    //Main line
    ret = msgsnd(msqid, &msgsend, len, 0);


    if (ret == -1) {
        perror("msgsnd");
        exit(1);
    } else {
        printf("Message sent successfully.\n");
    }

    return 0;
}


OUTPUT:

Enter msg type: 5
Enter msg text: hello
Message sent successfully.
