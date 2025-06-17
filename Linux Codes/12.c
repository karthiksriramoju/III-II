#include <stdio.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define KEY 1216

int semid, fd;

void lock() {
    struct sembuf sb = {0, -1, 0};
    semop(semid, &sb, 1);
}

void unlock() {
    struct sembuf sb = {0, 1, 0};
    semop(semid, &sb, 1);
}

int main() {
    char buf[10];
    int seq;

    semid = semget(KEY, 1, IPC_CREAT | 0666);

    semctl(semid, 0, SETVAL, (union semun){.val = 1});

    fd = open("seq_file", O_RDWR);

    for (int i = 0; i < 2; i++) {
        lock();

        lseek(fd, 0, SEEK_SET);

        read(fd, buf, 10);

        seq = atoi(buf);

        printf("PID: %d, Seq: %d\n", getpid(), seq++);

        sprintf(buf, "%d\n", seq);

        lseek(fd, 0, SEEK_SET);

        write(fd, buf, strlen(buf));

        unlock();

        sleep(1);
    }

    return 0;
}
