#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct
{
	char name[101];
	int la, lo;
}list;

bool cek(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
 	int p;
    for (p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
        	int i;
            for (i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    if(prime[n])
	{
		return true;
	} 
	else
	{
		return false;
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	list arr[n + 1];
	
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s %dN %dE", arr[i].name, &arr[i].la, &arr[i].lo);
	}
	
	while(m--)
	{
		char str[101];
		scanf("%s", str);
		
		bool ketemu = false;
		
		for(i = 0; i < n; i++)
		{	
			if(strcmp(str, arr[i].name) == 0)
			{
				if(cek(arr[i].la) && cek(arr[i].lo))
				{
					printf("%s aman! Bangunlah Kesatria!\n", arr[i].name);
					ketemu = true;
				}
				else
				{
					printf("%s tidak aman! Ini pasti ulah Gorgom!\n", arr[i].name);
					ketemu = true;
				}
			}
		}
		if(ketemu == false)
		{
			printf("Tempat apa itu? Kotaro tidak tahu!\n", str);	
		}
	}
}

