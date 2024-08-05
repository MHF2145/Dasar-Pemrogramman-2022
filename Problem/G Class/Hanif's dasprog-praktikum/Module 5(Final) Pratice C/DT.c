#include <stdio.h>


void urutkan(int isi[], int n)
{
    int jml = 0;
    for (int i = 1; i < n; i++)
    {
        int j, angka;
        angka = isi[i];
        j = i - 1;
            
        while (j >= 0 && isi[j] > angka)
        {
            isi[j + 1] = isi[j];
            jml ++;
            j = j - 1;
        }
        isi[j + 1] = angka;
    }
    printf("minimal lakukan %d pertukaran\n",jml);
}

int main()
{
    
    while(1)
    {
        int a, i;

        scanf("%d", &a);
        if(a == 0)
        {
            break;
        }

        int isi[a];

        for(i = 0; i < a; i++)
        {
            scanf("%d",&isi[i]);
        }

        urutkan(isi, a);

        for(i = 0; i < a; i++)
        {
            if(isi[i] % 2 == 0)
            {
                printf("Yeay ");
            }
            if(isi[i] % 5 == 0)
            {
                printf("Lulus ");
            }
            if(isi[i] % 10 == 0)
            {
                printf("Dasprog ");
            }
            if(isi[i] % 10 != 0 && isi[i] % 2 != 0 && isi[i] % 5 != 0)
            {
                printf("%d ", isi[i]);
            }
            printf("\n");
        }
    }
    return 0;
}