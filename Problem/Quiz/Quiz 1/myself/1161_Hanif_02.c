#include<stdio.h>

int diliat(int a);

int main()
{
    int a;

    scanf("%d", &a);
    printf("%d\n", diliat(a));

    return 0;
}

int diliat(int a)
{
    int b, c, pohon, total = 0;

    for(b = 0; b < a; b++) 
    {
        for(c = 0; c < a; c++)
        {
            scanf("%d", &pohon);

            if(pohon == 1) 
            {
                total++;
            }
        }
    }

    return total;
}