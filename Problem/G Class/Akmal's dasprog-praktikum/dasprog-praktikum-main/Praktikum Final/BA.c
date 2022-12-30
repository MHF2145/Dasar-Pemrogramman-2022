#include<stdio.h>
#include<string.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main()
{
	int n;
	scanf("%d", &n);
	
	int arr[n + 1];
	
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int t;
	scanf("%d", &t);
	
	while(t--)
	{
		int a;
		scanf("%d", &a);
		
		if(a == 2)
		{
			for(i = 0; i < n; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
		
		else
		{
			char str[5];
			int b;
			
			scanf("%s %d", str, &b);
			
			if(strcmp(str, "XOR") == 0)
			{
				for(i = 0; i < n; i++)
				{
					arr[i] = arr[i] ^ b;
				}
			}
			else if(strcmp(str, "AND") == 0)
			{
				for(i = 0; i < n; i++)
				{
					arr[i] = arr[i] & b;
				}
			}
			else
			{
				for(i = 0; i < n; i++)
				{
					arr[i] = arr[i] | b;
				}
			}
		}
	}
}

