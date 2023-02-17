#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	char arr[10];
	scanf("%s", arr);
	
	int i;
	int j;
	for (i = 1; i <= n; i++)
	{
		if(strcmp(arr, "Aku") == 0)
		{	
			for (j = 1; j <= n; j++)
			{
				if((n - i) + j <= n)
				{
					if((i + j) % 2 == 0)
					{
						printf("I ");
					}
					else
					{
						printf("U ");
					}
				}
				else
				{
					printf(" ");
				}
			}
		}
		else if(strcmp(arr, "Kamu") == 0)
		{
			for (j = n; j >= 1; j--)
			{
				if((n - i) + j <= n)
				{
					if((i + j) % 2 == 0)
					{
						printf("I ");
					}
					else
					{
						printf("U ");
					}
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
