#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    for (int ask = 0; ask < t; ask++) {
        int n[100], m[100];
        char type[100];
        
        for (int i = 0; i < t; i++) {
            scanf(" %c %d %d", &type[i], &n[i], &m[i]);
            getchar();
        }
        
        // type = if A then pattern starts with ., if B then pattern starts with -
        // n = how many lines
        // m = how many chars of pattern in each line

        for (int no = 0; no < t; no++) {
            printf("Pattern no : %d\n", no + 1);

            if (type[no] == 'A') {
                for (int i = 1; i <= n[no]; i++) {
                    // make the spaces for odd and even step
                    if (i % 2 != 0) {
                        printf(" ");
                    }

                    for (int j = 0; j <= m[no] - 1; j++) {
                        if (j % 2 == 0) {
                            printf(".");
                        } else {
                            printf("-");
                        }
                    }
                    printf("\n");
                }
            } else if (type[no] == 'B') {
                for (int i = 1; i <= n[no]; i++) {
                    // make the spaces for odd and even step
                    if (i % 2 == 0) {
                        printf(" ");
                    }

                    for (int j = 0; j <= m[no] - 1; j++) {
                        if (j % 2 == 0) {
                            printf("-");
                        } else {
                            printf(".");
                        }
                    }
                    printf("\n");
                }
            }
        }
        break;
    }
    return 0;
}