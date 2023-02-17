#include <stdio.h>

int main()
{
	long long a;
	scanf("%lld", &a);
	long long b;
	scanf("%lld", &b);
	long long c;
	scanf("%lld", &c);
	long long d;
	scanf("%lld", &d);
	long long e;
	scanf("%lld", &e);
	long long f;
	scanf("%lld", &f);
	long long g;
	scanf("%lld", &g);
	
	int counter = 0;
	
	a = a % 16;
	if(a % 2 == 1)
	{
		counter++;
	}
	if(a % 4 >= 2)
	{
		counter++;
	}
	if(a % 8 >= 4)
	{
		counter++;
	}
	if(a % 16 >= 8)
	{
		counter++;
	}
	
	//printf ("%d\n", counter);
	
	b = b % 16;
	if(b % 2 == 1)
	{
		counter++;
	}
	if(b % 4 >= 2)
	{
		counter++;
	}
	if(b % 8 >= 4)
	{
		counter++;
	}
	if(b % 16 >= 8)
	{
		counter++;
	}
	
	//printf ("%d\n", counter);
	
	c = c % 16;
	if(c % 2 == 1)
	{
		counter++;
	}
	if(c % 4 >= 2)
	{
		counter++;
	}
	if(c % 8 >= 4)
	{
		counter++;
	}
	if(c % 16 >= 8)
	{
		counter++;
	}
	
	//printf ("%d\n", counter);
	
	d = d % 16;
	if(d % 2 == 1)
	{
		counter++;
	}
	if(d % 4 >= 2)
	{
		counter++;
	}
	if(d % 8 >= 4)
	{
		counter++;
	}
	if(d % 16 >= 8)
	{
		counter++;
	}
	
	//printf ("%d\n", counter);
	
	e = e % 16;
	if(e % 2 == 1)
	{
		counter++;
	}
	if(e % 4 >= 2)
	{
		counter++;
	}
	if(e % 8 >= 4)
	{
		counter++;
	}
	if(e % 16 >= 8)
	{
		counter++;
	}
	
	//printf ("%d\n", counter);
	
	f = f % 16;
	if(f % 2 == 1)
	{
		counter++;
	}
	if(f % 4 >= 2)
	{
		counter++;
	}
	if(f % 8 >= 4)
	{
		counter++;
	}
	if(f % 16 >= 8)
	{
		counter++;
	}
	
	//printf ("%d\n", counter);
	
	g = g % 16;
	if(g % 2 == 1)
	{
		counter++;
	}
	if(g % 4 >= 2)
	{
		counter++;
	}
	if(g % 8 >= 4)
	{
		counter++;
	}
	if(g % 16 >= 8)
	{
		counter++;
	}
	
	//printf ("%d\n", counter);
	
	if(counter > 14)
	{
		printf("Jangan Rakus bang :3");
	}
	else if(counter == 14)
	{
		printf("Nikmati aja bang :\\");
	}
	else
	{
		if(counter % 2 == 0)
		{
			printf("Semangat Bang :(");
		}
		else
		{
			printf("Hallo Bang");
		}
	}
}
