#include <stdio.h>
#include <string.h>

int main()
{
    char x[100000];
    int i, j, k;

    scanf("%[^\n]", x);

    //ngukur string, kalau misal i lebih kecil daripada string yang dimasukin, dia pindah ke for bawahnya --> strlen buat ngitung panjang string
    for (i = 0; i < strlen(x); i++) // i sengaja 0 karena kalau ga dimasukin string apa2 dia ga hasilin output apapun
    {
        //masuk ke if dibawah karena j = 0, pasti dia tidak sama dengan i (sama sama 0)
        for (j = 0; j < i; j++) //string di array i dipindah ke array j
        {
            if ((x[i] == x[j]) || (x[i] == ' ')) //jika ada spasi atau karakter yang sama
            {
                break; //maka dia akan dihapus
            }
        }
        if (j == i) //kalau misalnya inputan string jumlahnya sama dengan i,
        {
            printf("%c", x[i]); //maka dia akan ngeprint semua data yang telah diubah ubah :DD
        }
    }
    return 0;
}