#include<stdio.h>

void reverse(char str1[50], char str2[50]);

int main() {
    char text[50] = "I Love You";
    char out[50];
    reverse(text, out);
    printf("Original: %s\nReversed: %s\n", text, out);
    return 0;
}

void reverse(char str1[50], char str2[50]) {
    // Find the length of the string
    int length = 0;
    while (str1[length] != '\0') {
        length++;
    }

    // Copy characters in reverse order to str2
    for (int i = 0; i < length; i++) {
        str2[i] = str1[length - 1 - i];
    }

    // Add null terminator to the end of str2
    str2[length] = '\0';
}
