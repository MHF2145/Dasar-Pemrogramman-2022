#include <stdio.h>
#include <math.h>
long long mod = 1000000007;

long long fast_exponent(long long a, long long b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a % mod;
	}
	long long hasil = fast_exponent(a, b / 2) % mod;
	if(b % 2 == 0)
	{
		return (hasil * hasil) % mod;
	}
	else
	{
		return (((hasil * hasil) % mod) * a) % mod;
	}
}

int gcd(int a, int b)
{
    if (b == 0)
    {
    	return a;
	}
    return gcd(b, a % b);
}

int main()
{
	int N;
	scanf("%d", &N);
	int K;
	scanf("%d", &K);
    long long hasil = 0;
    
    int i;
    for (i = 0; i < N; i++)
	{
        int hasil_gcd = gcd(i, N);
        hasil = hasil % mod + fast_exponent(K, hasil_gcd);
    }
    hasil = (hasil * fast_exponent(N, mod - 2)) % mod;
    printf("%lld\n", hasil);
}
