#include<stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main()
{
	int n;
	scanf("%d", &n);
	
	while(n--)
	{
		int a;
		scanf("%d", &a);
		
		if(a%2 == 0)
		{
			printf("%d\n", 2 * a - 1);
		}
		else
		{
			printf("%d\n", 2 * a + 1);
		}
	}
}

