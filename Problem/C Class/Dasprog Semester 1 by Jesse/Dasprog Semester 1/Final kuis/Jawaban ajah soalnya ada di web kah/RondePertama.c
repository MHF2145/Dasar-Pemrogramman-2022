#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    char s[n][50];
    int ptba = 0;
    int catto;

    for (int i = 0; i < n; i++)
    {   
        int m, maks = -1000, sekarang = 0;
        scanf("%s %d", s[i], &m);

        int a[m];

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[j]);
        }

        for (int j = 0; j < m; j++)
        {
            sekarang += a[j];

            if (sekarang > maks)
            {
                maks = sekarang;
            }

            if (sekarang < 0)
            {
                sekarang = 0;
            }
        }
        if (i == 0)
        {
            catto = maks;
        } if (catto < maks)
        {
            catto = maks;
            ptba = i;
        }
    }
    printf("%s", s[ptba]);
}