#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// create avicii thunder logo
int main() {
    int d, rows[10000], cols[10000];
    scanf("%d", &d);

    for (int i = 0; i < d; i++) {
        // scanf for the rows and cols
        scanf("%d %d", &rows[i], &cols[i]);
    }
    
    // print the avicii thunder
    for (int i = 0; i < d; i++) {
        for (int r = 0; r < rows[i]; r++) {
            for (int c = 0; c <= cols[i]; c++) {
                int fib = fibonacci(r + 1);
                if (c == r + 1) {
                    printf(" %d ", fib);
                }
                // else if we reached the last * in the row, print a new line
                else if (c == cols[i]) {
                    continue;
                }
                // else print a *
                else {
                    printf("*");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}