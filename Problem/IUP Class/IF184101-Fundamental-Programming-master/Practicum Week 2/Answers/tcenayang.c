#include <stdio.h>

int main() {
    /*
    d = how many inputs
    row = how many row for avicii logo
    col = how many cols for avicii logo
    message =  message to encrypt
    */
    int d;
    scanf("%d", &d);

    // assign values all to zero so that it will not have any garbage value
    int row[1000] = {0}, col[1000] = {0}, SN[1000] = {0};
    char message[1000][1000];

    for (int i = 0; i < d; i++) {
        scanf("%d %d", &row[i], &col[i]);
        getchar();
    }
    for (int i = 0; i < d; i++) {
        scanf("%d", &SN[i]);
        getchar();
        scanf(" %[^\n]", message[i]);
    }

    for (int i = 0; i < d; i++) {
        // encrypt the message
        int chr = 0;
        while (message[i][chr] != '\0') {
            if (message[i][chr] >= 'a' && message[i][chr] <= 'z') {
                message[i][chr] = (message[i][chr] - 'a' + SN[i]) % 26 + 'a';
            } else if (message[i][chr] >= 'A' && message[i][chr] <= 'Z') {
                message[i][chr] = (message[i][chr] - 'A' + SN[i]) % 26 + 'A';
            }
            chr++;
        }
        printf("%s\n", message[i]);
    }

    for (int i = 0; i < d; i++) {
        // print avicii logo
        for (int r = 0; r < row[i]; r++) {
            for (int c = 0; c < col[i]; c++) {
                if (c == r + 1) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}