#include <stdio.h>
#include <string.h>

void sortString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;\
            }
        }
    }
}

int main() {
    char input[100];
    printf("Enter the string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    
    sortString(input);
    printf("%s\n", input);
    return 0;
}
