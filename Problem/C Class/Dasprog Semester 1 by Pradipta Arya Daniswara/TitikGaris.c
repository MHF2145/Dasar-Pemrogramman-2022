#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);
	long long m;
	scanf("%lld", &m);
	
	int min = n - 1;
	int max;
	if(n % 2 == 1)
	{
		max = n * ((n - 1) / 2);
	}
	else
	{
		max = n * ((n - 1) / 2) + n / 2;
	}
	
	/*printf ("%d\n", min);
	printf ("%d\n", max);*/
	
	if(m >= min && m <= max)
	{
		printf("bisa dong");
	}
	else
	{
		printf("mana bisa bang");
	}
}
