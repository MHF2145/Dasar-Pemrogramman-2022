#include <stdio.h>

int main()
{
	int testcase;
	scanf("%d", &testcase);
	
	int i;
	for(i = 1; i <= testcase; i++)
	{
		int input;
		scanf("%d", &input);
		
		if(input % 2 == 0)
		{
			printf("%d\n", input * 2 - 1);
		}
		else
		{
			printf("%d\n", input * 2 + 1);
		}
	}
}
