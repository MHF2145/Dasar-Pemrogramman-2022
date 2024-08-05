#include <stdio.h>

long long hcf(long long a, long long b); // fungsi gcd
long long modulus(long long c, long long d); // fungsi yang dihubungkan
long long mod = 1000000007;
long long E, F;
long long hasil = 0;

int main()
{
    scanf("%lld %lld", &E, &F);
    
    for (int i = 0; i < E; ++i)
    {
        hasil = (hasil + modulus(F, hcf(i, E))) % mod;
    }

    printf("%lld",hasil = (hasil * modulus(E, mod - 2)) % mod);
}


long long hcf(long long a, long long b) // fungsi gcd dari gfg
{
    if (b == 0)
    {
        return a;
    }

    return hcf(b, a % b);
}

long long modulus(long long c, long long d) // fungsi modulus yang ada di soal
{
    if (d == 0)
    {
        return 1;
    }
    
    long long g;
    g = modulus(c, d / 2);
    g = (g * g) % mod;

    if (d & 1)
    {
        g = (c * g) % mod;
    }

    return g;
}


/*refrensi 1:https://www.programiz.com/c-programming/examples/hcf-recursion*/
/*refrensi 2:https://mathworld.wolfram.com/Necklace.html*/