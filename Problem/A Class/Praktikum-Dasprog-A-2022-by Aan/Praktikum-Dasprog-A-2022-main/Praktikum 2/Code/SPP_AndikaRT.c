#include <stdio.h>
// #include <string.h>
// #include <math.h>

int main()
{
    // Your code goes here
    int a;
    int prima[78499];
    int poin;
    int x[78499], y[78499];

    scanf("%d", &a); // input jumlah tes

    prima[1] = 2; // 2 sudah pasti bilangan prima
    prima[2] = 3; // 3 sudah pasti bilangan prima
    // printf("%d\n%d\n", prima[1], prima[2]);
    int z = 3;

    // mengumpulkan bilangan prima sampai 1 juta
    for (int i = 5; i <= 1000000; i++)
    {
        poin = 1;
        if (i % 2 == 0 || i % 3 == 0)
        {
            continue;
        }

        for (int j = 5; j * j <= i; j = j + 6)
        {
            if (i % j == 0 || i % (j + 2) == 0)
            {
                poin = 0;
                break;
            }
        }

        if (poin == 0)
        {
            continue;
        }
        else
        {
            prima[z] = i;
            // printf("\n%d", prima[z]);
            z++;
        }
    }

    // input dari prima ke x sampai prima ke y
    for (int q = 1; q <= a; q++)
    {
        scanf ("%d%d", &x[q], &y[q]);
    }

    for (int w = 1; w <= a; w++)
    {
        printf("Test Case #%d :\n", w);
        for (int r = x[w]; r <= y[w]; r++)
        {
            printf("%d\n", prima [r]);
        }
    }
    
    return 0;
}