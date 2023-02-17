#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	int i;
	for (i = 1; i <= t; i++)
	{
		int c;
		scanf("%d", &c);
		int k;
		scanf("%d\n", &k);
		char arr[100];
		scanf("%[^\n]s", arr);
		
		int j;
		for (j = 0; j <= strlen(arr) - 1; j++)
		{
			if(arr[j] >= 97 && arr[j] <= 122)
			{
				if(c == 1)
				{
					if(arr[j] + k > 122)
					{
						arr[j] = arr[j] + k - 26;
					}
					else
					{
						arr[j] = arr[j] + k;
					}
				}
				else if(c == 2)
				{
					if(arr[j] - k < 97)
					{
						arr[j] = arr[j] - k + 26;
					}
					else
					{
						arr[j] = arr[j] - k;
					}
				}
			}
		}
		printf("%s\n", arr);
	}
}
