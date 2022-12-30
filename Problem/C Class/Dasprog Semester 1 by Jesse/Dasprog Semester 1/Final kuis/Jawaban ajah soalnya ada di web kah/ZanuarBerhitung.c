#include<stdio.h>

long long zanuar(long long int a, long long int b)
{
    if(b == 0)
    {
        return a;
    }
    return zanuar(b, a % b);
}

long long pangkat(long long int x, long long int y, long long moduluz)
{
    if(y == 0)
    {
        return 1;  
    }

    long long hehe = pangkat(x, y / 2, moduluz);
    hehe = (hehe * hehe) % moduluz;

    if(y & 1)
    {
        hehe = (x * hehe) % moduluz;
    }
    return hehe;
}

int main()
{
    long long int n, k, hitungan = 0, moduluz = 1000000007;

    scanf("%lld %lld", &n, &k);

    for (int i = 0; i < n; i++)
    {
    	hitungan = (hitungan + pangkat(k, zanuar(i,n), moduluz)) % moduluz;
    }

    hitungan = (hitungan*pangkat(n, moduluz - 2, moduluz)) % moduluz;

    printf("%lld", hitungan);
    return 0;
}