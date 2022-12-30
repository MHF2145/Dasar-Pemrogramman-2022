#include <stdio.h>
#include <string.h>

struct king
{
    char NamaTempat[100];
    int Latitude;
    int Longitude;
};

int temp1 = 0, temp2 = 0;

int primatidak(int c, int d){
    int i;
    for (i = 2; i <= c; i++)
    {
        if (c % i == 0)
        {
            temp1++;
        }
    }

    for (i = 2; i <= d; i++)
    {
        if (d % i == 0)
        {
            temp2++;
        }
    }

    if (temp1 == 1 && temp2 == 1)
    {
        temp1 = 0;
        temp2 = 0;
        return 1;
    } else
    {
        temp2 = 0;
        temp1 = 0;
        return 0;
    }
}

int main(){
    int a, b, i;

    scanf("%d %d", &a, &b);

    struct king lol[a];
    
    for (i = 0; i < a; i++)
    {
        scanf("%s %dN %dE", lol[i].NamaTempat, &lol[i].Latitude, &lol[i].Longitude);
    }

    char ceknama[b][100];
    
    for (i = 0; i < b; i++)
    {
        scanf("%s", ceknama[i]);
    }

    int j;

    for (i = 0; i < b; i++)
    {
        int h = 0;
        for (j = 0; j < a; j++)
        {
            if (strcmp(lol[j].NamaTempat, ceknama[i]) == 0)
            {
                if (primatidak(lol[j].Latitude, lol[j].Longitude) == 1)
                {   
                    printf("%s aman! Bangunlah Kesatria!\n", lol[j].NamaTempat);
                    break;
                } else
                {
                    printf("%s tidak aman! Ini pasti ulah Gorgom!\n", lol[j].NamaTempat);
                    break;
                }
            h++;
            }
        }
        if (j == a)
        {
            printf("Tempat apa itu? Kotaro tidak tahu!\n");
        }
    }
    return 0;
} 