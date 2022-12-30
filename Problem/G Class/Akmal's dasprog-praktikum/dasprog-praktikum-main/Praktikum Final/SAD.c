#include<stdio.h>
#include<stdbool.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;

int main()
{
	int n;
	
	scanf("%d", &n);
	
	while(n--)
	{
		int a;
		bool flag = false;
		
		scanf("%d", &a);
		
		if(a >= 140) printf("YES\n");
		else if(a%11 == 0 || a%15 == 0) printf("YES\n");
		else
		{
			while(a > 0)
			{
				a -= 11;
				if(a%15 == 0)
				{
					printf("YES\n");
					flag = true;
					break;
				}
				
			}
			
			if(!flag) printf("NO\n");
		}
	}
}

