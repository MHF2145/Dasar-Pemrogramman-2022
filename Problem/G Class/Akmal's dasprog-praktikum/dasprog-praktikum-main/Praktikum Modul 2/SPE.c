#include <stdio.h>
#include<string.h>

int main(){
	char s[1000001];
	
	scanf("%s", s);
	
	int i, j, arr[10];
	
	for(i = 0; i < strlen(s); i++){
		if(s[i] == 'w'){
			arr[2]++;
		}
		if(s[i] == 'g'){
			arr[8]++;
		}
		if(s[i] == 'x'){
			arr[6]++;
		}
		if(s[i] == 'v'){
			arr[5]++;
		}
		if(s[i] == 'o'){
			arr[1]++;
		}
		if(s[i] == 's'){
			arr[7]++;
		}
		if(s[i] == 'f'){
			arr[4]++;
		}
		if(s[i] == 'h'){
			arr[3]++;
		}
		if(s[i] == 'i'){
			arr[9]++;
		}
	}
	arr[7] -= arr[6];
	arr[5] -= arr[7];
	arr[4] -= arr[5];
	arr[1] -= (arr[2] + arr[4]);
	arr[3] -= arr[8];
	arr[9] -= (arr[5] + arr[6] + arr[8]);
	
	for(i = 10; i > 0; i--){
		for(j = 0; j < arr[i]; j++){
			printf("%d", i);
		}
	}
	
	return 0;
}

