#include <stdio.h>

int main(){
    int m, n;
    
    scanf("%d %d", &m, &n);

	if(m%(n+1) == 0){
		printf("abeng\n");
	}
	else{
		printf("bahresi\n");
	}

    return 0;
}
