#include<stdio.h>

int spi(int n, int idx){
  if(n==1) return 1;
  else {
  	return (spi(n - 1, idx + 1) + idx) % n + 1;
  }
}

int main(){
	int n;
	
	scanf("%d", &n);
	
	while(n--){
		int a;
		scanf("%d", &a);
		printf("%d\n", spi(a, 0));
	}
	
	return 0;
}

