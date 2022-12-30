#include <stdio.h>
#include <math.h>


int main()
{
    // Your code start here
    long long n,jumlah;
    scanf ("%lld", &n);

    jumlah = (pow(n,2)+n)/2;
    jumlah = pow(jumlah, 2);

    printf ("%lld", jumlah);
    
    
    return 0;
}