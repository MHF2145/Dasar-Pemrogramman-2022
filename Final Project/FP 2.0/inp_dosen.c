#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void inp_dosen()
{
	system("cls");
	FILE *fp = fopen("isi_dosen.dat", "a");
	
	if(fp == NULL)
	{
		printf("File list dosen tidak bisa dibuka!?!?!?");
		
		fclose(fp);
	}
	else
	{
	struct isi_dosen isidosen = {0, "", "", ""};
		
		while(1)
		{
			printf("Ketik 0 untuk kembali ke Main Menu\n\n");
			printf("Masukkan NIM Dosen(10-digit):\n");
			scanf("%d",&isidosen.nim);
			
			if(isidosen.nim == 0)
			{
				break;
			}
			else
			{
				printf("Masukkan nama Dosen(Panggilan):\n");
				scanf("%s",&isidosen.nama);
				
				printf("Masukkan Email Dosen:\n");
				scanf("%s",&isidosen.email);
								
				printf("Masukkan nama Departemen:\n");
				scanf("%s",&isidosen.departemen);
				
				size_t hasil = fwrite(&isidosen, sizeof(isidosen), 1, fp);
				
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

