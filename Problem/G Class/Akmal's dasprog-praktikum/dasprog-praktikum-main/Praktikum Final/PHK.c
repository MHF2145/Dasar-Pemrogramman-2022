#include <stdio.h>
#include <stdbool.h>
#define ll long long

int main(){
    ll n;
    
    scanf("%lld", &n);
    
    ll x1 = 1, y1 = 1, x2 = n, y2 = n;

	while(true)
	{
		if(x1 < x2 && y1 < y2)
		{
        	ll xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
        	
        	printf("LIHAT %d %d\n", xm, ym);
			fflush(stdout);
			
        	ll look;
        	
        	scanf("%lld", &look);
        	
        	if(look == 1)
			{
        		y1 = ym;
        		x2 = xm;
			}
			if(look == 2)
			{
				y1 = ym;
			}
			if(look == 3)
			{
				x1 = xm;
				y1 = ym;
			}
			if(look == 4)
			{
				x2 = xm;
			}
			if(look == 5)
			{
        		printf("KOORDINAT %d %d", xm, ym);
            	fflush(stdout);
            	return 0;
			}
			if(look == 6)
			{
				x1 = xm;
			}
			if(look == 7)
			{
				x2 = xm;
				y2 = ym;
			}
			if(look == 8)
			{
				y2 = ym;
			}
			if(look == 9)
			{
				x1 = xm;
				y2 = ym;
			}
		}
	}
	
	return 0;
}

