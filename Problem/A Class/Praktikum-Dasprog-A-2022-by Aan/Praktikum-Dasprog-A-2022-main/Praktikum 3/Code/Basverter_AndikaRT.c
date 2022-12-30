#include <stdio.h>
#include <string.h>
// #include <math.h>

void basverter(long long a, long long b)
{
    char arr[64];
    int i = 0;

    while (a != 0)
    {
        if (a % b < 10)
        {
            arr[i] = (a % b) + '0';
            a /= b;
            i++;
        }
        else
        {
            arr[i] = (a % b) + 55;
            a /= b; // A = 65
            i++;
        }

        
    }
    // arr[i] = '\0';

    for (int j = i-1; j >= 0; j--)
    {
        printf("%c", arr[j]);
        
    }

    printf("\n");
}

int main()
{
    int test;
    scanf("%d", &test); //input
    long long n[test], basis[test];

    for (int i = 0; i < test; i++)
    {
        scanf("%lld%lld", &n[i], &basis[i]); //input
    }

    for (int i = 0; i < test; i++)
    {
        if (n[i] == 0)
        {
            printf("0\n");
        }
        else
        {
            basverter(n[i], basis[i]);
        }
        
    }

    printf("Ril no fek, ini bwatan Huan");
    return 0;
}