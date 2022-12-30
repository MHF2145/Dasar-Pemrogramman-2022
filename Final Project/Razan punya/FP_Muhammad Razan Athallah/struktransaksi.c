#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void struktransaksi(){
	FILE *fpstr;
	struct order struk = {"", "", 0, 0, 0, 0, 0, 0, 0};
	
	if ((fpstr = fopen("struk.dat", "rb")) == NULL){
    	printf("File could not be opened.\n");
        fclose(fpstr);
	}
    else{
    	system("cls");
    	
    	int sekali = 1;
    	printf("Struk Transaksi\n");
		while(!feof(fpstr)){ 
            if(fread(&struk, sizeof(struct order), 1, fpstr)){
                if(strcmp(struk.kode, "000")){
                	if (sekali){
	            		printf("Tanggal dan Waktu: ");
	            		if (struk.day < 10){
	            			printf("0%d/", struk.day);
						}
						else {
							printf("%d/", struk.day);
						}
						if (struk.mon < 10){
							printf("0%d/", struk.mon);
						}
						else {
							printf("%d/", struk.mon);
						}
	            		printf("%d\t ", struk.year);
	            		if (struk.hour < 10){
	            			printf("0%d:", struk.hour);
						}
						else {
							printf("%d:", struk.hour);
						}
						if (struk.min < 10){
							printf("0%d\n\n", struk.min);
						}
						else {
							printf("%d\n\n", struk.min);
						}
	    				printf("%-7s%-14s%-12s%s\n", "Kode", "Nama Barang", "Jumlah", "Harga");
	    				sekali = 0;
					}
                    printf("%-7s%-14s%6d%11d\n", 
                    struk.kode, struk.nama, struk.banyak, struk.harga);
                }
            }   
        }
        fclose(fpstr);
        printf("----------------------------------------\n");
        printf("%29s%9d\n", "Total: ", totalharga);
        printf("%29s%9d\n", "Tunai: ", bayar);
        printf("%29s%9d\n", "Kembali: ", kembali);
	}
}
