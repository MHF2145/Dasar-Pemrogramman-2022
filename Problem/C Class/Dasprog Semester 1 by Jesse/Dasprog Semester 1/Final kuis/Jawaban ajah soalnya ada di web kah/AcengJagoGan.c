#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int primaaa[100000];

void aceng(int n){
    memset(primaaa, false, sizeof(primaaa));

    primaaa[1] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (primaaa[i] == false)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                primaaa[j] = true;
            }
        }
    }
}

int main(){
    int q, kode[100000];
    aceng(100000);

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        int n;

        scanf("%d", &n);

        int tes = 0;

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &kode[j]);

            if (primaaa[kode[j]] == false)
            {
                printf("%d ", kode[j]);
                tes++;
            }
        }
        
        if (tes != 0)
        {
            printf("\n");
        } else {
        printf("Unable to send Fever Slot Buckle.\n");
        }
    }
}