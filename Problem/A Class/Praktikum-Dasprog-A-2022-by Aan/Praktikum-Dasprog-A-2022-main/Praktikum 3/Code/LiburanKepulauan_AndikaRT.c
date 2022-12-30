#include <stdio.h>

int baris, kolom;
int luas = 0;
int max_luas = 0;
int pulau = 0;

void cek_rute(int arr[baris][kolom], int a, int b)
{
    if (arr[a][b] == 1 && a >= 0 && b >= 0 && a < baris && b < kolom)
    {
        arr[a][b] = 0;
        luas++;

        if (luas >= max_luas)
        {
            max_luas = luas;
        }

        cek_rute (arr, a-1, b); // atas
        cek_rute (arr, a, b+1); // kanan
        cek_rute (arr, a+1, b); // bawah
        cek_rute (arr, a, b-1); // kiri
    }

}

void jumlah_pulau (int arr[baris][kolom], int p, int q) // kek ditandain
{
    if (arr[p][q] == 1)
    {
        cek_rute (arr, p, q);
        pulau++;
        luas = 0; // reset luas
    }
}

int main()
{
    // Your code goes here
    scanf ("%d%d", &baris, &kolom); // input

    int peta[baris][kolom];
    // int a = 0; // index luas
    // int banyak = 0;
    
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            scanf ("%d", &peta[i][j]); // input peta
        }
        
    }

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            jumlah_pulau (peta, i, j); // nyari pulau
        }
    }
    printf ("Banyak Pulau: %d\n", pulau);
    printf ("Luas Terbesar: %d", max_luas);

    return 0;
}