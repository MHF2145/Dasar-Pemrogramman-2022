#include <stdio.h>

int main ()
{
    // brp line terus lanjutannya brp banyak
    int line = 5, many, n;
    
    while(line--)
    {
        scanf("%d %d", &many, &n);

        if(n <= many) 
        {
            printf("%d\n", n);
        }

        while(n > many)
        {
            n = n - many;

            if(n <= many) printf("%d\n", n);
        }
    }
}
