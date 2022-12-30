#include <stdio.h>

int n = 1, i, j, swapped, temp;

void Sortgelembung(int *a, int *b){
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    while (n != 0)
    {
        scanf("%d", &n);

        int gelas[n];

        if (n == 0)
        {
            break;
        }
        
        for (i = 0; i < n; i++)
        {
            scanf("%d", &gelas[i]);
        }
        
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (gelas[j] > gelas[j+1]) {
                    Sortgelembung(&gelas[j], &gelas[j + 1]);
                    swapped++;
                }
            }
        }
        
        printf("Minimal lakukan %d pertukaran\n", swapped);

        for (i = 0; i < n; i++)
        {
            if (gelas[i] % 2 == 0 && gelas[i] % 5 == 0 && gelas[i] % 10 == 0)
            {
                printf("Yeay Lulus Dasprog\n");
            } else if (gelas[i] % 5 == 0 && gelas[i] % 10 == 0)
            {
                printf("Lulus Dasprog\n");
            } else if (gelas[i] % 5 == 0)
            {
                printf("Lulus\n");
            } else if (gelas[i] % 2 == 0 && gelas[i] % 5 == 0)
            {
                printf("Yeay Lulus\n");
            } else if (gelas[i] % 2 == 0)
            {
                printf("Yeay\n");
            } else
            {
                printf("%d\n", gelas[i]);
            }
        }
    swapped = 0;
    }
    return 0;
}
