#include <stdio.h>
#include <string.h>

int main() {
    int n = 0, q = 0, nums[1000], results[1000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        results[i] = nums[i];
    }

    scanf("%d", &q);
    int temp[100];
    for (int i = 0; i < q; i++) {
        /*
        char *word = "1 XOR ";
        char *pch = strstr(queries[i], word);
        if (pch) {
            printf("%c\n", pch[6]);
        }
        */
        getchar();
        //scanf("%[^\n]%*c", queries[i]);
        scanf("%d", &temp[i]);

        if (temp[i] == 2) {
            for (int j = 0; j < n; j++) {
                printf("%d ", results[j]);
            }
            printf("\n");
        }
        if (temp[i] == 1) {
            int x = 0;
            char t[5];
            scanf("%s %d", t, &x);
            if (strcmp(t, "AND") == 0) {
                for (int j = 0; j < n; j++) {
                    results[j] = nums[j] & x;
                }
            }
            if (strcmp(t, "OR") == 0) {
                for (int j = 0; j < n; j++) {
                    results[j] = nums[j] | x;
                }
            }
            if (strcmp(t, "XOR") == 0) {
                for (int j = 0; j < n; j++) {
                    results[j] = nums[j] ^ x;
                }
            }
        }
    }
    return 0;
}