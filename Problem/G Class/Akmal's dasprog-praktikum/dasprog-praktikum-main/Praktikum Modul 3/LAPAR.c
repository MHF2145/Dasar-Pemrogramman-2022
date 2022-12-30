#include <stdio.h>

int n, k;
int arr[15];
int ada;

void permut(int idx) {
    if (idx > n) {
        int flag = 1;
        if (n > 2 && arr[1] == arr[n]) {
            flag = 0;
        }
        int i;
        for ( i = 0; i < n; i++) {
            if (arr[i] == arr[i+1]) {
                flag = 0;
                break;
            }
        }
 
        if(flag){
        	int i;
            for (i = 1; i <= n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            ada = 1;
        }
    }
    else{
    	int i;
        for (i = 1; i <= k; i++) {
            arr[idx] = i;
            permut(idx + 1);
        }
    }
} 
 
int main(){
	
    scanf("%d %d", &n, &k);
    
	permut(1);
    
	if (!ada){
    	printf("-1\n");
	} 
    
	return 0;
}
