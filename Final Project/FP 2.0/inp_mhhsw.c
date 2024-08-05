#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void inp_mhssw()
{
	system("cls");
	FILE *fp = fopen("isi_mhssw.dat", "a");
	
	if(fp == NULL)
	{
		printf("File list Dosen tidak bisa dibuka!?!?!?");
		
		fclose(fp);
	}
	else
	{
		struct isi_mhssw isimhssw = {0, 0, "", "", ""};
		
		while(1)
		{
			printf("Ketik 0 untuk kembali ke Main Menu\n\n");
			printf("Masukkan NIM Mahasiswa(10-digit):\n");
			scanf("%d",&isimhssw.nim);
			
			if(isimhssw.nim == 0)
			{
				break;
			}
			else
			{
				printf("Masukkan nama Mahasiswa(Panggilan):\n");
				scanf("%s",&isimhssw.nama);
				
				printf("Masukkan Email Mahasiwa:\n");
				scanf("%s",&isimhssw.email);
								
				printf("Masukkan nama Departemen:\n");
				scanf("%s",&isimhssw.departemen);
				
				printf("Masukkan nilai IPS(koma diganti titik):\n");
				scanf("%f",&isimhssw.ips);
				
				size_t hasil = fwrite(&isimhssw, sizeof(isimhssw), 1, fp);
				
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

