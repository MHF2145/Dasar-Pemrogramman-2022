#include <stdio.h>

int main()
{
	printf("Number of iterations : ");
	int iteration;
	scanf("%d", &iteration);
	
	float pi = 0.0;
	int divider = 1;
	
	int i;
	for(i = 1; i <= iteration; i++)
	{
		if(i % 2 == 0)
		{
			pi = pi - (1.0 / divider);
		}
		else
		{
			pi = pi + (1.0 / divider);
		}
		divider = divider + 2;
	}
	
	pi = pi * 4;
	printf("Value of pi : %f\n", pi);
}
