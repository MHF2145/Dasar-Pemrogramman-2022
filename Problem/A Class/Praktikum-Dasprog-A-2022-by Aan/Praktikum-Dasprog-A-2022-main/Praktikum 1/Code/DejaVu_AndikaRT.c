#include <stdio.h>



int main()
{
    // Your code start here
    unsigned long long n,hasil;
    unsigned long long a,b,c;
    unsigned long long total_1;
    scanf ("%llu", &n);

    a = n;
    b = n+1;
    c = 2*n+1;

    if (n < 6)
    {
        hasil = (a*b*c)/6;
        hasil %= 1000000007;
        printf ("%llu", hasil);
    }
    else
    {
        if (a % 2 == 0)
        {
            a /= 2;
            if (a % 3 == 0)
            {
                a /= 3;
            }
            else if (b % 3 == 0)
            {
                b /= 3;
            }
            else if (c % 3 == 0)
            {
                c /= 3;
            }
        }

        else if (b % 2 == 0)
        {
            b /= 2;
            if (a % 3 == 0)
            {
                a /= 3;
            }
            else if (b % 3 == 0)
            {
                b /= 3;
            }
            else if (c % 3 == 0)
            {
                c /= 3;
            }
        }

        else if (c % 2 == 0)
        {
            c /= 2;
            if (a % 3 == 0)
            {
                a /= 3;
            }
            else if (b % 3 == 0)
            {
                b /= 3;
            }
            else if (c % 3 == 0)
            {
                c /= 3;
            }
        }

        // JEDA

        a %= 1000000007;
        b %= 1000000007;
        c %= 1000000007;

        hasil = (a*b)%1000000007;
        total_1 = (hasil*c)%1000000007;
        printf ("%llu",total_1);

        

    }

    return 0;
}
    