#include <stdio.h>
#include <string.h>

char str[100];

void sortChars() {
    int i, j, len = strlen(str);
    char tmp;
    for (i = 0; i < len - 1; i++)
        for (j = i + 1; j < len; j++)
            if (str[i] > str[j]) {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
}

int main() {
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    sortChars();
    printf("%s\n", str);
    return 0;
}
