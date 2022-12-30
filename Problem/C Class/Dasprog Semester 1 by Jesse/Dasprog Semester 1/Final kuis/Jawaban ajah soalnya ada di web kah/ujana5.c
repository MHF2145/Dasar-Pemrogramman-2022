#include <stdio.h>
#include <string.h>

struct ujana
{
    char isBerguna[6];
};

int main() {
    int n;
    int saldo, biaya;
    
    scanf("%d", &saldo);
    int i;
    
    scanf("%d", &n);

    struct ujana ahaha[10000];

    int poin1 = 0, poin2;

    for (i = 0; i < n; i++)
    {
        scanf("%s %d", ahaha[i].isBerguna, &biaya);

        saldo = saldo - biaya;

        if (biaya <= 100000)
        {
            poin2 = 1;
        } else if (biaya > 100000 && biaya <= 500000)
        {
            poin2 = 5; 
        } else if (biaya > 500000 && biaya <= 10000000)
        {
            poin2 = 20; 
        } else if (biaya > 10000000 && biaya <= 500000000)
        {
            poin2 = 35; 
        } else if (biaya > 500000000)
        {
            poin2 = 50;
        }

        if (strcmp(ahaha[i].isBerguna, "Iya") == 0)
        {
            poin1 = poin1 + poin2;
        } else if (strcmp(ahaha[i].isBerguna, "Tidak") == 0)
        {
            poin1 = poin1 - poin2;
        }
    }

    if (saldo > 0)
    {
        if (poin1 > 0)
        {
            printf("Ujana berakhir bahagia.");
        } else if (poin1 == 0)
        {
            printf("Ujana berakhir b aja.");
        } else if (poin1 < 0)
        {
            printf("Ujana tidak berakhir bahagia.");
        }
    } else if (saldo <= 0)
    {
        printf("Ujana tidak berakhir bahagia.");
    }
}


