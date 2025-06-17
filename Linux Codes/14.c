#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int pfds[2];
    char buf[30];

    if (pipe(pfds) == -1) {
        perror("pipe");
        exit(1);
    }

    printf("Writing to file descriptor #%d\n", pfds[1]);
    write(pfds[1], "test", 5);

    printf("Reading from file descriptor #%d\n", pfds[0]);
    read(pfds[0], buf, 5);

    printf("Read \"%s\"\n", buf);

    return 0;
}

OUTPUT:

Writing to file descriptor #4
Reading from file descriptor #3
Read "test"
