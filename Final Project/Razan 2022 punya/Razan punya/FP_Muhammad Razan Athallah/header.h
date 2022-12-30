#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info{
    char kode[4];
    char nama[20];
    int stok;
    int hargajual;
    int modal;
    int balik;
    int status;
};

struct order{
	char kode[4];
	char nama[20];
	int banyak;
	int harga;
	int hour;
	int min;
	int day;
	int mon;
	int year;
};

int totalharga;
int bayar;
int kembali;

void transaksi();		// melakukan transaksi
void struktransaksi();	// mencetak struk transaksi
void carikode();		// melihat riwayat transaksi sesuai kode barang
void caritahun();		// melihat riwayat transaksi sesuai tahun transaksi
void caribulan();		// melihat riwayat transaksi sesuai bulan transaksi
void caritanggal();		// melihat riwayat transaksi sesuai tanggal transaksi
void inputbarang();     // memasukkan barang baru ke dalam list
void inputstok();		// menambah stok barang
void ubahkodebarang();	// mengubah kode barang
void ubahnamabarang();	// mengubah nama barang
void ubahhargajual();	// mengubah harga jual barang
void lihatbarang();     // melihat isi keseluruhan dari list
void keuangan();   		// melihat status keuangan


