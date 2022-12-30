#include <stdio.h>
#include<string.h>

int main(){
	char s[100001];
	long long n, sum = 0;
	
	scanf("%lld", &n);
	
	while(n--){
		scanf("%s", s);
	
		char *tok = strtok(s, ".");
		char *name = strtok(NULL, ".");
		char *tok1 = strtok(NULL, ".");
    	char *tok2 = strtok(NULL, "\n");
    
    	int stat = atoi(tok1);
    	int hp = atoi(tok2);
    	
    	if(stat%5 == 0){
    		printf("%s %lld\n", name, hp);
    		sum += hp;
		}
	}

    printf("TOTAL SCORE: %lld", sum);
	    
    return 0;
}
