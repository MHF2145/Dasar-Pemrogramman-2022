#include<stdio.h>
#include<stdbool.h>
typedef long long ll;

typedef struct
{
	char s[101];
}gay;

ll max(ll a[], ll n)
{
    ll len = -1000001, end = 0;
 
 	ll i;
    for (i = 0; i < n; i++) 
	{
        end += a[i];
        
        if (len < end) len = end;
 		if (end < 0) end = 0;
    }
    
    return len;
}
 
int main()
{
	ll n, m;
    
    scanf("%lld", &n);
    
	ll skor[100001];
	char name[n + 1][101];
    
    ll i;
	for(i = 0; i < n; i++) 
	{
        scanf("%s %lld", name[i], &m);
        
        ll arr[m + 1];
		ll j;
        for(j = 0; j < m; j++) 
		{
            scanf("%lld", &arr[j]);
        }
        
        skor[i] = max(arr, m);
    }

    ll big = -10000001, idx = -1;
    
    for(i = 0; i < n; i++) 
	{
        if(skor[i] > big) 
		{
            big = skor[i];
            idx = i;
        }
    }

    printf("%s\n", name[idx]);
    
    return 0;
}
