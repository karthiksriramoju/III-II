#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char ch[1];

    fd = open(argv[1], O_RDONLY);

    printf("Contents of the file %s:\n", argv[1]);
    while (read(fd, ch, 1) > 0)
        printf("%c", ch[0]);
    close(fd);
    
    return 0;
}

OUTPUT:

$ ./a.out file.txt
Contents of the file file.txt:
Hello World!
