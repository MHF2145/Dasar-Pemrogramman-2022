#include <stdio.h>

int main()
{
    // Your code goes here
    int n;
    scanf ("%d", &n);

    // memasukkan nilai x1
    int x1[11];
    int semar[11], gareng[11], petruk[11], bagong[11];
    for (int i = 1; i<=n; i++)
    {
        scanf("%d",&x1[i]);
        semar[i] = x1[i] >> 24;

        gareng[i]= (x1[i] << 8) >> 24;
        // printf ("%c", gareng[i]);

        petruk[i]= (x1[i] << 16) >> 24;
        // printf ("%c", petruk[i]);

        bagong[i]= (x1[i] << 24) >> 24;
        // printf ("%c", bagong[i]);

    }

    for (int j = 1; j <= n; j++)
    {
        printf ("%c%c%c%c", semar[j], gareng[j], petruk[j], bagong[j]);
    }

    
    // bit shifting tiap elemen x1
    
    // for (int j = 1; j <= n;)
    return 0;
}