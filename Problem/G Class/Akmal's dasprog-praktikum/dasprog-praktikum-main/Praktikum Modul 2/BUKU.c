#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	long long n, t, i;
	
	scanf("%lld", &n);
	
	while(n--){
		scanf("%lld", &t);
		
		for(i = 0; i < 10; i++){
			long long x = pow(26,i);
			
			printf("%c", 65 + ((t / x) % 26));
		}
		printf("\n");	
	}
 	
	return 0;
}
