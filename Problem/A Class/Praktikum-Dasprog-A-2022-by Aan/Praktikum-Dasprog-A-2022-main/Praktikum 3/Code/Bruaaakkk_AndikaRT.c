#include <stdio.h>
#include <string.h>

int baris, kolom;

void jalan(char arr[baris][kolom], int a, int b)
{
    if (arr[a][b] == '_' && a >= 0 && b >= 0 && a < baris && b < kolom) //cek bawah
    {
        arr[a][b] = '*';
        if (arr[a+1][b] == '_' && a >= 0 && b >= 0 && a < baris && b < kolom)
        {
            jalan(arr, a+1, b); //bawah
        }
        else
        {
            jalan(arr, a, b-1); // kiri
            jalan(arr, a, b+1); // kanan
        }
        
    }

    // else if (arr[a][b-1] == '_' || arr[a][b+1] == '_')
    // {
    //     if (arr[a][b-1] == '_' && a >= 0 && b-1 >= 0 && a < baris && b-1 < kolom) // cek kiri
    //     {
    //         arr[a][b-1] = '*'; 
    //         jalan(arr, a, b-1);
    //     }

    //     if (arr[a][b+1] == '_' && a >= 0 && b+1 >= 0 && a < baris && b+1 < kolom) // cek kanan
    //     {
    //         arr[a][b+1] = '*';
    //         jalan(arr, a, b+1); 
    //     }
    // }  
}

int main()
{
    // Your code goes here
    scanf ("%d%d", &baris, &kolom); // input
    char labirin[baris][kolom];

    for (int i = 0; i < baris; i++)
    {
        scanf ("%s", labirin[i]); //bikin labirin
    }

    for (int i = 0; i < kolom; i++)
    {
        // for (int j = 0; j < kolom; j++)
        // {
            if (labirin[0][i] == '*')
            {
                if (labirin [1][i] == '_')
                {
                    jalan(labirin, 1, i);
                }
                else
                {
                    jalan (labirin, 0, i-1); // cek kiri
                    jalan (labirin, 0, i+1); // cek kanan
                }
            }
        // }
    }

    // printf ("\n\n");

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf ("%c", labirin[i][j]);
            if (j == kolom - 1)
            {
                printf ("\n");
            }
        }
    }
    return 0;
}