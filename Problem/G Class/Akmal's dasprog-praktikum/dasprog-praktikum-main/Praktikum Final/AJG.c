#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main()
{
	bool prime[100001];
    memset(prime, true, sizeof(prime));
 	int p, q, i;;
 		
    for(p = 2; p * p <= 100001; p++) 
	{
        if(prime[p] == true) 
		{
            for (i = p * p; i <= 100001; i += p)
            {
            	prime[i] = false;
			}	
        }
    }
    prime[1] = false;
    
	
	
	scanf("%d", &q);
	
	while(q--)
	{
		int n;
		
		scanf("%d", &n);
		
		
		
		int i, arr[n + 1];
		for(i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		bool ada;
		
		for(i = 0; i < n; i++)
		{
			if(prime[arr[i]])
			{
				printf("%d ", arr[i]);
				ada = true;
			} 
			
		}
		
		if(ada == false)
		{
			printf("Unable to send Fever Slot Buckle.");
		}
		
		printf("\n");
		
		ada = false;
	}
}

