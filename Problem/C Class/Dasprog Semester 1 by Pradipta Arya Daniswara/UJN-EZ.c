#include <stdio.h>
#include <string.h>

int main()
{
	char arr[100];
	gets(arr);
	int n;
	scanf("%d", &n);
	int arr2[55];
	
	int i;
	for (i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		arr2[i] = x;
	}
	
	int j;
	for (j = 1; j <= n; j++)
	{
		printf("%c", arr[arr2[j]]);
	}
}
