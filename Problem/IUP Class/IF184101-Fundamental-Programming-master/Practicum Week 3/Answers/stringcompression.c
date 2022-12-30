#include <stdio.h>
#include <string.h>

int main() {
    int num;
    char inp[1000][1000];
    scanf("%d", &num);

    // ask for input for the ith index of string in array
    for (int i = 0; i < num; i++) {
        scanf("%s", inp[i]);
    }

    // order the string alphabetically
    for (int i = 0; i < num; i++) {
        char temp;
        int n = strlen(inp[i]);
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // swap if the character at j is greater than the character at k
                if (inp[j] > inp[k]) {
                    temp = inp[i][j];
                    inp[i][j] = inp[i][k];
                    inp[i][k] = temp;
                }
            }
        }
        
        // counter for how many times the character is repeated
        int count[26] = {0};
        for (int j = 0; j < n; j++) {
            count[inp[i][j] - 'a']++;
        }

        // print the compressed string according to format
        for (int j = 0; j < 26; j++) {
            if (count[j] > 1) {
                printf("[%d%c]", count[j], j + 'a');
            } else if (count[j] == 1) {
                printf("%c", j + 'a');
            }
        }
        printf("\n");
    }

    return 0;
}