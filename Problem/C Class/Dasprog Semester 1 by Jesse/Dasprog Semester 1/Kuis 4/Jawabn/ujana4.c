#include <stdio.h>
#include <string.h>

struct rekening
{
    char id[1000];
    char nama[10];
    int saldo;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct rekening rek[n];
    int i;

    for (i = 0; i < n; i++)
    {
        scanf("%s %s %d", rek[i].id, rek[i].nama, &rek[i].saldo);
    }

    int m, j; 
    
    scanf("%d", &m);
    
    int token[m], rubah[m];
    char ceknama[m][10];
    
    for (i = 0; i < m; i++)
    {
        scanf("%s %d", ceknama[i], &token[i]);

        if (token[i] == 2)
        {
            scanf("%d", &rubah[i]);
        }
    }
    
    for (i = 0; i < m; i++)
    {
        int k = 0;
        for (j = 0; j < n; j++){
            if ((strcmp(ceknama[i], rek[j].nama) == 0))
            {
                if (token[i] == 1)
                {
                    printf("Saldo %s dengan id %s adalah $%d\n", rek[j].nama, rek[j].id, rek[j].saldo);
                }
                else if (token[i] == 2)
                {
                    rek[j].saldo = rubah[i];
                    printf("Saldo %s dengan id %s diubah menjadi $%d\n", rek[j].nama, rek[j].id, rek[j].saldo);
                }
                k++;
                break;
            }
        }
        if (k == 0)
        {
        printf("Rekening %s tidak ditemukan!\n", ceknama[i]);
        }
    }
}