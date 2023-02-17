#include <stdio.h>

void rekursi(int arr[], int counter, int n, int check)
{
	if(counter >= n)
	{
		if(check == 0)
		{
			int i;
			for(i = 1; i <= n; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
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
		check = 1;
	}
	rekursi(arr, counter + 1, n, check);
}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[n + 1];
	int i;
	for(i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		arr[i] = x;
	}
	rekursi(arr, 1, n, 0);
}
