#include <stdio.h>
#include <string.h>

int main()
{
	char arr[100000];
	gets(arr);
	int arr2[128];
	
	int i;
	for (i = 0; i <= 127; i++)
	{
		arr2[i] = 0;
	}
	arr2[32] = 1;
	
	int j;
	for (j = 1; j <= strlen(arr); j++)
	{
		if(arr2[arr[j-1]] == 0)
		{
			arr2[arr[j-1]] = 1;
			printf("%c", arr[j-1]);
		}
	}
}
