#include <stdio.h>

int main(){
    int k, n, diskonKategori, totaldiskon1, totaldiskon2, diskonOngkir;
    scanf("%d %d", &k, &n);

    switch (k) //untuk kode
    {
    case 1 : //misal kode 1 maka 35 yang dipakai untuk persentase nantinya
    diskonKategori = 35;
    break;
    case 2 :
    diskonKategori = 45;
    break;
    case 3 :
    diskonKategori = 50;
    break;
    case 4 :
    diskonKategori = 55;
    break;
    case 5 :
    diskonKategori = 40;
    break;
    default:
    diskonKategori = 0;
    break;
    }

    totaldiskon1 = n - (n * diskonKategori / 100); //perhitungan diskon untuk barang
    //range untuk pembagian harga
    if(totaldiskon1 >= 50000 && totaldiskon1 < 150000){//misal, total harga barang yang telah didiskon di range 50000-150000 
        diskonOngkir = 25;
    } else if(totaldiskon1 >= 150000 && totaldiskon1 < 250000){
        diskonOngkir = 50;
    } else if(totaldiskon1 >= 250000){
        diskonOngkir = 100;
    } else if(totaldiskon1 < 50000){
        diskonOngkir = 0;
    }

    totaldiskon2 = totaldiskon1 + 50000 - (50000 * diskonOngkir / 100); //perhitungan total diskon
    
    if(totaldiskon2 > 300000){//menampilkan output
        printf("Mamaa minta uang, uangku kurang %d :((\n", (totaldiskon2 - 300000));
        printf("Totalnya tadi %d", totaldiskon2);
    } else if(totaldiskon2 < 300000){
        printf("WOHHHH uangku sisa %d\n", 300000 - totaldiskon2);
        printf("Mamaa Daffa bisa kasi THR ke adek adek, tadi totalnya %d", totaldiskon2);
    } else if(totaldiskon2 == 300000){
        printf("Yeyyy totalnya pas 300000\n");
        printf("Mamaa, Daffa udah gede ga jadi minta uang :)");
    }

return 0;
}