#include<stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;

ll modex(ll base, ll ex, ll mod)
{
    ll res = 1;

    while(ex > 0) 
	{
        if(ex % 2 == 1) res = (res * base);

        ex /= 2;
    	base = (base * base);
    }
    return res % mod;
}

int main()
{
	ll t, a, b, n, m;
	
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
		
		ll i, ans = 0;
		for(i = 0; i < n; i++)
		{
			ans += modex(a, i, m) * modex(i, b, m);
		}
		
		printf("%lld\n", ans % m);
	}
}

