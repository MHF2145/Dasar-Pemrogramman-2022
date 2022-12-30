#include <stdio.h>

int hitung(int a, int tumpuk);

int main() 
{
    int a, tumpuk, b = -1000000;

    while (1) 
    {
        scanf("%d", &a);
        if (a < b) 
        {
            break;
        }

        tumpuk = 1;
        int i = 0;

        hitung(a, tumpuk);

        printf("\n");
        b = a;
    }
    return 0;
}

int hitung(int a, int tumpuk)
{
    int i = 0;
    while (1) 
    {
        tumpuk += i;
        if (tumpuk > a) 
        {
            break;
        }
        else 
        {
            printf("%d ", tumpuk);
            i++;
        }
    }


}