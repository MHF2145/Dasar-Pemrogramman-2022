#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	bool prime[100001];
    memset(prime, true, sizeof(prime));
 	
	prime[0] = false;
 	prime[1] = false;
	int p;
    for (p = 2; p * p <= 100000; p++) 
	{
        if (prime[p] == true) 
		{
			int i;
            for (i = p * p; i <= 100000; i += p)
            {
            	prime[i] = false;
			}
        }
    }
	
	int Q;
	scanf("%d", &Q);
	
	int i;
	for(i = 1; i <= Q; i++)
	{
		int N;
		scanf("%d", &N);
		int arr[N + 1];
		
		int j;
		for(j = 1; j <= N; j++)
		{
			int kode;
			scanf("%d", &kode);
			arr[j] = kode;
		}
		
		int check = 0;
		int k;
		for(k = 1; k <= N; k++)
		{
			if(prime[arr[k]] == true)
			{
				printf("%d ", arr[k]);
				check = 1;
			}
			
			if(k == N && check == 0)
			{
				printf("Unable to send Fever Slot Buckle.");
			}
		}
		printf("\n");
	}
}
