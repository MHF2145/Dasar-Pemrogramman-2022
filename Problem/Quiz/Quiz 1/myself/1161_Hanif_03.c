#include <stdio.h>
#include <math.h>

int potongkue(int a);

int main()
{
    int a, b;
    
    scanf("%d", &b);
    while(b--)
    {
        scanf("%d", &a);
        printf("%d\n", potongkue(a));
    }

    return 0;
}

int potongkue(int a)
{
    if(a <= 0) 
    {
        return 0;
    }

    return ceil(log2(a));
}
