#include <stdio.h>
#include <string.h>

int main()
{
	char num[25];
	scanf("%s", &num);
	int digit;
	scanf("%d", &digit);
	int counter = strlen(num);
	
	int max_arr[25];
	unsigned long long max = 0;
	int i;
	for(i = 0; i <= counter - digit; i++)
	{
		int arr[25];
		int j;
		for(j = 0; j <= digit - 1; j++)
		{
			arr[j + 1] = num[i + j] - '0';
		}
		
		int check = 0;
		int counter2 = 1;
		unsigned long long max_temp = 0;
		while(1)
		{
			if(counter2 >= digit)
			{
				if(check == 0)
				{
					int k;
					for(k = 1; k <= digit; k++)
					{
						max_temp = max_temp * 10 + arr[k];
					}
					break;
				}
				counter2 = 1;
				check = 0;
			}
			if(arr[counter2 + 1] > arr[counter2])
			{
				int temp = arr[counter2];
				arr[counter2] = arr[counter2 + 1];
				arr[counter2 + 1] = temp;
				check = 1;
			}
			counter2++;
		}
		
		if(max_temp > max)
		{
			int k;
			for(k = 1; k <= digit; k++)
			{
				max_arr[k] = arr[k];
			}	
			max = max_temp;
		}
	}
	
	int j;
	for(j = 1; j <= digit; j++)
	{
		printf("%d", max_arr[j]);
	}
	printf("\n");
}
