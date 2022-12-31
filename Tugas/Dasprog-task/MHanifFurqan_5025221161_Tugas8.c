#include<stdio.h>
#include<string.h>
 
 
typedef struct
{
	char nama[30];
	int id;
    float persen;
}data;
 
int main(){
	int n = 5, i;
    // n = 5 dikarenakan data yang akan di input ada 5
    //  namun bisa juga dipakai scanf("%d", &n); 
    // untuk menentukan jumlah data yang akan di input
 
	data nilai[n + 1];

    printf("Silahkan memasukkan data dengan format berikut ini\n");
    printf("ID[Spasi]Nama(spasi untuk nama diganti '.'[Spasi]Nilai siswa\n");

	for(i = 0; i < n; i++)
    {
        scanf("%d %s %f", &nilai[i].id, nilai[i].nama, &nilai[i].persen );
	}

    // Sample Input saya sendiri, maaf mas ngga bisa make sample input yg di soal karena input nama memakai spasi
    // 1 Hanif.Furqan 75.99
    // 2 Arya.Gading 70.55
    // 3 GIlang.Kista 74.52
    // 4 Ivan.Adinata 73.48
    // 5 Wendy.Gata 75.32

    for(i = 0; i < n; i++)
    {
        printf("ID: %d Nama: %s Persentasi: %.2f%c\n", nilai[i].id, nilai[i].nama, nilai[i].persen, '%');
	}

    // Output:
    // ID: 1 Nama: Hanif.Furqan Persentasi: 75.99%
    // ID: 2 Nama: Arya.Gading Persentasi: 70.55% 
    // ID: 3 Nama: GIlang.Kista Persentasi: 74.52%
    // ID: 4 Nama: Ivan.Adinata Persentasi: 73.48%
    // ID: 5 Nama: Wendy.Gata Persentasi: 75.32%

	return 0;
}