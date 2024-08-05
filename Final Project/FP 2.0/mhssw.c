#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void mhssw()
{
	FILE *fp = fopen("isi_mhssw.dat", "r");
	
	if(fp == NULL)
	{
		printf("File list Mahasiswa tidak bisa dibuka!?!?!?");
		
		return;
	}
	
		struct isi_mhssw isimhssw = {0, 0, "", "", ""};
	
	printf("\n\n//Nama\t\t\tNIM\t\t\tEmail\t\t\tDepartemen\t\t\tIPS \\\\ \n");
	printf("||==========================================================================================================||\n");
		
	while(fread(&isimhssw, sizeof(isimhssw), 1, fp) == 1)
	{
		printf("||%s\t\t\t%d\t\t\t%s\t\t%s\t\t\t%.2f||\n", isimhssw.nama, isimhssw.nim, isimhssw.email, isimhssw.departemen, isimhssw.ips);
	}
	
	if(ferror(fp))
	{
		printf("File list Mahasiswa tidak bisa dibuka!?!?!?");
	}
	
	fclose(fp);
}
