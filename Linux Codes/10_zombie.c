#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child process %d\n", getpid());
        _exit(0);
    } else {
        wait(0);
        sleep(10); 
        printf("Parent process\n");
    }

    return 0;
}

OUTPUT:

Child process 21345
Parent process
