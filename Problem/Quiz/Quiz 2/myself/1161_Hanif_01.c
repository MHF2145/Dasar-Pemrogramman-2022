#include <stdio.h>
#include <math.h>


int main()
{
    int z, y, n = 1;

    scanf("%d",&z);
    
    while(z--)
    {
        scanf("%d",&y);
        n *= y;
    }
    printf("%d\n",n);
    
    return 0;
}

