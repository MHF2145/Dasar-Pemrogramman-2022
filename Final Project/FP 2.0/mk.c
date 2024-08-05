#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void mk()
{
	FILE *fp = fopen("isi_mk.dat", "r");
	
	if(fp == NULL)
	{
		printf("File list Mata Kuliah tidak bisa dibuka!?!?!?");
		
		return;
	}
	
	struct isi_mk isimk = {0, 0, "", ""};
	
	printf("\n\n//ID Mata Kuliah\tNama Mata Kuliah\tJumlah Mahasiswa\tDosen Pengajar\t\\\\\n");
	printf("||======================================================================================||\n");
	
	while(fread(&isimk, sizeof(isimk), 1, fp) == 1)
	{
		printf("||%d\t\t%s\t\t\t%d\t\t\t%s\t\t||\n", isimk.id, isimk.mk, isimk.jml_mhssw, isimk.dosen);
	}
	
	if(ferror(fp))
	{
		printf("File list Mata Kuliah tidak bisa dibuka!?!?!?");
	}
	
	fclose(fp);
}
