🔹 b) mv Command in C
(Moves or renames a file)

🛠 Create files first:
$ cat >> file2
1
2
3
^D

$ cat >> jerry
A
B
C
^D

----------------------------------------------

CODE:
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    open(argv[1], O_RDONLY);
    creat(argv[2], S_IWUSR);
    rename(argv[1], argv[2]);
    unlink(argv[1]);  // Optional; `rename()` already replaces it

    return 0;
}

----------------------------------------
OUTPUT:

$ gcc mv_program.c
$ ./a.out file2 jerry

$ cat file2
cat: file2: No such file or directory

$ cat jerry
1
2
3