#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void ubahnamabarang(){
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
	                printf("Masukkan nama barang baru:\n");
					scanf(" %[^\n]s", barang.nama);	
					
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
