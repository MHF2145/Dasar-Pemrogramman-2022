#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // Your code goes here
    char kata [1000007];
    char kata_kurang [1000007]; //sesuai constraint tapi dilebihkan dikit
    scanf ("%s", kata);
    kata_kurang [0] = kata[0]; //daripada hurufnya dihilangkan, why not huruf yang gak sama ditaruh di sini

    int index = 0;
    long long int kerugian = 0; // ya karena 100000*122*2000 > 2 milyaran (max int)
    
    int panjang = strlen(kata);
    int i;

    for (i = 1; i < panjang; i++)
    {
        if (kata [index] == kata [i])
        {
            kerugian += kata [index] * 2000; //dikalikan 2000 karena 2 batu yang hilang
            index--; //buat ngecek case seperti "yxxy"
        }
        else
        {
            index++; // buat array di bawah
            kata_kurang [index] = kata [i]; // mencatat huruf yang (awalnya) gak sama
        }
    }
 
    printf ("Di gudang tersisa %d batu\n", (index+1));
    if (index + 1 == i)
    {
        printf ("Wah, Jotaro Joemama tidak jadi dipecat");
    }
    else
    {
        printf ("Total Kerugian: %lld Dolar Imbu", kerugian);
    }
    
    return 0;
}