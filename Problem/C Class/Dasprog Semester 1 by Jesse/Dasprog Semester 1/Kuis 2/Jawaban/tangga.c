#include <stdio.h>

int main(){

	int i, j, k, n;
    char a;
	scanf("%d", &n); //input limit
    scanf(" %c", &a);

    //untuk scan alphabet "A" di kata "Aku"
    if (a == 'A') //Jika menghasilkan kata depannya A
    {
        //loop untuk pola setengah segitiga (dari kiri ke kanan)
        for (i = 1; i <= n; i++) {
        for (j = 1, k = i; j <= i; j++, k++) {
            if (k % 2 == 0) {
                printf("U ");
            }
            else {
                printf("I ");
            }
        }
        printf("\n");
    }
    }
    //untuk scan alphabet "K" di kata "Kamu"
    else if (a == 'K') //Jika menghasilkan kata depannya K
    {
        //loop untuk pola setengah segitiga (dari kanan ke kiri)
        for (i=1; i<=n; i++) {
        for (j=n; j>=i; j--) {
            printf(" ");
        }

        for (k=1; k<=i; k++) {
            if (k % 2 == 0) {
                printf("U ");
            } else {
                printf("I ");
            }
        }
           printf("\n");
        }
    }
}
