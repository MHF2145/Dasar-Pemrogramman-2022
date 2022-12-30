#include<stdio.h>

int main(){
	long long int x1, x2, x3, y1, y2, y3;
	
	scanf("[%lld,%lld] | [%lld,%lld] | [%lld,%lld]", &x1, &y1, &x2, &y2, &x3, &y3);
	
	long long int x = (x1 + x2 + x3) / 3;
	long long int y = (y1 + y2 + y3) / 3;
	
	if((x1 == x2 && x1 == x3) && (y1 == y2 && y1 == y3)){
		printf("Henshin! Entry.\n");
	}
	else if((y3 - y2)*(x2 - x1) == (x3 - x2)*(y2 - y1)){
		if((x%2 == 1) && (y%2 == 1)){
			printf("Boost Raise Buckle Acquired at Coordinate [%lld,%lld]\nHenshin! Boost, Ready, Fight!\n", x, y);
		}
		else{
			printf("Henshin! Entry.\n");
		}
	}
	else{
		if((x%2 == 0) && (y%2 == 0)){
			printf("Magnum Raise Buckle Acquired at Coordinate [%lld,%lld]\nHenshin! Magnum, Ready, Fight!\n", x, y);
		}
		else{
			printf("Henshin! Entry.\n");
		}
	}
	
	return 0;
}
