🔹 a) cat Command in C

🛠 Create a sample file first:
$ cat >> F1
Hello
Hi
^D
----------------------------------------------------
CODE:

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd1, n;
    char buf[500], fname[20];

    printf("Enter a file name:\n");
    scanf("%s", fname);

    fd1 = open(fname, O_RDONLY);

    if (fd1 == -1)
        printf("The file does not exist\n");
    else {
        printf("The contents of file %s are:\n", fname);
        n = read(fd1, buf, 500);
        write(1, buf, n);
    }
}

------------------------------------
OUTPUT:

$ gcc cat_program.c
$ ./a.out
Enter a file name:
F1
The contents of file F1 are:
Hello
Hi
