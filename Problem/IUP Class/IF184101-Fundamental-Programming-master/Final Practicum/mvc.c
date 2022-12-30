#include <stdio.h>
#include <string.h>
#define lld long long int
#define hassan res[i]
#define izzul res[i+1]
#define isgay strcmp(res, max) > 0

void bubble_sort(char *arr, lld n) {
    lld i, j;
    char temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int compare(char *a, char *b, lld n) {
    lld i;
    for (i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            return 1;
        } else if (a[i] < b[i]) {
            return 0;
        }
    }
    return 0;
}

int main() {
    lld digits, t = 0;
    char nums[1000], res[1000] = {0}, max[1000] = {0};
    scanf("%s", nums);
    scanf("%lld", &digits);

    t = strlen(nums) - digits + 1;
    for (int i = 0; i < digits; i++) {
        if (res[i] = '0') {
            max[i] = '0';
        }
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < digits; j++) {
            res[j] = nums[i + j];
        }
        for (int i = 0; i < digits - 1; i++) {
            if (hassan < izzul) {
                int p = 0;
                p = hassan;
                hassan = izzul;
                izzul = p;
                i = -1;
            }
            if (isgay) {
                strcpy(max, res);
            }
        }
    }
    for (int i = 0; i < digits; i++) {
        printf("%c", max[i]);
    }
}