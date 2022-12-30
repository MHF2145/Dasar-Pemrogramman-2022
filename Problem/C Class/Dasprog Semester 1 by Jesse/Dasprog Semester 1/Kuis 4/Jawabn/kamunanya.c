#include <stdio.h>
#include <string.h>

struct oleholeh
{
    char x[20];
    char y[10];
    int z;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct oleholeh aha[n];
    int i;
    
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %d", aha[i].x, aha[i].y, &aha[i].z);
    }
    
    char cekx[20], ceky[10];
    int cekz;

    scanf("%s %s %d", cekx, ceky, &cekz);
    

    for (i = 0; i < n; i++)
    {
        if (((strcmp(cekx, aha[i].x) == 0) && (strcmp(ceky, aha[i].y) == 0)) && aha[i].z >= cekz)
        {
            printf("Oleh-olehnya ada yaa");
            break;
        } else if (i == (n-1))
        {
            printf("Hah? Kamu nanya???");
        }
    }
}
