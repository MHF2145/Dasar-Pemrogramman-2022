#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void inputbarang(){
	system("cls");
    FILE *fp;
    struct info barang = {"", "", 0, 0, 0, 0, 0};

    if ((fp = fopen("listbarang.dat", "rb+")) == NULL){
        printf("File could not be opened.\n");
        fclose(fp);
    }
	else {
		while(1){ 
	        printf("Masukkan kode barang:\n");
	        scanf("%s", barang.kode);
	        if(!strcmp(barang.kode, "000")){
	        	system("cls");
	            break;
	        }
	
	        printf("Masukkan nama barang:\n");
	        scanf(" %[^\n]s", barang.nama);
	
	        int p = atoi(barang.kode);       
	        
	        fseek(fp, (p - 1) * sizeof(struct info), SEEK_SET);
	        fwrite(&barang, sizeof(struct info), 1, fp);
	        system("cls");
	    }
	}
    
    fclose(fp);
}

