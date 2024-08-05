#include <string.h>
#include <stdio.h>


int z; // di deklarasi disini biar bisa langsung dipake di fungsi yg lain
char input[21]; // input string 
char output[21]; // string output terbesar dari kombinasi string input  
char s[21]; // penyimpanan sementara


void potong(int y); // fungsi untuk memotong string lalu dimasukkan ke fungsi selanjutnya
int urutkan(int a, int b); // fungsi untuk mengurutkan string yang input


int main()
{   
    scanf("%s", input); // angka diinput namun tipe data string
    scanf("%d", &z); // banyak digit yang diminta pada output terbesar dari kombinasi string

    potong(strlen(input) - z); //pemanggilan fungsi yang memotong string input

    printf("%s", output); // ya print output
}


void potong(int y)
{
    y = 0;
    for (int i = 0; i < (strlen(input) - z) + 1; i++)
    {
        urutkan(y + i, z + i); // setelah string dipotong dengan input angka berupa string dan digit terus dimasukkan fungsi untuk mengurutkan string dan kombinasi string
    }
}


int urutkan(int a, int b) // mengurutkan string
{
    int y = 0, i, j;
    char x;

    for (i = a; i < b; i++)
    {
        s[y] = input[i];
        y++;
    }

    for (i = 0; i < z - 1; i++)
    {
        for (j = 1 + i; j < z; j++)
        {
            if (s[j] > s[i])
            {
                x = s[j];
                s[j] = s[i];
                s[i] = x;
            }
        }
    }

    if (strcmp(s, output) > 0) // karena tring harus pake strcmp sama strcpy
    {
        strcpy(output, s);
    }
}
