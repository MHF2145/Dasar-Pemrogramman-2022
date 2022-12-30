#include <stdio.h>

int main () 
{
	char x[100];
    int i, j, n, y[50];

    scanf("%[^\n]", x); //String awal, masukin apa aja
    scanf("%d", &n); //Buat ngelimit nanti berapa banyak angka di garis ke tiga

    for (i = 0; i < n; i++)
    {
        scanf("%d", &y[i]); //ngecek apakah array yang diambil lebih dari string ato ga, kalo lebih dia ga ngambil
    }
    for (j = 0; j < n; j++)
    {
        printf("%c", x[y[j]]); //ngeprint array yang diambil dan udah dilimit di atasnya
    }
return 0;
}