#include <stdio.h>
#include <string.h>
#define lld long long

int main() {
    lld n = 0, poin = 0, saldo = 0, biaya[10000];
    char isBerguna[50][50];

    scanf("%lld", &saldo);
    scanf("%lld", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %lld", isBerguna[i], &biaya[i]);
    }
    for (int i = 0; i < n; i++) {
        if (strcmp(isBerguna[i], "Iya") == 0) {
            if (biaya[i] <= 100000)
                poin += 1;
            else if (biaya[i] > 100000 && biaya[i] <= 500000)
                poin += 5;
            else if (biaya[i] > 500000 && biaya[i] <= 10000000)
                poin += 20;
            else if (biaya[i] > 10000000 && biaya[i] <= 500000000)
                poin += 35;
            else
                poin += 50;
        } else if (strcmp(isBerguna[i], "Tidak") == 0) {
            if (biaya[i] <= 100000)
                poin -= 1;
            else if (biaya[i] > 100000 && biaya[i] <= 500000)
                poin -= 5;
            else if (biaya[i] > 500000 && biaya[i] <= 10000000)
                poin -= 20;
            else if (biaya[i] > 10000000 && biaya[i] <= 500000000)
                poin -= 35;
            else
                poin -= 50;
        }
        saldo -= biaya[i];
    }

    if (saldo <= 0) {
        printf("Ujana tidak berakhir bahagia.");
        return 0;
    }
    if (poin == 0) {
        printf("Ujana berakhir b aja.");
        return 0;
    }
    if (poin > 0) {
        printf("Ujana berakhir bahagia.");
    } else if (poin < 0) {
        printf("Ujana tidak berakhir bahagia.");
    }
    return 0;
}