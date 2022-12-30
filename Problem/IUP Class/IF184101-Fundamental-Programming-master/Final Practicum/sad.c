#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        bool isMultiple = false;
        for (int j = 0; j <= arr[i] / 11; j++) {
            int askdjaksdj = (arr[i] - 11 * j) / 15;
            if (11 * j + 15 * askdjaksdj == arr[i]) {
               isMultiple = true;
               break;
            }
        }
        if (isMultiple) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}