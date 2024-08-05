#include<stdio.h>
#include<stdlib.h>
#include "structdanfx.h"

void dosen()
{
	FILE *fp = fopen("isi_dosen.dat", "r");
	
	if(fp == NULL)
	{
		printf("File list Dosen tidak bisa dibuka!?!?!?");
		
		return;
	}
	
	struct isi_dosen isidosen = {0, "", "", ""};
	
	printf("\n\n//Nama\t\t\tNIM\t\tEmail\t\t\t\tDepartemen\t\\\\\n");
	printf("||======================================================================================||\n");
	
	while(fread(&isidosen, sizeof(isidosen), 1, fp) == 1)
	{
		printf("||%s\t\t%d\t\t%s\t\t%s\t\t||\n", isidosen.nama, isidosen.nim, isidosen.email, isidosen.departemen);
	}
	
	if(ferror(fp))
	{
		printf("File list Dosen tidak bisa dibuka!?!?!?");
	}
	
	fclose(fp);
}
