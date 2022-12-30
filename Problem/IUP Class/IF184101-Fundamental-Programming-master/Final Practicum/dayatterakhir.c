#include <stdio.h>

int main() {
    int n, arr[10000];
    scanf("%d", &n);

    for (int i = 0; 1; i++) {
        if (n == 0) {
            break;
        }

        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i]);
        }
    }

    // print out all the values in the array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}

// sort the array og glass and return the minimal changes need to be done.

