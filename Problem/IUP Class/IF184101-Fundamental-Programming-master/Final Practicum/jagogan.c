#include <stdio.h>

int main() {
    int n;
    int inp[10000], nums[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        for (int j = 0; j < i; j++) {
            scanf("%d", &nums[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) {
            printf("%d", 2 * nums[i] - 1);
        } else {
            printf("%d", 2 * nums[i] + 1);
        }
        printf("\n");
    }
    return 0;
}