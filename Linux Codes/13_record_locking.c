#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0}; // Write lock
    int fd;

    fl.l_pid = getpid(); // Set current process ID

    if((fd = open("test.c", O_RDWR)) == -1) {
        perror("file not found");
        exit(1);
    }

    printf("Press <RETURN> to try to get lock: ");
    getchar();

    printf("Trying to get lock...\n");

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl - locking");
        exit(1);
    }

    printf("Got lock!\n");

    printf("Press <RETURN> to unlock: ");
    getchar();

    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl - unlocking");
        exit(1);
    }

    printf("Unlocked.\n");

    close(fd);
    return 0;
}

OUTPUT:

Press <RETURN> to try to get lock: 
Trying to get lock...
Got lock!
Press <RETURN> to unlock: 
Unlocked.
