#include <stdio.h>
#include <string.h>

int main()
{
    char x[100000];
    int i, j, k;

    gets(x);

    //ngukur string, kalau misal i lebih kecil daripada string yang dimasukin, dia pindah ke for bawahnya
    for (i = 0; i < strlen(x); i++) // i sengaja 0 karena kalau ga dimasukin string apa2 dia ga hasilin output apapun
    {
        //masuk ke if dibawah karena j = 0, pasti dia tidak samap dengan i (sama sama 0)
        for (j = 0; j < i; j++) //dibuat gini biar bisa looping untuk cek spasi
        {
            if ((x[i] == x[j]) || (x[i] == ' ')) //jika ada spasi atau karakter yang sama
            {
                break; //maka dia akan dihapus
            }
        }
        if (j == i) //kalau misalnya inputan string jumlahnya sama dengan i, maka
        {
            printf("%c", x[i]);
        }
    }
    return 0;
}