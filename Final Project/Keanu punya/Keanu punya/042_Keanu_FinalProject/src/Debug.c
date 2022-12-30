#include <stdio.h>
#include "../include/Data.h"
#include "../include/Debug.h"

void printError(const char *msg) {
    printf("\033[1;31mERROR: %s\n\033[0m", msg);
}

void printDosen(Dosen *dataDosen, DataSettings *dataSettings) {
    if (dataDosen == NULL || dataSettings == NULL) {
        if (dataDosen == NULL) {
            printError("Dosen *dataDosen is NULL");
        }
        if (dataSettings == NULL) {
            printError("DataSettings *dataSettings is NULL");
        }

        return;
    }

    for (int i = 0; i < dataSettings->structSize_Dosen; i++) {
        printf("%-20s %-30s\n", dataDosen[i].NIP, dataDosen[i].nama);
    } 
}

void printMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings) {
    if (dataMahasiswa == NULL || dataSettings == NULL) {
        if (dataMahasiswa == NULL) {
            printError("Mahasiswa *dataMahasiswa is NULL");
        }
        if (dataSettings == NULL) {
            printError("DataSettings *dataSettings is NULL");
        }

        return;
    }

    for (int i = 0; i < dataSettings->structSize_Mahasiswa; i++) {
        printf("%-20s %-30s %-50s\n", dataMahasiswa[i].NRP, dataMahasiswa[i].nama, dataMahasiswa[i].alamat);
    }
}

void printMatkul(Matkul *dataMatkul, DataSettings *dataSettings) {
    if (dataMatkul == NULL || dataSettings == NULL) {
        if (dataMatkul == NULL) {
            printError("Matkul *dataMatkul is NULL");
        }
        if (dataSettings == NULL) {
            printError("DataSettings *dataSettings is NULL");
        }

        return;
    }

    for (int i = 0; i < dataSettings->structSize_Matkul; i++) {
        printf("%-10s %-20s %d SKS\n", dataMatkul[i].kode, dataMatkul[i].nama, dataMatkul[i].sks);
    }
}

void printPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta) {
    if (dataPesertaKuliah == NULL || dataSettings == NULL || dataMatkul == NULL || dataDosen == NULL || dataPeserta == NULL) {
        if (dataPesertaKuliah == NULL) {
            printError("PesertaKuliah *dataPesertaKuliah is NULL");
        }
        if (dataSettings == NULL) {
            printError("DataSettings *dataSettings is NULL");
        }
        if (dataMatkul == NULL) {
            printError("Matkul *dataMatkul is NULL");
        }
        if (dataDosen == NULL) {
            printError("Dosen *dataDosen is NULL");
        }
        if (dataPeserta == NULL) {
            printError("Mahasiswa *dataPeserta is NULL");
        }

        return;
    }

    for (int i = 0; i < dataSettings->structSize_PesertaKuliah; i++) {
        printf("%s %s %s %s %s %s %d %d %.2f %s\n", dataPesertaKuliah[i].matkul->kode, dataPesertaKuliah[i].matkul->nama, dataPesertaKuliah[i].dosen->NIP, dataPesertaKuliah[i].dosen->nama, dataPesertaKuliah[i].peserta->NRP, dataPesertaKuliah[i].peserta->nama, dataPesertaKuliah[i].uts, dataPesertaKuliah[i].uas, dataPesertaKuliah[i].rerata, dataPesertaKuliah[i].grade);
    }
}