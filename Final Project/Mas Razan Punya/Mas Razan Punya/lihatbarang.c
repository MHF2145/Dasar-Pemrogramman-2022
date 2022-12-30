#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void lihatbarang(){
	system("cls");
    FILE *fp;
    struct info barang = {"", "", 0, 0, 0, 0, 0};

    if ((fp = fopen("listbarang.dat", "rb")) == NULL) {
        printf("File could not be opened.\n");
        fclose(fp);
    }
    else{
    	int ketemu = 0;

        while(!feof(fp)){ 
            if(fread(&barang, sizeof(struct info), 1, fp)){
                if(strcmp(barang.kode, "000") && strcmp(barang.nama, "")){
                	if (ketemu == 0){
                		printf("%-7s%-14s%-7s%-13s%\n",
						"Kode", "Nama Barang", "Stok", "Harga Jual");
					}
                    printf("%-7s%-14s%4d%13d\n", 
                    barang.kode, barang.nama, barang.stok, barang.hargajual);
                    ketemu = 1;
                }
            }   
        }
        if (ketemu == 0){
        	printf("Belum ada barang yang dimasukkan!\n");
		}
        printf("\n");
        fclose(fp);
    }
}

