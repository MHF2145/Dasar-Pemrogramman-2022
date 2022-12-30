#include<stdio.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;
const ll m = 1000000007;

ll gay(ll a, ll b)
{
    ll i;
    for(i = 1; i < b; i++)
	{
        if(((a % b) * (i % b)) % b == 1) return i;      
    }
}
 
int main()
{
 	ll n, k, sum = 1, ans = 0;
    
    scanf("%lld %lld", &n, &k);
    
	ll i, j;
    for(i = 0; i < n; i++)
	{
        ll a = n;
        ll b = i;

        while(a != 0)
		{
            ll tmp = (b % a);
            tmp  %= m;
            b = a;
            a = tmp;
        }
        for (j = 0; j < b; j++)
		{
            sum = ((sum % m) * (k % m)) % m;   
        }
        ans = (ans + sum) % m;
        sum = 1;
    }
    
    ans %= m;
    ans = (ans * gay(n, m)) % m;
    
    printf("%lld\n", ans);
 
    return 0;
}
