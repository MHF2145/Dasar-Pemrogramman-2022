#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void carikode(){
	system("cls");
	FILE *fplap;
	struct order struk = {"", "", 0, 0, 0, 0, 0, 0, 0};
	
	if ((fplap = fopen("riwayat.dat", "rb+")) == NULL){
    	printf("File could not be opened.\n");
        fclose(fplap);
	}
    else{
    	while(1){
    		fplap = fopen("riwayat.dat", "rb+");
			
    		printf("Masukkan kode barang:\n");
		    char carikode[4];
		    scanf("%s", carikode);
		    system("cls");
		    	
		    if(!strcmp(carikode, "000")){
		        break;
		    }
		    
		    int terjual = 0;
			int pendapatan = 0;

	    	while(!feof(fplap)){ 
		        if(fread(&struk, sizeof(struct order), 1, fplap)){
		            if(!strcmp(struk.kode, carikode)){
		            	if (terjual == 0){
		            		printf("%-7s%-14s%6s%14s%20s%8s\n", "Kode", "Nama Barang", "Jumlah", 
							"Total Harga", "Tanggal Transaksi", "Waktu");
						}
		                printf("%-7s%-14s%6d%14d", 
		                struk.kode, struk.nama, struk.banyak, struk.harga);
						if (struk.day < 10){
	            			printf("%11s%d/", "0", struk.day);
						}
						else {
							printf("%12d/", struk.day);
						}
						if (struk.mon < 10){
							printf("0%d/", struk.mon);
						}
						else {
							printf("%d/", struk.mon);
						}
	            		printf("%d", struk.year);
	            		if (struk.hour < 10){
	            			printf("   0%d:", struk.hour);
						}
						else {
							printf("   %d:", struk.hour);
						}
						if (struk.min < 10){
							printf("0%d\n", struk.min);
						}
						else {
							printf("%d\n", struk.min);
						}
						
						terjual += struk.banyak;
						pendapatan += struk.harga;
		            }
		        }   
		    }
		    
		    if (terjual == 0){
		    	printf("Tidak ada transaksi yang ditemukan\n");
			}
			else {
				printf("Total barang terjual : %d\n", terjual);
				printf("Total pendapatan     : %d\n", pendapatan);
			}
		    printf("\n");
			fclose(fplap);   
		}	
	}
}

void caritahun(){
	system("cls");
	FILE *fplap;
	struct order struk = {"", "", 0, 0, 0, 0, 0, 0, 0};
	
	if ((fplap = fopen("riwayat.dat", "rb+")) == NULL){
    	printf("File could not be opened.\n");
        fclose(fplap);
	}
    else{
    	while(1){
    		fplap = fopen("riwayat.dat", "rb+");
    		
    		printf("Masukkan tahun transaksi:\n");
		    int tahuntransaksi;
		    scanf("%d", &tahuntransaksi);
		    
		    system("cls");
		    if(tahuntransaksi == 0){
		        break;
		    }
		    
		    int terjual = 0;
			int pendapatan = 0;
		    
	    	while(!feof(fplap)){ 
		        if(fread(&struk, sizeof(struct order), 1, fplap)){
		            if(struk.year == tahuntransaksi){
		            	if (terjual == 0){
		            		printf("%-7s%-14s%6s%14s%20s%8s\n", "Kode", "Nama Barang", "Jumlah", 
							"Total Harga", "Tanggal Transaksi", "Waktu");
						}
		                printf("%-7s%-14s%6d%14d", 
		                struk.kode, struk.nama, struk.banyak, struk.harga);
						if (struk.day < 10){
	            			printf("%11s%d/", "0", struk.day);
						}
						else {
							printf("%12d/", struk.day);
						}
						if (struk.mon < 10){
							printf("0%d/", struk.mon);
						}
						else {
							printf("%d/", struk.mon);
						}
	            		printf("%d", struk.year);
	            		if (struk.hour < 10){
	            			printf("   0%d:", struk.hour);
						}
						else {
							printf("   %d:", struk.hour);
						}
						if (struk.min < 10){
							printf("0%d\n", struk.min);
						}
						else {
							printf("%d\n", struk.min);
						}
						
						terjual += struk.banyak;
						pendapatan += struk.harga;
		            }
		        }   
		    }
		    
		    if (terjual == 0){
		    	printf("Tidak ada transaksi yang ditemukan\n");
			}
			else {
				printf("Total barang terjual : %d\n", terjual);
				printf("Total pendapatan     : %d\n", pendapatan);
			}
			
		    printf("\n");
			fclose(fplap);   
		}	
	}
}

void caribulan(){
	system("cls");
	FILE *fplap;
	struct order struk = {"", "", 0, 0, 0, 0, 0, 0, 0};
	
	if ((fplap = fopen("riwayat.dat", "rb+")) == NULL){
    	printf("File could not be opened.\n");
        fclose(fplap);
	}
    else{
    	while(1){
    		fplap = fopen("riwayat.dat", "rb+");
    		
    		printf("Masukkan tahun transaksi:\n");
		    int tahuntransaksi;
		    scanf("%d", &tahuntransaksi);
		    
		    if(tahuntransaksi == 0){
		    	system("cls");
		        break;
		    }
		    
		    printf("Masukkan bulan transaksi:\n");
		    int bulantransaksi;
		    scanf("%d", &bulantransaksi);
		
			int terjual = 0;
			int pendapatan = 0;
		    
		    system("cls");
	    	while(!feof(fplap)){ 
		        if(fread(&struk, sizeof(struct order), 1, fplap)){
		            if(struk.year == tahuntransaksi){
		            	if(struk.mon == bulantransaksi){
		            		if (terjual == 0){
		            		printf("%-7s%-14s%6s%14s%20s%8s\n", "Kode", "Nama Barang", "Jumlah", 
							"Total Harga", "Tanggal Transaksi", "Waktu");
						}
		                printf("%-7s%-14s%6d%14d", 
		                struk.kode, struk.nama, struk.banyak, struk.harga);
						if (struk.day < 10){
	            			printf("%11s%d/", "0", struk.day);
						}
						else {
							printf("%12d/", struk.day);
						}
						if (struk.mon < 10){
							printf("0%d/", struk.mon);
						}
						else {
							printf("%d/", struk.mon);
						}
	            		printf("%d", struk.year);
	            		if (struk.hour < 10){
	            			printf("   0%d:", struk.hour);
						}
						else {
							printf("   %d:", struk.hour);
						}
						if (struk.min < 10){
							printf("0%d\n", struk.min);
						}
						else {
							printf("%d\n", struk.min);
						}
							
							terjual += struk.banyak;
							pendapatan += struk.harga;
						}
		            }
		        }   
		    }
		    
		    if (terjual == 0){
		    	printf("Tidak ada transaksi yang ditemukan\n");
			}
			else {
				printf("Total barang terjual : %d\n", terjual);
				printf("Total pendapatan     : %d\n", pendapatan);
			}
			
		    printf("\n");
			fclose(fplap);   
		}	
	}
}

void caritanggal(){
	system("cls");
	FILE *fplap;
	struct order struk = {"", "", 0, 0, 0, 0, 0, 0, 0};
	
	if ((fplap = fopen("riwayat.dat", "rb+")) == NULL){
    	printf("File could not be opened.\n");
        fclose(fplap);
	}
    else{
    	while(1){
    		fplap = fopen("riwayat.dat", "rb+");
    		
    		printf("Masukkan tahun transaksi:\n");
		    int tahuntransaksi;
		    scanf("%d", &tahuntransaksi);
		    
		    if(tahuntransaksi == 0){
		    	system("cls");
		        break;
		    }
		    
		    printf("Masukkan bulan transaksi:\n");
		    int bulantransaksi;
		    scanf("%d", &bulantransaksi);
		    printf("Masukkan tanggal transaksi:\n");
		    int tgltransaksi;
		    scanf("%d", &tgltransaksi);
		    
		    int terjual = 0;
		    int pendapatan = 0;
		    
		    system("cls");
	    	while(!feof(fplap)){ 
		        if(fread(&struk, sizeof(struct order), 1, fplap)){
		            if(struk.year == tahuntransaksi){
		            	if(struk.mon == bulantransaksi){
		            		if(struk.day == tgltransaksi){
		            			if (terjual == 0){
		            		printf("%-7s%-14s%6s%14s%20s%8s\n", "Kode", "Nama Barang", "Jumlah", 
							"Total Harga", "Tanggal Transaksi", "Waktu");
						}
		                printf("%-7s%-14s%6d%14d", 
		                struk.kode, struk.nama, struk.banyak, struk.harga);
						if (struk.day < 10){
	            			printf("%11s%d/", "0", struk.day);
						}
						else {
							printf("%12d/", struk.day);
						}
						if (struk.mon < 10){
							printf("0%d/", struk.mon);
						}
						else {
							printf("%d/", struk.mon);
						}
	            		printf("%d", struk.year);
	            		if (struk.hour < 10){
	            			printf("   0%d:", struk.hour);
						}
						else {
							printf("   %d:", struk.hour);
						}
						if (struk.min < 10){
							printf("0%d\n", struk.min);
						}
						else {
							printf("%d\n", struk.min);
						}
								
								terjual += struk.banyak;
								pendapatan += struk.harga;
							}
						}
		            }
		        }   
		    }
		    
		    if (terjual == 0){
		    	printf("Tidak ada transaksi yang ditemukan\n");
			}
			else {
				printf("Total barang terjual : %d\n", terjual);
				printf("Total pendapatan     : %d\n", pendapatan);
			}
			
		    printf("\n");
			fclose(fplap);   
		}	
	}
}
