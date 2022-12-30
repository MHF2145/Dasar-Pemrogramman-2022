#include<stdio.h>

int Panjang(int a, int b);

int main()
{
    int a, b, c;
    while(1)
    {
        scanf("%d%d", &a, &b);
        if(a == 0 && b == 0) 
        {
            break;
        }
        if(a > b) 
        {
            c = Panjang(a, b);
        }
        else 
        {
            c = Panjang(b, a);
        }
        printf("%d\n", (c / a) + (c / b));
    }
    return 0;
}

int Panjang(int a, int b)
{
    int c;
    if(a % b == 0) 
    {
        return a;
    }
    if(a == b + 1) 
    {
        return a * b;
    }
    for(c = a + 1; c % a != 0 || c % b != 0 ; c++);
    {
        return c;
    }
}