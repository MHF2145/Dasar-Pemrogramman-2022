#include <stdio.h>
#include <math.h>



int main()
{
    // Your code start here
    long long a,b,penjumlahan,pengurangan,perkalian,pembagian;
    long long max,min;
    scanf ("%ld%ld", &a, &b);
    
    if (a > b)
    {
        max = a;
        min = b;
    }
    else if (a < b)
    {
        max = b;
        min = a;
    }
    else if (a==b)
    {
        max = a;
        min = a;
    }

    penjumlahan = a + b;
    pengurangan = abs (a-b);
    perkalian = a*b;
    pembagian = max % min;

    if (penjumlahan % 2 == 0)
    {
        if(pengurangan % 2 == 0)
        {
            if (perkalian % 2 == 0)
            {
                if (pembagian == 0)
                {
                    printf ("We are soulmates");
                }
                else {printf ("We are NOT soulmates");}
            }
            else {printf ("We are NOT soulmates");}
            
        }
        else {printf ("We are NOT soulmates");}
    }
    else {printf ("We are NOT soulmates");}
    
    return 0;
}