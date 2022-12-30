#include <stdio.h>
#include <string.h>

typedef struct 
{
    int ID;
    char username[21];
    char password[21];
    int kondisi;
}data_aktivitas;

data_aktivitas masukan_data()
{
    data_aktivitas var;
    scanf ("%d", &var.ID);
    scanf ("%s", var.username);
    scanf ("%s", var.password);
    var.kondisi = 0;
    return var;
}

int main()
{
    // Your code goes here
    int N, Q;
    scanf ("%d %d", &N, &Q);
    data_aktivitas pengguna[101];

    for (int i = 0; i < N; i++)
    {
        pengguna[i] = masukan_data();
    }

    int mencurigakan = 0;
    int tersangka[101];
    int indekusu = 0;

    for (int i = 0; i < Q; i++)
    {
        int orang_ke;
        int realita;
        scanf ("%d %d", &orang_ke, &realita);

        if (pengguna[orang_ke].kondisi == realita)
        {
            mencurigakan++;
            tersangka[indekusu] = orang_ke;
            indekusu++;
        }
        else
        {
            pengguna[orang_ke].kondisi = realita;
        }
    }

    printf ("%d\n", mencurigakan);
    for (int i = 0; i < indekusu; i++)
    {
        printf ("%d\n", pengguna[tersangka[i]-1].ID);
        printf ("%s\n", pengguna[tersangka[i]-1].username);
        printf ("%s\n", pengguna[tersangka[i]-1].password);
    }
    return 0;
}