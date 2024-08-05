#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void inp_mk()
{
	system("cls");
	FILE *fp = fopen("isi_mk.dat", "a");
	
	if(fp == NULL)
	{
		printf("File list Mata Kuliah tidak bisa dibuka!?!?!?");
		
		fclose(fp);
	}
	else
	{
	struct isi_mk isimk = {0, 0, "", ""};
		
		while(1)
		{
			printf("Ketik 0 untuk kembali ke Main Menu\n\n");
			printf("Masukkan ID Mata Kuliah(6-digit):\n");
			scanf("%d",&isimk.id);
			
			if(isimk.id == 0)
			{
				break;
			}
			else
			{
				printf("Masukkan nama Mata Kuliah(Singkat):\n");
				scanf("%s",&isimk.mk);
				
				printf("Masukkan nama Dosen Pengajar(Panggilan):\n");
				scanf("%s",&isimk.dosen);
								
				printf("Masukkan Jumlah Mahasiswa:\n");
				scanf("%d",&isimk.jml_mhssw);
				
				size_t hasil = fwrite(&isimk, sizeof(isimk), 1, fp);
				
				if(hasil != 1)		//Untuk mengecek bisa mencetak data dalam file atau tidak
				{
					printf("Gagal memasukkan data!!!\n");
				}
			}
			
			system("cls");
			printf("Note: Ketik 0 untuk kembali ke Main Menu\n\n");			
		}
	}
	
	fclose(fp);
}

