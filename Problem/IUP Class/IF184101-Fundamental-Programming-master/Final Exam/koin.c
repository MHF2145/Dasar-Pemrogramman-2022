#include <stdio.h>
#include <string.h>
#define lld long long int

// print the nth prime number
int prime_num_sequence(int n) {
    int count = 0, i = 2;
    while (count < n) {
        int is_prime = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            count++;
        }
        i++;
    }
    return i - 1;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

char matrix_array[1000][1000] = {0};
int i, d, mode[10000], rows[10000], cols[10000];
void getPattern(int mode) {
    for (int r = 0; r < rows[i]; r++) {
        for (int c = 0; c <= cols[i]; c++) {
            // save all the values in the matrix
            if (mode == 1) {
                if (c == r + 1) {
                    // save the values in the matrix
                    for (int j = 0; j < 3; j++) {
                        strcat(matrix_array[i], " ");
                    }
                } else if (c == cols[i]) {
                    continue;
                } else {
                    strcat(matrix_array[i], "*");
                }
            } else if (mode == 2) {
                int fib = fibonacci(r + 1);
                if (c == r + 1) {
                    // convert fibonacci number to string
                    char fib_str[100];
                    sprintf(fib_str, "%d", fib);
                    strcat(matrix_array[i], " ");
                    strcat(matrix_array[i], fib_str);
                    strcat(matrix_array[i], " ");
                } else if (c == cols[i]) {
                    continue;
                } else {
                    strcat(matrix_array[i], "*");
                }
            } else if (mode == 3) {
                if (c == r + 1) {
                    // prime number sequence
                    int prime = prime_num_sequence(r + 1);
                    // convert prime number to string
                    char prime_str[100];
                    sprintf(prime_str, "%d", prime);
                    strcat(matrix_array[i], " ");
                    strcat(matrix_array[i], prime_str);
                    strcat(matrix_array[i], " ");
                } else if (c == cols[i]) {
                    continue;
                } else {
                    strcat(matrix_array[i], "*");
                }
            }
        }
        // save \n in the matrix
        strcat(matrix_array[i], "\n");
    }
    //printf("\n");
}

// create avicii thunder logo
int main() {
    scanf("%d", &d);
    for (i = 0; i < d; i++) {
        // scanf for the rows and cols
        scanf("%d %d %d", &mode[i], &rows[i], &cols[i]);
        getPattern(mode[i]);
        // print the matrix
        for (int j = 0; j < strlen(matrix_array[i]); j++) {
            printf("%c", matrix_array[i][j]);
        }
        printf("\n");
    }
}