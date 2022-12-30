#include <stdio.h>
#include <string.h>

int jumlah_kartu;

typedef struct
{
    char nama_kartu[10001];
    int poin_kartu;
}data_kartu;

void swap(data_kartu var[], int x, int y)
{
    data_kartu temp;
    temp = var[x];
    var[x] = var[y];
    var[y] = temp;
}

void cetak(data_kartu var[], int p)
{
    for (int j = 0; j < p; j++)
    {
        printf ("%s ", var[j].nama_kartu);
        printf ("%d\n", var[j].poin_kartu);
    }
}

int main()
{
    // Your code goes here
    scanf ("%d", &jumlah_kartu);
    data_kartu card[jumlah_kartu];
    for (int i = 0; i < jumlah_kartu; i++)
    {
        // char temp [1001];
        scanf ("\n%[^\n]%*c", card[i].nama_kartu);
        scanf (" %d", &card[i].poin_kartu);
        // strcpy (, temp);
    }

    // int flag = 1;
    while (1)
    {
        char perintah;
        scanf ("%c", &perintah);

        if (perintah == 'x')
        {
            break;
        }
        else if (perintah == 's')
        {
            int a,b;
            scanf ("%d %d", &a, &b);
            if (a > jumlah_kartu - 1 || b > jumlah_kartu - 1)
            {
                printf("Index diluar batas\n");
            }
            else if (a == b)
            {
                printf ("Index tidak boleh sama\n");
            }
            else
            {
                swap(card, a, b);
            }
            
        }
        else if (perintah == 'p')
        {
            cetak(card, jumlah_kartu);
        }
        // else if (perintah == 'x')
        // {
        //     break;
        // }
    }
    
    return 0;
}