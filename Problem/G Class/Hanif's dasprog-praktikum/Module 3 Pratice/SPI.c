#include <stdio.h>

int nesya(int q, int n)
{
    // pokoknya begitu
    n++;
    return q > 1 ? (nesya(q-1, n)+ n - 1) % q + 1 : 1;
}

int main ()
{
    // brp line terus lanjutannya brp banyak
    int line = 5, many, n;
    int idk = 0;
    scanf("%d", &line);
    for (int i = 0; i < line; i++) //terus disini biar bisa input lagi
    {
        scanf("%d", &many);
        // printf("%d\n", nesya(many, idk));
    }

        for (int i = 0; i < line; i++) //terus disini biar bisa input lagi
    {
        // scanf("%d%d", &many, &n);
        printf("%d\n", nesya(many, idk));
    }
    // while (--line)
    // {
    //     scanf("%d%d",&many, &n);
    //     printf("%d\n", nesya(many, n));
    // } 
}
