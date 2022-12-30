#include <stdio.h>

int n, i, perhitungan, j, angka[1000];

int ngideterosackagak(int *lol){
    while (*lol > 0)
    {
        if (*lol % 15 == 0)
        {
            *lol = *lol - 15;
        } else if (*lol % 11 == 0)
        {
            *lol = *lol - 11;
        } else if (*lol % 11 != 0 && *lol % 15 != 0)
        {
            *lol = *lol - 26;
        }
    }
    return *lol;
}

int main(){

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &angka[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (ngideterosackagak(&angka[i]) == 0)
        {
            printf("YES\n");
        } else if (ngideterosackagak(&angka[i]) != 0)
        {
            printf("NO\n");
        }
    }
    return 0;
}
