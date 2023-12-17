#include<stdio.h>

void reverse(char str1[], char str2[]);

int main() {
    char text[50] = "Hello World";
    char out[50];
    reverse(text, out);
    printf("--|Input: %s|--\n--|output: %s|--\n", text, out);
}

void reverse(char str1[], char str2[]) {
    int length = 0;
    while (str1[length] != '\0') {
        length++;
    } 
    for (int i = 0; i < length; i++) {
        str2[i] = str1[length - 1 - i];
    }
}
