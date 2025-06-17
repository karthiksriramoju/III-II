#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd1, fd2, i;
    char *file1, *file2, buf[2];

    file1 = argv[1];
    file2 = argv[2];
    printf("file1 = %s, file2 = %s\n", file1, file2);

    fd1 = open(file1, O_RDONLY);

    fd2 = creat(file2, 0777);

    while ((i = read(fd1, buf, 1)) > 0)
        write(fd2, buf, 1);

    remove(file1); // delete old file

    close(fd1);
    close(fd2);

    return 0;
}

OUTPUT:

$ ./a.out old.txt new.txt
file1 = old.txt, file2 = new.txt
