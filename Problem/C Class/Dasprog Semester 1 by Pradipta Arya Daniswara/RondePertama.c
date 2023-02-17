#include <stdio.h>
#include <string.h>

int max_sum(int arr[], int size)
{
    int max = -2147483647;
	int counter = 0;

	int i;
    for(i = 1; i <= size; i++) 
	{
        counter = counter + arr[i];
        if (max < counter)
        {
        	max = counter;
		}
        if (counter < 0)
        {
        	counter = 0;
		}
    }
    return max;
}

int main()
{
	int N;
	scanf("%d", &N);
	int arr[100000005];
	char nama_max[55];
	int max = 0;
	
	int i;
	for(i = 1; i <= N; i++)
	{
		char nama[55];
		scanf("%s", &nama);
		if(i == 1)
		{
			strcpy(nama_max, nama);
		}
		
		int M;
		scanf("%d", &M);
		int j;
		for(j = 1; j <= M; j++)
		{
			int input;
			scanf("%d", &input);
			arr[j] = input;
		}
		
		int hasil = max_sum(arr, M);
		if(hasil >= max)
		{
			max = hasil;
			strcpy(nama_max, nama);
		}
	}
	printf("%s\n", nama_max);
}
