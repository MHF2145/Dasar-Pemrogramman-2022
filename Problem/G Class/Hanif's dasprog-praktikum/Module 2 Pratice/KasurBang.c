#include <stdio.h>
#include <string.h>

int main () 
{
    char input[1001];
    char kiri;

   //  ga akan ngeprint , yang ngeprint compiler
    while (scanf ("%s", input) != EOF) 
    {
    //seberapa pangjang kalimat atau string
    int panjang = strlen(input);

    //biar dibalik
    int kanan = panjang - 1;

    for (int i = 0; i < kanan; i++) 
    {
    //biar huruf nya tersimpan
    kiri = input[i];
    input[i] = input[kanan];
    input[kanan] = kiri;
    kanan--;
    }

    printf("%s\n", input);
    }
    
    return 0;
}