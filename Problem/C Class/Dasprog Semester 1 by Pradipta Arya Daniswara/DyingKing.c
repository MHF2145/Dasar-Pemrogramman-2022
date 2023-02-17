#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct kota {
    char tempat[100];
    int latitude;
    int longitude;
};

bool isPrime(int z)
{
	if(z == 1)
	{
		return false;
	}
	
	if(z % 2 == 0 && z != 2)
	{
		return false;
	}
	
	int a;
	for(a = 3; a <= sqrt(z); a = a + 2)
	{
		if (z % a == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int a;
	scanf("%d", &a);
	int b;
	scanf("%d", &b);
	struct kota arr[a + 1];
	
	int i;
	for(i = 1; i <= a; i++)
	{
		char tempat[100];
		scanf("%s", &tempat);
		int latitude;
		scanf("%dN", &latitude);
		int longitude;
		scanf("%dE", &longitude);
		
		strcpy(arr[i].tempat, tempat);
		arr[i].latitude = latitude;
		arr[i].longitude = longitude;
	}
	
	int j;
	for(j = 1; j <= b; j++)
	{
		char tempat[100];
		scanf("%s", &tempat);
		int check = 0;
		
		int k;
		for(k = 1; k <= a; k++)
		{
			if(strcmp(arr[k].tempat, tempat) == 0)
			{
				check = k;
				break;
			}
		}
		
		if(check != 0)
		{
			if(isPrime(arr[check].latitude) == true && isPrime(arr[check].longitude) == true)
			{
				printf("%s aman! Bangunlah Kesatria!\n", arr[check].tempat);
			}
			else
			{
				printf("%s tidak aman! Ini pasti ulah Gorgom!\n", arr[check].tempat);
			}
		}
		else
		{
			printf("Tempat apa itu? Kotaro tidak tahu!\n");
		}
	}
}
