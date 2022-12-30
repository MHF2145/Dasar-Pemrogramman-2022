#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void transaksi(){
	FILE *fp, *fpstr, *fplap;
	struct info barang = {"", "", 0, 0, 0, 0, 0};
	struct order struk = {"", "", 0, 0, 0, 0, 0, 0, 0};
	
	if ((fp = fopen("listbarang.dat", "rb+")) == NULL){
        printf("File could not be opened.\n");
        fclose(fp);
    }
    else if ((fpstr = fopen("struk.dat", "wb")) == NULL){
    	printf("File could not be opened.\n");
        fclose(fpstr);
	}
	else if ((fplap = fopen("riwayat.dat", "ab")) == NULL){
		printf("File could not be opened.\n");
        fclose(fplap);
	}
    else{
    	int hour;
    	int min;
    	int day;
    	int mon;
    	int year;
		int urutanstruk = 1;
		int tidakcukup = 0;
		totalharga = 0;
		
    	while(1){
    		fp = fopen("listbarang.dat", "rb+");
    		fpstr = fopen("struk.dat", "rb+");
    		fplap = fopen("riwayat.dat", "ab");
    		
    		lihatbarang();
    		
    		if (tidakcukup == 1){
    			printf("Stok tidak cukup!\n\n");
			}
			
			tidakcukup = 0;
    		
    		printf("Masukkan kode barang yang dibeli:\n");
	    	char carikode[4];
	    	scanf("%s", carikode);
	    	
	    	if (!strcmp(carikode, "000")){
	    		break;
			}
			else {
				while(!feof(fp)){
	            fread(&barang, sizeof(struct info), 1, fp);
		            if (!strcmp(barang.kode, carikode)){
		                printf("Masukkan jumlah %s yang dibeli:\n", barang.nama);
		                int kurangstok;
		                scanf("%d", &kurangstok);
		                
		                if (kurangstok > barang.stok){
		                	tidakcukup = 1;
		                	break;
						}
						else {
							barang.stok -= kurangstok;
			                barang.balik += barang.hargajual * kurangstok;
			                totalharga += barang.hargajual * kurangstok;
			                barang.status = barang.balik - barang.modal;
			                
			                int p = atoi(barang.kode);
			                fseek(fp, (p - 1) * sizeof(struct info), SEEK_SET);                   
			                fwrite(&barang, sizeof(struct info), 1, fp);
			                
			                strcpy(struk.kode, barang.kode);
			                strcpy(struk.nama, barang.nama);
			                struk.banyak = kurangstok;
			                struk.harga = barang.hargajual * kurangstok;
			                
			                if (urutanstruk == 1){
			                	time_t currtime;
			                	time(&currtime);
			                	struct tm *local = localtime(&currtime);
			                	hour = local->tm_hour;
			                	min = local->tm_min;
			                	day = local->tm_mday;
			                	mon = local->tm_mon + 1;
			                	year = local->tm_year + 1900;
							}
			                
			                struk.hour = hour;
			                struk.min = min;
			                struk.day = day;
			                struk.mon = mon;
			                struk.year = year;
			                
			                fseek(fpstr, (urutanstruk - 1) * sizeof(struct order), SEEK_SET);
			                fwrite(&struk, sizeof(struct order), 1, fpstr);
			                
			                fwrite(&struk, sizeof(struct order), 1, fplap);
			                
			                urutanstruk++;
							break;
						}	
					}
		        }	
			}
			fclose(fp);
			fclose(fpstr);
			fclose(fplap);
		}
		if (totalharga > 0){
			printf("\nTotal belanja anda sebesar %d\n", totalharga);
			while(1){
				printf("Masukkan jumlah uang tunai yang dibayarkan: ");
				scanf("%d", &bayar);
				kembali = bayar - totalharga;
				if (kembali == 0){
					printf("Tidak ada kembalian\n\n");
					break;
				}
				else if (kembali > 0){
					printf("Kembalian anda sebesar %d\n\n", kembali);
					break;
				}
				else {
					printf("Uang tunai yang dibayarkan tidak cukup\n\n");
				}
			}
		}
		else {
			printf("\n");
		}
	}
}
