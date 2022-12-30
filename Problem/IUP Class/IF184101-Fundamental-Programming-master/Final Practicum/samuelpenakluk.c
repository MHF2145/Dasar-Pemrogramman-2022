#include <stdio.h>

int main() {
    int n, i, input;
    int inp[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
    }
    for (int i = 0; i < n; i++) {
        if (inp[i] % 2 == 0) {
            printf("%d", 2 * inp[i] - 1);
        } else {
            printf("%d", 2 * inp[i] + 1);
        }
        printf("\n");
    }
    return 0;
}