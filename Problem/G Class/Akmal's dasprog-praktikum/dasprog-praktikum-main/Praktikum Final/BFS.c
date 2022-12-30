#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main()
{
	
	int n, base;
	
	scanf("%d %d", &n, &base);
	
	while(n--)
	{
        int idx, t, ans = 0;
        bool flag = false;
        
        scanf("%d %d", &idx, &t);
        
        if(idx != 0)
        {
            base ^= (1 << idx - 1);
        }
         
    	int a, b, i;
    	for(i = sizeof(int) * 8 - 1; i >= 0; i--)
    	{
        	a = (base >> i) & 1;
        	b = (t >> i) & 1;

        	if (a != b && i != 0)
        	{
           		flag = true;
        	}
        	else if (a != b && i == 0)
        	{
            	ans++;
				flag = true;
        	}
        	if (a == b && flag)
        	{	
				ans++;
            	flag = false;
            	
        	}
    	}
    	
		base = t;
		
        printf("%d\n", ans);
	}
	
	return 0;
}

