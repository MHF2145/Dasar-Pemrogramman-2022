#include<stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
int solve(int arr[], int n)
{
    int i, j, ans = 0;
    for (i = 0; i < n - 1; i++)
    {
    	for (j = 0; j < n - i - 1; j++)
    	{
    		if (arr[j] > arr[j + 1])
            {
            	ans++;
            	swap(&arr[j], &arr[j + 1]);
			}
		}
	}   
	return ans;   
}

int main()
{
	int n;
	
	while(scanf("%d", &n))
	{
		if(n == 0)
		{
			return 0;
		}
		else
		{	
			int i, arr[n + 1];
			for(i = 0; i < n; i++)
			{
				scanf("%d", &arr[i]);
			}
			
			printf("Minimal lakukan %d pertukaran\n", solve(arr, n));
			
			for(i = 0; i < n; i++)
			{
				if(arr[i]%10 == 0)
				{
					printf("Yeay Lulus Dasprog\n");
				}
				else if(arr[i]%5 == 0)
				{
					printf("Lulus\n");
				}
				else if(arr[i]%2 == 0)
				{
					printf("Yeay\n");
				}
				else
				{
					printf("%d\n", arr[i]);
				}
			}
		}
	}
}

