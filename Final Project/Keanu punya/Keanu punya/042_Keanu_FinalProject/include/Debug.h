#ifndef _DEBUG_H
#define _DEBUG_H

#include "Data.h"

void printError(const char *msg);

void printDosen(Dosen *dataDosen, DataSettings *dataSettings);
void printMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings);
void printMatkul(Matkul *dataMatkul, DataSettings *dataSettings);
void printPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);

#endif