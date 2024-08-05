#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check[69][69];
int search(int cari);


typedef struct
{
    char asma[69];
    char hp[31];
    char jeneng[69];    
    int yuswa;
    int kanca;
    int kanca_d;
} dhata;


typedef struct
{
    dhata wong[11];
    int akehwong;
} akehe;


typedef struct
{
    akehe saka[11];
    char asma[69];
} kutha;


int a, j, k, l, m, y = 1, z, cari;
kutha ktp;


int main()
{
    memset(check, false, sizeof(check));
    char asma[69][69];

    scanf("%d", &z);
    for (a = 0; a < z; a++)
    {
        scanf("%s", asma[a]);
        int n;
        scanf("%d", &n);
        ktp.saka[a].akehwong = n;
        for (j = 0; j < n; j++)
        {
            strcpy(ktp.saka[a].wong[j].asma, asma[a]);
            scanf("%s %d %s", ktp.saka[a].wong[j].jeneng, &ktp.saka[a].wong[j].yuswa, ktp.saka[a].wong[j].hp);
        }
    }

    scanf("%d", &cari);
    search(cari);

    for (a = 0; a < z; a++)
    {
        printf("%s\n", asma[a]);
        for (j = 0; j < ktp.saka[a].akehwong; j++)
        {
            printf("Name: %s\nAge: %d\nPhone Number:%s\n", ktp.saka[a].wong[j].jeneng, ktp.saka[a].wong[j].yuswa, ktp.saka[a].wong[j].hp);
            check[a][j] ? printf("His/Her bestie is: %s\nHis/Her contact info is as follows\nName: %s\nAge: %d\nPhone Number:%s\n", ktp.saka[ktp.saka[a].wong[j].kanca].wong[ktp.saka[a].wong[j].kanca_d].jeneng, ktp.saka[ktp.saka[a].wong[j].kanca].wong[ktp.saka[a].wong[j].kanca_d].jeneng, ktp.saka[ktp.saka[a].wong[j].kanca].wong[ktp.saka[a].wong[j].kanca_d].yuswa, ktp.saka[ktp.saka[a].wong[j].kanca].wong[ktp.saka[a].wong[j].kanca_d].hp) : printf("His/Her bestie is: No one\n");
            printf("\n");
        }
    }
}


int search(int cari)
{
    for (a = 0; a < cari; a++)
    {
        char a[69], b[69];
        scanf("%s %s", a, b);
        for (j = 0; j < z; j++)
        {
            for (k = 0; k < ktp.saka[j].akehwong; k++)
            {
                if (strcmp(a, ktp.saka[j].wong[k].jeneng) == 0)
                {
                    for (l = 0; l < z && y == 1; l++)
                    {
                        for (m = 0; m < ktp.saka[l].akehwong && y == 1; m++)
                        {
                            if (strcmp(b, ktp.saka[l].wong[m].jeneng) == 0)
                            {
                                ktp.saka[j].wong[k].kanca = l;
                                ktp.saka[j].wong[k].kanca_d = m;
                                check[j][k] = true;
                                break;
                                y = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}