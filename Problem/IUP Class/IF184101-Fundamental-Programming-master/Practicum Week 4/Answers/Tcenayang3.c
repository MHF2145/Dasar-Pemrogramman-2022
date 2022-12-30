#include <stdio.h>
#include <string.h>
#define hassan printf("\n")

// function to reverse a string by each character
// input: string
void reverse(char *str) {
    // length of the string - 1
    // because the last character is '\0'
    int len = strlen(str) - 1;
    // decrement loop from the end of the string
    for (int i = len; i >= 0; i--) {
        // print the character
        printf("%c", str[i]);
    }
}

int main() {
    // two dimensional array of strings
    char str[1000][1000];
    // k as an index for a while loop
    int k = 0;
    while (1) {
        // get the string
        scanf(" %s", str[k]);
        // if the string is "exit" then break the loop
        if (strcmp(str[k], "exit") == 0)
            break;
        ++k;
    }
    
    // for each string in the array
    for (int i = 0; i < k; i++) {
        // call the function to reverse the string
        // and print the reversed string
        reverse(str[i]);
        hassan;
    }

    return 0;
}