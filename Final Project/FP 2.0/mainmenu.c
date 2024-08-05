#include<stdio.h>
#include "structdanfx.h"

void menu()
{
	printf("\t\t\t ________________________________\n");
	printf("\t\t\t/\tMain Menu\t\t\\\\ \n");
	printf("\t\t\t|1.Input Mahasiswa\t\t||\n");
	printf("\t\t\t|2.List Mahasiswa\t\t||\n");
	printf("\t\t\t|3.Input Dosen\t\t\t||\n");
	printf("\t\t\t|4.List Dosen\t\t\t||\n");
	printf("\t\t\t|5.Input Mata Kuliah\t\t||\n");
	printf("\t\t\t|6.List Mata Kuliah\t\t||\n");
	printf("\t\t\t|10.Exit\t\t\t||\n");
	printf("\t\t\t----------------------------------\n\n\n");
	
	printf("Tolong Masukkan angka sesuai Menu:\n");
}

int main()
{
	int pilihmenu;
	menu();
	
	scanf("%d", &pilihmenu);
	
	while(pilihmenu != 10)
	{
		if(pilihmenu == 1)
		{
			inp_mhssw();
		}
		else if(pilihmenu == 2)
		{
			mhssw();
		}
		else if(pilihmenu == 3)
		{
			inp_dosen();
		}
		else if(pilihmenu == 4)
		{
			dosen();
		}
		else if(pilihmenu == 5)
		{
			inp_mk();
		}
		else if(pilihmenu == 6)
		{
			mk();
		}
		else
		{
			printf("Pilihan anda tidak ada di Menu, tolong masukkan pilihan anda lagi: ");
		}
		
		menu();
			
		printf("Masukkan Pilihan anda:\n");

		scanf("%d", &pilihmenu);

		
		
	}
	return 0;
}
