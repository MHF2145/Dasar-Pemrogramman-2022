#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void inputstok(){
	system("cls");
	FILE *fp;
	struct info barang = {"", "", 0, 0, 0, 0, 0};
	
	if ((fp = fopen("listbarang.dat", "rb+")) == NULL) {
        printf("File could not be opened.\n");
        fclose(fp);
    }
    else{
    	while(1){
			fp = fopen("listbarang.dat", "rb+");
			lihatbarang();
			
    		printf("Masukkan kode barang:\n");
	    	char carikode[4];
	    	scanf("%s", carikode);
	    	
	    	if(!strcmp(carikode, "000")){
	        	system("cls");
	            break;
	        }	        
	    	
			while(!feof(fp)){
	            fread(&barang, sizeof(struct info), 1, fp);
	            if (!strcmp(barang.kode, carikode)){
	                printf("Masukkan jumlah stok yang akan ditambahkan:\n");
	                int tambahstok;
	                scanf("%d", &tambahstok);
	                barang.stok += tambahstok;
	                
	                int hargabeli;
	                printf("Masukkan harga beli per barang:\n");
	                scanf("%d", &hargabeli);
	                barang.modal += hargabeli * tambahstok;
	                barang.status = barang.balik - barang.modal;
	                	
	                if (barang.hargajual == 0){
	                	printf("Tetapkan harga jual per barang:\n");
	               		scanf("%d", &barang.hargajual);
					}
					
					int p = atoi(barang.kode);
	                fseek(fp, (p - 1) * sizeof(struct info), SEEK_SET);                   
	                fwrite(&barang, sizeof(struct info), 1, fp);
					break;	
				}
	        }
			fclose(fp);
			system("cls");
		}
    } 
}
