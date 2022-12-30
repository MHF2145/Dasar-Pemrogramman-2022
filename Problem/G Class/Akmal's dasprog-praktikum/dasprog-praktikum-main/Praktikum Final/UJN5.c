#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;

int main()
{
	ll saldo,biaya ,total = 0, poin;
	int n;
	
	scanf("%lld %d", &saldo, &n);
	
	while(n--)
	{
		char str[1001];		
		scanf("%s %lld", str, &biaya);	
		
		if(biaya <= 100000) poin = 1;
		else if(biaya <= 500000) poin = 5;
		else if(biaya <= 10000000) poin = 20;
		else if(biaya <= 500000000) poin = 35;
		else poin = 50;
			
		if(strcmp(str, "Iya") == 0) total += poin;
		else total -= poin;
		saldo -= biaya;
	}
	
	if(total < 0 || saldo <= 0) printf("Ujana tidak berakhir bahagia.\n");
	else if(total == 0) printf("Ujana berakhir b aja.\n"); 
	else printf("Ujana berakhir bahagia.\n");
}

