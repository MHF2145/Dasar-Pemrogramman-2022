#include <string.h>
#include <malloc.h>
#include "../include/Data.h"
#include "../include/ErrorList.h"

void *initializeEmptyData(void) {
    return malloc(0);
}


char *scoreToGrade(float score) {
    if (score <= 40) {
        return "E";
    }
    else if (score <= 55) {
        return "D";
    }
    else if (score <= 60) {
        return "C";
    }
    else if (score <= 65) {
        return "BC";
    }
    else if (score <= 75) {
        return "B";
    }
    else if (score <= 85) {
        return "AB";
    }
    else if (score <= 100) {
        return "A";
    }
    else {
        return "NA";
    }
}


int inputDosen(Dosen **dataDosen, DataSettings *dataSettings, const char *NIP, const char *nama) {  
    Dosen *temp = realloc(*dataDosen, (dataSettings->structSize_Dosen + 1) * sizeof(Dosen));
    if (temp == NULL) {
        return ERROR_NOMEMORY;
    }

    int insertPosition = 0;
    while (insertPosition < dataSettings->structSize_Dosen && strcmp(temp[insertPosition].NIP, NIP) < 0) {
        insertPosition++;
    }

    if (insertPosition < dataSettings->structSize_Dosen) {  
        memmove(temp+insertPosition+1, temp+insertPosition, (dataSettings->structSize_Dosen - insertPosition)*sizeof(Dosen));
    }

    strcpy(temp[insertPosition].NIP, NIP);
    strcpy(temp[insertPosition].nama, nama);
    *dataDosen = temp;
    dataSettings->structSize_Dosen++;
    return PROCCESS_SUCCESS;
}

int inputMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings, const char *NRP, const char *nama, const char *alamat) {
    Mahasiswa *temp = realloc(*dataMahasiswa, (dataSettings->structSize_Mahasiswa + 1) * sizeof(Mahasiswa));
    if (temp == NULL) {
        return ERROR_NOMEMORY;
    }

    int insertPosition = 0;
    while (insertPosition < dataSettings->structSize_Mahasiswa && strcmp(temp[insertPosition].NRP, NRP) < 0) {
        insertPosition++;
    }

    if (insertPosition < dataSettings->structSize_Mahasiswa) {
        memmove(temp+insertPosition+1, temp+insertPosition, (dataSettings->structSize_Mahasiswa - insertPosition) * sizeof(Mahasiswa));
    }

    strcpy(temp[insertPosition].NRP, NRP);
    strcpy(temp[insertPosition].nama, nama);
    strcpy(temp[insertPosition].alamat, alamat);
    *dataMahasiswa = temp;
    dataSettings->structSize_Mahasiswa++;
    return PROCCESS_SUCCESS;
}

int inputMatkul(Matkul **dataMatkul, DataSettings *dataSettings, const char *kode, const char *nama, int sks) {
    Matkul *temp = realloc(*dataMatkul, (dataSettings->structSize_Matkul + 1) * sizeof(Matkul));
    if (temp == NULL) {
        return ERROR_NOMEMORY;
    }

    int insertPosition = 0;
    while (insertPosition < dataSettings->structSize_Matkul && strcmp(temp[insertPosition].kode, kode) < 0) {
        insertPosition++;
    }

    if (insertPosition < dataSettings->structSize_Matkul) {
        memmove(temp+insertPosition+1, temp+insertPosition, (dataSettings->structSize_Matkul - insertPosition) * sizeof(Matkul));
    }

    strcpy(temp[insertPosition].kode, kode);
    strcpy(temp[insertPosition].nama, nama);
    temp[insertPosition].sks = sks;
    *dataMatkul = temp;
    dataSettings->structSize_Matkul++;
    return PROCCESS_SUCCESS;
}

int inputPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings* dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta) {
    PesertaKuliah *temp = realloc(*dataPesertaKuliah, (dataSettings->structSize_PesertaKuliah + 1) * sizeof(PesertaKuliah));
    if (temp == NULL) {
        return ERROR_NOMEMORY;
    }

    int insertPosition = 0;
    // Sort by matkul->kode
    while (insertPosition < dataSettings->structSize_PesertaKuliah && strcmp(temp[insertPosition].matkul->kode, matkul->kode) < 0) {
        insertPosition++;
    }

    // Sort by dosen->NIP
    while (insertPosition < dataSettings->structSize_PesertaKuliah && strcmp(temp[insertPosition].matkul->kode, matkul->kode) == 0 && strcmp(temp[insertPosition].dosen->NIP, dosen->NIP) < 0) {
        insertPosition++;
    }

    // Sort by peserta->NRP
    while (insertPosition < dataSettings->structSize_PesertaKuliah && strcmp(temp[insertPosition].dosen->NIP, dosen->NIP) == 0 && strcmp(temp[insertPosition].peserta->NRP, peserta->NRP) < 0) {
        insertPosition++;
    }

    if (insertPosition < dataSettings->structSize_PesertaKuliah) {
        memmove(temp+insertPosition+1, temp+insertPosition, (dataSettings->structSize_PesertaKuliah - insertPosition) * sizeof(PesertaKuliah));
    }

    temp[insertPosition].matkul = matkul;
    temp[insertPosition].dosen = dosen;
    temp[insertPosition].peserta = peserta;
    temp[insertPosition].uts = SCORE_EMPTY;
    temp[insertPosition].uas = SCORE_EMPTY;
    temp[insertPosition].rerata = AVG_EMPTY;
    strcpy(temp[insertPosition].grade, "E");
    strcpy(temp[insertPosition].key_kode, matkul->kode);
    strcpy(temp[insertPosition].key_NIP, dosen->NIP);
    strcpy(temp[insertPosition].key_NRP, peserta->NRP);
    *dataPesertaKuliah = temp;
    dataSettings->structSize_PesertaKuliah++;
    return PROCCESS_SUCCESS;
}

int inputNilai(PesertaKuliah *dataPesertaKuliah, DataSettings* dataSettings, int insertPosition, int uts, int uas) {
    if (insertPosition == NOT_FOUND) {
        return NOT_FOUND;
    }
    if (insertPosition >= dataSettings->structSize_PesertaKuliah) {
        return ERROR_INVALIDMEMORY;
    }

    dataPesertaKuliah[insertPosition].uts = uts;
    dataPesertaKuliah[insertPosition].uas = uas;
    dataPesertaKuliah[insertPosition].rerata = (uts+uas)/2.0f;
    strcpy(dataPesertaKuliah[insertPosition].grade, scoreToGrade(dataPesertaKuliah[insertPosition].rerata));
    return PROCCESS_SUCCESS;
}

int searchDosen(Dosen *dataDosen, DataSettings *dataSettings, const char *NIP) {
    int l = 0, r = dataSettings->structSize_Dosen-1, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (strcmp(dataDosen[mid].NIP, NIP) < 0) {
            l = mid+1;
        }
        else if (strcmp(dataDosen[mid].NIP, NIP) > 0) {
            r = mid-1;
        }
        else {
            return mid;
        }
    }

    return NOT_FOUND;
}

int searchMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings, const char *NRP) {
    int l = 0, r = dataSettings->structSize_Mahasiswa-1, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (strcmp(dataMahasiswa[mid].NRP, NRP) < 0) {
            l = mid+1;
        }
        else if (strcmp(dataMahasiswa[mid].NRP, NRP) > 0) {
            r = mid-1;
        }
        else {
            return mid;
        }
    }

    return NOT_FOUND;
}

int searchMatkul(Matkul *dataMatkul, DataSettings *dataSettings, const char *kode) {
    int l = 0, r = dataSettings->structSize_Matkul-1, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (strcmp(dataMatkul[mid].kode, kode) < 0) {
            l = mid+1;
        }
        else if (strcmp(dataMatkul[mid].kode, kode) > 0) {
            r = mid-1;
        } 
        else {
            return mid;
        }
    }

    return NOT_FOUND;
}

int searchPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, const char *kode, const char *NIP, const char *NRP) {
    int l = 0, r = dataSettings->structSize_PesertaKuliah-1, mid, idx = -1;

    // Lower bound for key_kode
    while (l <= r) {
        mid = (l+r)/2;
        if (strcmp(dataPesertaKuliah[mid].key_kode, kode) < 0) {
            l = mid+1;
        }
        else if (strcmp(dataPesertaKuliah[mid].key_kode, kode) > 0) {
            r = mid-1;
        }
        else {
            idx = mid;
            break;
        }
    }
    while (idx > 0 && strcmp(dataPesertaKuliah[idx-1].key_kode, kode) == 0) {
        idx--;
    }
    if (idx == -1) {
        return NOT_FOUND;
    }

    // Lower bound for key_NIP
    l = idx, r = dataSettings->structSize_PesertaKuliah-1, idx = -1;
    while (l <= r && strcmp(dataPesertaKuliah[l].key_kode, kode) == 0) {
        if (strcmp(dataPesertaKuliah[l].key_NIP, NIP) == 0) {
            idx = l;
        }
        l++;
    }
    if (idx == -1) {
        return NOT_FOUND;
    }

    // Exact index of key_NRP
    l = idx, r = dataSettings->structSize_PesertaKuliah-1, idx = -1;
    while (l <= r && strcmp(dataPesertaKuliah[l].key_NIP, NIP) == 0) {
        if (strcmp(dataPesertaKuliah[l].key_NRP, NRP) == 0) {
            idx = l;
        }
        l++;
    }
    if (idx == -1) {
        return NOT_FOUND;
    }
    else {
        return idx;
    }
}

int deleteDosen(Dosen **dataDosen, DataSettings *dataSettings, int deletePosition) {
    if (deletePosition == NOT_FOUND) {
        return NOT_FOUND;
    }
    if (deletePosition >= dataSettings->structSize_Dosen) {
        return ERROR_INVALIDMEMORY;
    }

    Dosen *temp = *dataDosen;
    
    memmove(temp+deletePosition, temp+deletePosition+1, (dataSettings->structSize_Dosen - deletePosition - 1) * sizeof(Dosen));
    temp = realloc(temp, (dataSettings->structSize_Dosen - 1) * sizeof(Dosen));
    *dataDosen = temp;
    dataSettings->structSize_Dosen--;
    return PROCCESS_SUCCESS;
}

int deleteMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings, int deletePosition) {
    if (deletePosition == NOT_FOUND) {
        return NOT_FOUND;
    }
    if (deletePosition >= dataSettings->structSize_Mahasiswa) {
        return ERROR_INVALIDMEMORY;
    }

    Mahasiswa *temp = *dataMahasiswa;

    memmove(temp+deletePosition, temp+deletePosition+1, (dataSettings->structSize_Mahasiswa - deletePosition - 1) * sizeof(Mahasiswa));
    temp = realloc(temp, (dataSettings->structSize_Mahasiswa - 1) * sizeof(Mahasiswa));
    *dataMahasiswa = temp;
    dataSettings->structSize_Mahasiswa--;
    return PROCCESS_SUCCESS;
}

int deleteMatkul(Matkul **dataMatkul, DataSettings *dataSettings, int deletePosition) {
    if (deletePosition == NOT_FOUND) {
        return NOT_FOUND;
    }
    if (deletePosition >= dataSettings->structSize_Matkul) {
        return ERROR_INVALIDMEMORY;
    }

    Matkul *temp = *dataMatkul;

    memmove(temp+deletePosition, temp+deletePosition+1, (dataSettings->structSize_Matkul - deletePosition - 1) * sizeof(Matkul));
    temp = realloc(temp, (dataSettings->structSize_Matkul - 1) * sizeof(Matkul));
    *dataMatkul = temp;
    dataSettings->structSize_Matkul--;
    return PROCCESS_SUCCESS;
}

int deletePesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, int deletePosition) {
    if (deletePosition == NOT_FOUND) {
        return NOT_FOUND;
    }
    if (deletePosition >= dataSettings->structSize_PesertaKuliah) {
        return ERROR_INVALIDMEMORY;
    }

    PesertaKuliah *temp = *dataPesertaKuliah;

    memmove(temp+deletePosition, temp+deletePosition+1, (dataSettings->structSize_PesertaKuliah - deletePosition - 1) * sizeof(PesertaKuliah));
    temp = realloc(temp, (dataSettings->structSize_PesertaKuliah - 1) * sizeof(PesertaKuliah));
    *dataPesertaKuliah = temp;
    dataSettings->structSize_PesertaKuliah--;
    return PROCCESS_SUCCESS;
}

int readjustPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta) {
    int newPosition;
    for (int i = 0; i < dataSettings->structSize_PesertaKuliah; i++) {
        // Fix Matkul *matkul if key_code does not match kode it points
        if (strcmp(dataPesertaKuliah[i].key_kode, dataPesertaKuliah[i].matkul->kode) != 0) {
            newPosition = searchMatkul(dataMatkul, dataSettings, dataPesertaKuliah[i].key_kode);
            if (newPosition != NOT_FOUND) {
                dataPesertaKuliah[i].matkul = &dataMatkul[newPosition];
            }
            else {
                deletePesertaKuliah(&dataPesertaKuliah, dataSettings, i);
                readjustPesertaKuliah(dataPesertaKuliah, dataSettings, dataMatkul, dataDosen, dataPeserta);
                continue;
            }
        }

        // Fix Dosen *dosen if key_NIP does not match NIP it points
        if (strcmp(dataPesertaKuliah[i].key_NIP, dataPesertaKuliah[i].dosen->NIP) != 0) {
            newPosition = searchDosen(dataDosen, dataSettings, dataPesertaKuliah[i].key_NIP);
            if (newPosition != NOT_FOUND) {
                dataPesertaKuliah[i].dosen = &dataDosen[newPosition];
            }
            else {
                deletePesertaKuliah(&dataPesertaKuliah, dataSettings, i);
                readjustPesertaKuliah(dataPesertaKuliah, dataSettings, dataMatkul, dataDosen, dataPeserta);
                continue;
            }
        }

        // Fix Mahasiswa *peserta if key_NRP does not match NRP it points
        if (strcmp(dataPesertaKuliah[i].key_NRP, dataPesertaKuliah[i].peserta->NRP) != 0) {
            newPosition = searchMahasiswa(dataPeserta, dataSettings, dataPesertaKuliah[i].key_NRP);
            if (newPosition != NOT_FOUND) {
                dataPesertaKuliah[i].peserta = &dataPeserta[newPosition];
            }
            else {
                deletePesertaKuliah(&dataPesertaKuliah, dataSettings, i);
                readjustPesertaKuliah(dataPesertaKuliah, dataSettings, dataMatkul, dataDosen, dataPeserta);
                continue;
            }
        }
    }

    return PROCCESS_SUCCESS;
}

int forceReadjustPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta) {
    int newPosition;
    for (int i = 0; i < dataSettings->structSize_PesertaKuliah; i++) {
        // Fix Matkul *matkul if key_code does not match kode it points
        newPosition = searchMatkul(dataMatkul, dataSettings, dataPesertaKuliah[i].key_kode);
        if (newPosition != NOT_FOUND) {
            dataPesertaKuliah[i].matkul = &dataMatkul[newPosition];
        }

        // Fix Dosen *dosen if key_NIP does not match NIP it points
        newPosition = searchDosen(dataDosen, dataSettings, dataPesertaKuliah[i].key_NIP);
        if (newPosition != NOT_FOUND) {
            dataPesertaKuliah[i].dosen = &dataDosen[newPosition];
        }

        // Fix Mahasiswa *peserta if key_NRP does not match NRP it points
        newPosition = searchMahasiswa(dataPeserta, dataSettings, dataPesertaKuliah[i].key_NRP);
        if (newPosition != NOT_FOUND) {
            dataPesertaKuliah[i].peserta = &dataPeserta[newPosition];
        }
    }

    return PROCCESS_SUCCESS;
}