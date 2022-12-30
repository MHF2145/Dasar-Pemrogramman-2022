#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(){
    while(1){
        int command;
        printf("MENU UTAMA\n");
        printf("(1) Transaksi\n");
        printf("(2) Struk Transaksi\n");
        printf("(3) Riwayat Transaksi\n");
        printf("(4) Data Barang\n");
        printf("(5) Laporan Keuangan\n");     
        printf("(0) Exit\n");
        printf("Masukkan angka sesuai perintah:\n");
        scanf("%d", &command);
        
        if (command == 1){
            transaksi();
        }
        else if (command == 2){
        	struktransaksi();
		}
		else if (command == 3){
			system("cls");
			while(1){
				int what;
				printf("RIWAYAT TRANSAKSI\n");
	            printf("(1) Cari sesuai kode\n");
	            printf("(2) Cari sesuai tahun\n");
	            printf("(3) Cari sesuai bulan\n");
	            printf("(4) Cari sesuai tanggal\n");
	            printf("(0) Kembali ke menu utama\n");
	            printf("Masukkan angka sesuai perintah:\n");
	            scanf("%d", &what);
	                
	            if (what == 1){
	            	carikode();
	            }
	            else if (what == 2){
					caritahun();
	            }
	            else if (what == 3){
					caribulan();
				}
	            else if (what == 4){
					caritanggal();
	            }
	            else if (what == 0){
	            	system("cls");
	            	break;
				}
	            else {
	                printf("Masukkan angka yang benar!\n\n");
	            }
			}
		}
        else if (command == 4){
        	system("cls");
        	while(1){
        		int what;
        		printf("DATA BARANG\n");
	            printf("(1) Input barang baru\n");
	            printf("(2) Tambah stok barang\n");
	            printf("(3) Ubah nama barang\n");
	            printf("(4) Ubah harga jual\n");
	            printf("(5) Lihat data barang\n");
	            printf("(0) Kembali ke menu utama\n");
	            printf("Masukkan angka sesuai perintah:\n");
	            scanf("%d", &what);
	                
	            if (what == 1){
	                inputbarang();
	            }
	            else if (what == 2){
	            	inputstok();
	            }
	            else if (what == 3){
	            	ubahnamabarang();
				}
	            else if (what == 4){
					ubahhargajual();
	            }
	            else if (what == 5){
	                lihatbarang();    
	            }
	            else if (what == 0){
	            	system("cls");
	            	break;
				}
	            else {
	                printf("Masukkan angka yang benar!\n\n");
	            }
			}    
        }
        else if (command == 5){
			keuangan();
        }
        else if (command == 0){
            break;
        }
        else {
            printf("Masukkan angka yang benar!\n\n");
        }
    }
}
