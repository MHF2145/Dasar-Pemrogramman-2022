#ifndef _UI_H
#define _UI_H

#include "Data.h"

#define COLOR_DEFAULT "\033[0m"
#define COLOR_BLACK "\033[0;30m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_PURPLE "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_WHITE "\033[0;37m"

void clearScreen(void);
void setColor(const char* color);
void printLogo(void);
void printMainMenu(void);

int tabulateDosen(Dosen *dataDosen, DataSettings *dataSettings);
int tabulateMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings);
int tabulateMatkul(Matkul *dataMatkul, DataSettings *dataSettings);
int tabulatePesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);

#endif