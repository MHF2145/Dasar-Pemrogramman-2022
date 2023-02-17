#include <stdio.h>

void rekursi(int a, int b, int c, int d, int counter_mie, int counter_kopi, int sisa_mie, int sisa_kopi)
{
	if(sisa_mie >= a)
	{
		counter_kopi = counter_kopi + sisa_mie / a * b;
		sisa_kopi = sisa_kopi + sisa_mie / a * b;
		sisa_mie = sisa_mie - sisa_mie / a * a;
	}
	if(sisa_kopi >= c)
	{
		counter_mie = counter_mie + sisa_kopi / c * d;
		sisa_mie = sisa_mie + sisa_kopi / c * d;
		sisa_kopi = sisa_kopi - sisa_kopi / c * c;
	}
	if(sisa_mie < a && sisa_kopi < c)
	{
		printf("%d %d\n", counter_mie, sisa_mie);
		printf("%d %d\n", counter_kopi, sisa_kopi);
		return;
	}
	rekursi(a, b, c, d, counter_mie, counter_kopi, sisa_mie, sisa_kopi);
}

int main()
{
	int a;
	scanf("%d", &a);
	int b;
	scanf("%d", &b);
	int c;
	scanf("%d", &c);
	int d;
	scanf("%d", &d);
	int x;
	scanf("%d", &x);
	rekursi(a, b, c, d, x, 0, x, 0);
}
