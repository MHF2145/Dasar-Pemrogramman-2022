#include <stdio.h>
#include <string.h>

long int poin(unsigned long a);// deklarasi fungsi menghitung poin

int main()
{
    unsigned long tab;
    int keg;
    int resesi = 0;
    long ttl = 0;
    char YoN[7];


    scanf("%llu", &tab);
    scanf("%d", &keg);
    

    for (int i = 0; i < keg; i++) // perulangan untuk menghitung beban dan resesi
    {
        scanf("%s", YoN);
        if (!strcmp(YoN, "Iya")) // lalu dihubungkan dengan kategori Yes or No
        {
            unsigned long  beban;
            scanf("%llu", &beban);
            ttl += poin(beban);
    
            if (tab < beban)
            {
                resesi = 1;
                break;
            }

            else
            {
                tab -= beban;
            }
        }

        else if (!strcmp(YoN, "Tidak"))
        {
            unsigned long  beban;
            scanf("%llu", &beban);
            ttl = ttl + (poin(beban) * -1);
    
            if (tab < beban)
            {
                resesi = 1;
                break;
            }

            else
            {
                tab -= beban;
            }
        }
    }


// menentukan jika tab(uang) 
    if (resesi == 0 && tab > 0 && ttl > 0 ) 
    {
        printf("Ujana berakhir bahagia.\n"); // lebih dari uang pengeluaran(berarti sisa)
    }

    else if (resesi != 0 || tab <= 0 || ttl < 0 ) 
    {
        printf("Ujana tidak berakhir bahagia.\n"); // kurang dari uang pengeluaran(berarti resesi seperti kasus yang akan datang)
    }

    else if (resesi == 0 && tab > 0 && ttl == 0 ) 
    {
        printf("Ujana berakhir b aja.\n");// uang tetap(berarti ya gpp)
    }

    return 0;
}


// fungsi menghitung poin yang diberikan diatas
long poin(unsigned long a)
{
    long jml;
    if (a <= 100000)
    {
        jml = 1;
    }
    else if (a > 100000 && a <= 500000)
    {
        jml = 5;
    }
    else if (a > 500000 && a <= 10000000)
    {
        jml = 20;
    }
    else if (a > 10000000 && a <= 500000000)
    {
        jml = 35;
    }
    else if (a > 500000000)
    {
        jml = 50;
    }
    return jml;
}