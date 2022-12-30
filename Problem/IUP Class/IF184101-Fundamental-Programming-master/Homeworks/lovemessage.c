#include <stdio.h>
#include <string.h>

void sort_and_clean(char *str) {
    int j;
    char key;
    int n = strlen(str);
    // insertion sort starts at second index
    for (int i = 1; i < n; i++) {
        // set a key for our cur index
        key = str[i];
        // and j as an index for the index cur - 1
        j = i - 1;
        // while loop to check the condition for a swap to happen
        // if the char before is bigger in ascii than the cur char
        while (j >= 0 && str[j] > key) {
            // then swap!
            str[j + 1] = str[j];
            // this is just to keep the while loop runnin properly
            // if we dont set this, our while loop will go until j <= key
            j = j - 1;
        }
        // this is to place the key after the element smaller than it
        // i mean like the key has to follow the index before you know
        str[j + 1] = key;
    }

    // removing whitespaces happen here
    // check for each char if it is ' ', then skip
    // else print
    for (int i = 0; i <= n; i++) {
        if (str[i] != ' ') {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

int main() {
    // declare a 2d array of strings
    char str[1000][1000];
    // declare lines to count how many lines
    int lines = 0;
    
    // basically a while loop but we will have index
    for (int i = 0; 1; i++) {
        // scanf for each line
        scanf("%[^\n]s", str[i]);
        getchar();
        lines++;
        // if we type exit, we ded
        if (strcmp(str[i], "exit") == 0) {
            break;
        }
    }

    // lines - 1 cus its cool
    // jk cus we don't need to sort the last line which is "exit"
    for (int i = 0; i < lines - 1; i++) {
        sort_and_clean(str[i]);
    }

    return 0;
}