#include <stdio.h>
#include <stdbool.h>

void rekursi(int arr[], int counter, int n, int check, int tukar)
{
	if(counter >= n)
	{
		if(check == 0)
		{
			printf("Minimal lakukan %d pertukaran\n", tukar);
			
			int i;
			for(i = 1; i <= n; i++)
			{
				if(arr[i] % 2 == 0 || arr[i] % 5 == 0 || arr[i] % 10 == 0)
				{
					if(arr[i] % 2 == 0)
					{
						printf("Yeay ");
					}
					if(arr[i] % 5 == 0)
					{
						printf("Lulus ");
					}
					if(arr[i] % 10 == 0)
					{
						printf("Dasprog ");
					}
				}
				else
				{
					printf("%d ", arr[i]);
				}
				printf("\n");
			}
			return;
		}
		counter = 1;
		check = 0;
	}
	if(arr[counter] > arr[counter + 1])
	{
		int temp = arr[counter];
		arr[counter] = arr[counter + 1];
		arr[counter + 1] = temp;
		tukar++;
		check = 1;
	}
	rekursi(arr, counter + 1, n, check, tukar);
}

int main()
{
	while(1)
	{
		int N;
		scanf("%d", &N);
		if(N == 0)
		{
			break;
		}
		int arr[N];
		
		int i;
		for(i = 1; i <= N; i++)
		{
			int input;
			scanf("%d", &input);
			arr[i] = input;
		}
		
		rekursi(arr, 1, N, 0, 0);
	}
}
