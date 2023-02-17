#include <stdio.h>

int main()
{
	long long x;
	scanf("%lld", &x);
	int arr[20];
	int limit;
	
	arr[1] = x % 10;
	x = x / 10;
	arr[2] = x % 10;
	x = x / 10;
	arr[3] = x % 10;
	x = x / 10;
	arr[4] = x % 10;
	x = x / 10;
	arr[5] = x % 10;
	x = x / 10;
	arr[6] = x % 10;
	x = x / 10;
	arr[7] = x % 10;
	x = x / 10;
	arr[8] = x % 10;
	x = x / 10;
	arr[9] = x % 10;
	x = x / 10;
	arr[10] = x % 10;
	x = x / 10;
	limit = 10;
	
	if(x >= 10)
	{
		arr[11] = x % 10;
		x = x / 10;
		limit++;
	}
	else if(x > 0)
	{
		arr[11] = x;
		x = x / 10;
		limit++;
	}
	
	if(x >= 10)
	{
		arr[12] = x % 10;
		x = x / 10;
		limit++;
	}
	else if(x > 0)
	{
		arr[12] = x;
		x = x / 10;
		limit++;
	}
	
	if(x >= 10)
	{
		arr[13] = x % 10;
		x = x / 10;
		limit++;
	}
	else if(x > 0)
	{
		arr[13] = x;
		x = x / 10;
		limit++;
	}
	
	if(x >= 10)
	{
		arr[14] = x % 10;
		x = x / 10;
		limit++;
	}
	else if(x > 0)
	{
		arr[14] = x;
		x = x / 10;
		limit++;
	}
	
	if(x >= 10)
	{
		arr[15] = x % 10;
		x = x / 10;
		limit++;
	}
	else if(x > 0)
	{
		arr[15] = x;
		x = x / 10;
		limit++;
	}
	
	if(x >= 10)
	{
		arr[16] = x % 10;
		x = x / 10;
		limit++;
	}
	else if(x > 0)
	{
		arr[16] = x;
		x = x / 10;
		limit++;
	}
	
	if(x >= 10)
	{
		arr[17] = x % 10;
		x = x / 10;
		limit++;
	}
	else if(x > 0)
	{
		arr[17] = x;
		x = x / 10;
		limit++;
	}
	
	if(limit == 17)
	{
		if(arr[1] == arr[17] && arr[2] == arr[16] && arr[3] == arr[15] && arr[4] == arr[14] && arr[5] == arr[13] && arr[6] == arr[12] && arr[7] == arr[11] && arr[8] == arr[10])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	if(limit == 16)
	{
		if(arr[1] == arr[16] && arr[2] == arr[15] && arr[3] == arr[14] && arr[4] == arr[13] && arr[5] == arr[12] && arr[6] == arr[11] && arr[7] == arr[10] && arr[8] == arr[9])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	if(limit == 15)
	{
		if(arr[1] == arr[15] && arr[2] == arr[14] && arr[3] == arr[13] && arr[4] == arr[12] && arr[5] == arr[11] && arr[6] == arr[10] && arr[7] == arr[9])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	if(limit == 14)
	{
		if(arr[1] == arr[14] && arr[2] == arr[13] && arr[3] == arr[12] && arr[4] == arr[11] && arr[5] == arr[10] && arr[6] == arr[9] && arr[7] == arr[8])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	if(limit == 13)
	{
		if(arr[1] == arr[13] && arr[2] == arr[12] && arr[3] == arr[11] && arr[4] == arr[10] && arr[5] == arr[9] && arr[6] == arr[8])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	if(limit == 12)
	{
		if(arr[1] == arr[12] && arr[2] == arr[11] && arr[3] == arr[10] && arr[4] == arr[9] && arr[5] == arr[8] && arr[6] == arr[7])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	if(limit == 11)
	{
		if(arr[1] == arr[11] && arr[2] == arr[10] && arr[3] == arr[9] && arr[4] == arr[8] && arr[5] == arr[7])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	if(limit == 10)
	{
		if(arr[1] == arr[10] && arr[2] == arr[9] && arr[3] == arr[8] && arr[4] == arr[7] && arr[5] == arr[6])
		{
			printf("Aku mau satenya!");
		}
		else
		{
			printf("GMW! Aku ga suka satenya!");
		}
	}
	
	/*printf ("%d\n", limit);
	int i;
	for (i = 1; i <= limit; i++)
	{
		printf ("%d ", arr[i]);
	}*/
}
