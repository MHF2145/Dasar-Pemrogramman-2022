#include<stdio.h>
#include<stdlib.h>

struct isi_mhssw			//datanya mahasiswa
{
	int nim;
	float ips;
	char nama[21];
	char email[21];
	char departemen[21];
};

struct isi_dosen			//datanya dosen
{
	int nim;
	char nama[21];
	char email[21];
	char departemen[21];
};

struct isi_mk				//datanya mata kuliah
{
	int id;
	int jml_mhssw;
	char dosen[21];
	char mk[21];
};

void inp_mhssw();			//f(x) input mahasiswa
void inp_dosen();			//f(x) input dosen
void inp_mk();				//f(x) input mata kuliah
void mhhssw();				//f(x) list mhssw
void dosen();				//f(x) list dosen
void mk();					//f(x) list mk


