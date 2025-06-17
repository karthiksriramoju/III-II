#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int sl = symlink(argv[1], argv[2]);

    if (sl == 0)
        printf("Soft Link created successfully.\n");
    else
        perror("symlink");

    return 0;
}

OUTPUT:

$ ./a.out original.txt softlink.txt
Soft Link created successfully.
