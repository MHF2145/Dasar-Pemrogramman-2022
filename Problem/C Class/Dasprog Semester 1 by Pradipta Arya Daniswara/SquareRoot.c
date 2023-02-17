#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	printf("Input a number : ");
	float N;
	scanf("%f", &N);
	
	float NG;
	float LG = 1.0;
	while(true)
	{
		NG = 0.5 * (LG + N / LG);
		if(fabs(NG - LG) < 0.005)
		{
			printf("Square root of number : %f\n", NG);
			break;
		}
		LG = NG;
	}
}
