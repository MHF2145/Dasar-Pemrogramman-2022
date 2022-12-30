#include<stdio.h>
#include<string.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main()
{
	int sum = 0;
	char s[100001];
	
	scanf("%s", s);
	
	int i, j, k, len = strlen(s);
	for(i = 0; i < len; i++)
	{
		int j = i - 1, k = i;
		
		while(k < len - 1 && s[k] == s[k + 1])
		{
			k++;
		} 
		
		sum += (k - j) * (k - j + 1) / 2;
		
		i = k++;
		
		while(j >= 0 && k < len && s[k++] == s[j--])
		{
			sum++;
		}
	}
	
	printf("%d\n", sum);
}

