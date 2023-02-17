#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int i;
	for(i = 1; i <= N; i++)
	{
		int input;
		scanf("%d", &input);
		
		int counter_11 = input / 11;
		int sisa = input % 11;
		
		while(1)
		{
			if(counter_11 == 0)
			{
				printf("NO\n");
				break;
			}
			
			int counter_4 = sisa / 4;
			if(sisa % 4 == 0 && counter_4 <= counter_11)
			{
				printf("YES\n");
				break;
			}
			else
			{
				counter_11--;
				sisa = sisa + 11;
			}
		}
	}
}
