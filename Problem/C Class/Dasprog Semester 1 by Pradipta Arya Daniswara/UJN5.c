#include <stdio.h>

int main()
{
	long long saldo;
	scanf("%lld", &saldo);
	int n;
	scanf("%d", &n);
	int poin = 0;
	
	int i;
	for(i = 1; i <= n; i++)
	{
		char berguna[10];
		scanf("%s", &berguna);
		long long biaya;
		scanf("%lld", &biaya);
		
		if(strcmp(berguna, "Iya") == 0)
		{
			if(biaya <= 100000)
			{
				poin = poin + 1;
			}
			else if(biaya <= 500000)
			{
				poin = poin + 5;
			}
			else if(biaya <= 10000000)
			{
				poin = poin + 20;
			}
			else if(biaya <= 500000000)
			{
				poin = poin + 35;
			}
			else
			{
				poin = poin + 50;
			}
			
			saldo = saldo - biaya;
		}
		else if(strcmp(berguna, "Tidak") == 0)
		{
			if(biaya <= 100000)
			{
				poin = poin - 1;
			}
			else if(biaya <= 500000)
			{
				poin = poin - 5;
			}
			else if(biaya <= 10000000)
			{
				poin = poin - 20;
			}
			else if(biaya <= 500000000)
			{
				poin = poin - 35;
			}
			else
			{
				poin = poin - 50;
			}
			
			saldo = saldo - biaya;
		}
	}
	
	if(saldo <= 0)
	{
		printf("Ujana tidak berakhir bahagia.\n");
	}
	else
	{
		if(poin > 0)
		{
			printf("Ujana berakhir bahagia.\n");
		}
		else if(poin < 0)
		{
			printf("Ujana tidak berakhir bahagia.\n");
		}
		else
		{
			printf("Ujana berakhir b aja.\n");
		}
	}
}
