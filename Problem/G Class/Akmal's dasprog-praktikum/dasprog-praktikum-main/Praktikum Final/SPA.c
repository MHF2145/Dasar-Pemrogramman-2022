#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;
const long long m = 10e9 + 7;

ll sum(ll n)
{
  	if(n == 0) return 0;
  	else return n % 10 + sum(n / 10);
} 

void solve(ll n) 
{
  	bool ada;
  	
	ll i;
  	for(i = 0 ; i < n; i++) 
  	{
    	ll tmp = ((2*((((ll)pow(10, i + 1) % m) - 9*i-10 ) % m) / 27) % m);
    	
    	if(sum(tmp) == n)
		{
      		printf("%lld ", i);
      		ada = true;
    	}
  	}
  	
  	if(ada == false)
  	{
  		printf("-1");
	} 
}

int main() 
{
  	ll q;
  	
  	scanf("%lld", &q);
  	
  	ll i;
  	for(i = 0; i < q; i++) 
  	{
	  	ll n;
    	scanf("%lld", &n);
    	
    	solve(n);
    	
    	printf("\n");
  	}
}

