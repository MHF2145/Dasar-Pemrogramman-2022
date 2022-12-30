#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nama[101];
    int umur;
    int iq;
} anggota_sirkel;

anggota_sirkel input_data()
{
    anggota_sirkel sementara;
    scanf("%s", sementara.nama);
    scanf("%d", &sementara.umur);
    scanf("%d", &sementara.iq);
    return sementara;
}

int main()
{
    // Your code goes here
    anggota_sirkel ningen[100];
    int indekusu = 0;
    int kode_perintah;
    int flag = 1;
    while (flag != 0)
    {
        scanf("%d", &kode_perintah);
        switch (kode_perintah)
        {
        case 1:
        {
            ningen[indekusu] = input_data();
            indekusu++;
        }
        break;
        case 2:
        {
            char jeneng[101][101];
            int indedeks = 0;
            scanf("%s", jeneng[indedeks]);
            // char *ptr;
            // ptr = strtok(jeneng, " ");
            for (int i = 0; i < indekusu; i++)
            {
                if (!strcmp(jeneng[indedeks], ningen[i].nama))
                {
                    ningen[i].iq += 5;
                    indedeks++;
                    // ptr = strtok(NULL, " ");
                    // printf ("%s", jeneng);
                }
            }
        }

        break;
        case -1:
            flag = 0;
            break;
        default:
            break;
        }
    }

    int jumlah_iq = 0;
    for (int i = 0; i < indekusu; i++)
    {
        jumlah_iq += ningen[i].iq;
    }

    if (jumlah_iq >= 404)
    {
        printf("===SIRKEL SOLID===\n");
        for (int i = 0; i < indekusu; i++)
        {
            printf("%s %d %d\n", ningen[i].nama, ningen[i].umur, ningen[i].iq);
        }
    }
    else
    {
        printf("404 NOT FOUND");
    }
    return 0;
}