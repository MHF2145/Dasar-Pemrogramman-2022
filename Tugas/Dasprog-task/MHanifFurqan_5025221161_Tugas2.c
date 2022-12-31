#include <stdio.h>

int main () {
    int i;
    int Ratusan, Puluhan, Satuan;

    printf (" Masukan Bilangan = " );
    scanf (" %d", &i );

    Ratusan = i/100;
    Puluhan = (i - Ratusan*100)/10;
    Satuan = (i - Ratusan*100 - Puluhan*10);

    printf (" Ratusan = %d \n Puluhan = %d \n Satuan = %d \n ", Ratusan, Puluhan, Satuan );

    return 0;
    
}