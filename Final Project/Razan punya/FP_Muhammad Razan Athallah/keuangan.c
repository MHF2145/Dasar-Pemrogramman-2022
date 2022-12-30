#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void keuangan(){
	system("cls");
    FILE *fp;
    struct info barang = {"", "", 0, 0, 0, 0, 0};

    if ((fp = fopen("listbarang.dat", "rb")) == NULL) {
        printf("File could not be opened.\n");
        fclose(fp);
    }
    else{ 
		int ketemu = 0;
		int sisastok = 0;
		int modal = 0;
		int balik = 0;
		int status = 0;

        while(!feof(fp)){ 
            if(fread(&barang, sizeof(struct info), 1, fp)){
                if(strcmp(barang.kode, "000") && strcmp(barang.nama, "")){
                	if (ketemu == 0){
                		printf("LAPORAN KEUANGAN\n");
                		printf("%-7s%-14s%-7s%-13s%-13s%-13s%s\n",
						"Kode", "Nama Barang", "Stok", "Harga Jual", "Pengeluaran", "Pendapatan", "Laba/Rugi");
					}
                    printf("%-7s%-14s%4d%13d%14d%12d%12d\n", 
                    barang.kode, barang.nama, barang.stok, barang.hargajual, 
					barang.modal, barang.balik, barang.status);
					
					sisastok += barang.stok;
					modal += barang.modal;
					balik += barang.balik;
					
					ketemu = 1;
                }
            }   
        }
        
        if (ketemu == 0){
        	printf("Belum ada barang yang dimasukkan!\n\n");
		} 
		else {
			printf("Stok tersisa      : %d\n", sisastok);
			printf("Total Pengeluaran : %d\n", modal);
	        printf("Total Pendapatan  : %d\n", balik);
	        printf("Status Keuangan   : ");
	        status = balik - modal;
	    	if (status < 0){
	    		status *= -1;
	    		printf("Rugi %d\n\n", status);
			}
			else if (status >= 0){
				printf("Laba %d\n\n", status);
			}
		}
        
		fclose(fp);
    }
}

