#include<stdio.h>

int main(){
	long long int n;
	
	scanf("Jumlah Test Data : %lld", &n);
	
	n %= 5;
	
	if(n == 1){
		printf("Alpha\n");
	}
	else if(n == 2){
		printf("Beta\n");
	}
	else if(n == 3){
		printf("Gamma\n");
	}
	else if(n == 4){
		printf("Theta\n");
	}
	else{
		printf("Epsilon\n");
	}
	
	return 0;
}
