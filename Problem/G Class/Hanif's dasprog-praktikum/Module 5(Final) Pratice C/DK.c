#include <stdio.h>
#include <string.h>
#include <math.h>

struct data
{
    char tempat[101];
    int n, o;
} data;
typedef struct data kdn;

int prima(int z)
{
    for (int i = 2; i <= sqrt(z); i++)
    {
        if (z % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int sampai = 0;

int search(char sercing[], struct data kdn[])
{
    int liat = -1;
    for (int i = 0; i < sampai; i++)
    {
        if (strcmp(kdn[i].tempat, sercing) == 0)
        {
            
            liat = 0;
            liat += prima(kdn[i].n);
            liat += prima(kdn[i].o);
        }
    }
    return liat;
}

int main()
{
    struct data kdn[101];
    int z, b;
    int i;
    
    scanf("%d %d", &z, &b);
    
    while (z--)
    {
        scanf("%s %dN %dE", kdn[sampai].tempat, &kdn[sampai].n, &kdn[sampai].o);
        sampai++;
    }

    while (b--)
    {
        char sercing[101];
        scanf("%s", sercing);
        if (search(sercing, kdn) == 2)
        {
            printf("%s aman! Bangunlah Kesatria!\n", sercing);
        }

        else if (search(sercing, kdn) >= 0)
        {
            printf("%s tidak aman! Ini pasti ulah Gorgom!\n", sercing);
        }

        else
        {
            printf("Tempat apa itu? Kotaro tidak tahu!\n");
        }

    }
}
