#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	
	if(n == 1)
	{
		k = k * 65 / 100;
	}
	else if(n == 2)
	{
		k = k * 55 / 100;
	}
	else if(n == 3)
	{
		k = k * 50 / 100;
	}
	else if(n == 4)
	{
		k = k * 45 / 100;
	}
	else if(n == 5)
	{
		k = k * 60 / 100;
	}
	
	int ongkir = 50000;
	if(k >= 250000)
	{
		ongkir = 0;
	}
	else if(k >= 150000)
	{
		ongkir = ongkir * 50 / 100;
	}
	else if(k >= 50000)
	{
		ongkir = ongkir * 75 / 100;
	}
	
	int total = k + ongkir;
	
	//printf ("%d\n", k);
	//printf ("%d\n", ongkir);
	
	if(total < 300000)
	{
		printf("WOHHHH uangku sisa %d", 300000 - total);
		printf("\nMamaa Daffa bisa kasi THR ke adek adek, tadi totalnya %d", total);
	}
	else if(total == 300000)
	{
		printf("Yeyyy totalnya pas 300000");
		printf("\nMamaa, Daffa udah gede ga jadi minta uang :)");
	}
	else if(total > 300000)
	{
		printf("Mamaa minta uang, uangku kurang %d :((", total - 300000);
		printf("\nTotalnya tadi %d", total);
	}
}

