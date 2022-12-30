#include <stdio.h>
#include "../include/ErrorList.h"
#include "../include/UI.h"

void clearScreen(void) {
    printf("\e[1;1H\e[2J");
}

void setColor(const char* color) {
    printf("%s", color);
}

void printLogo(void) {
    setColor(COLOR_BLUE);
    printf("                                          &                                         \n");
    printf("                                 &#######%%&/*******&                                \n");
    printf("                                /&#####&&   &&*****&                                \n");
    printf("                   &&&      &&&########&    &%%********&&&     .&&&                  \n");
    printf("                &&#####&&&#############&& &*&&*************&&&*****&&               \n");
    printf("             &&##################&&&&  && & &&  &&&&******************&%%            \n");
    printf("           &&###############&&         && & &&         &&***************&&          \n");
    printf("         &&#############&&            &&& & &&             &&*************&&        \n");
    printf("          &##########&&               &.& & &&(               &&**********&         \n");
    printf("            &######&&                 & & & &.&                 &&******&           \n");
    printf("          &&######&                   & & & & &                   &******&&         \n");
    printf("         &######&                     & & & & &                    /&*****%%&        \n");
    printf("        %%&#####&                      & &/&.& &                      &*****&.       \n");
    printf("   &##########&/              &&&&    &.&...& &    &&&&              &&**********&  \n");
    printf("   &##########&        &&&&   &&....&&&.......&&&....&    &&&&        &**********&  \n");
    printf("   &#########%%&         &....&&&....&&.........&#....&&&....&         &**********&  \n");
    printf("  &&#########&.          &....&#...&............(&...&.....&          %%&*********&  \n");
    printf("   &#########%%&          &....&...&&.............&....&....&          &**********&  \n");
    printf("   &##########&          &...&,...&...............&...&(...&          &**********&  \n");
    printf("   &&&&&&#####&*         &...&....&...............&....&...&         &&*****&&&&&&  \n");
    printf("        %%&#####&         &...&....&...............&.../&...&         &*****&.       \n");
    printf("         &######&        &....&....&.............&....&....&       /&*****%%&        \n");
    printf("          &&######&       &&....&...&...........&...&....&%%       &******&&         \n");
    printf("           &#######&&        &&&..&&.&&.......&&.&/..&&(        &&******#&          \n");
    printf("        &&###########&&            #&&&&&...&&&&&             &%%***********&.       \n");
    printf("         &&#############&&       &&   &.  &  #&   &&       &&*************&(        \n");
    printf("           &&##############&&/    /&%%     &     &&.    #&#**************&&          \n");
    printf("             &&##############&     &/     &     &&     &**************&,            \n");
    printf("                &&####%%&&&################&****************&&&*****&&               \n");
    printf("                   &&%%      &&&###########&**********(&&&      &&&                  \n");
    printf("                                &#########&*********&                               \n");
    printf("                                &#########&*********&                               \n");
    setColor(COLOR_DEFAULT);
}

void printMainMenu(void) {
    clearScreen();
    setColor(COLOR_CYAN);
    printf("======================================================================================\n");
    printf("|                SELAMAT DATANG DI SISTEM INFORMASI AKADEMIK MAHASISWA               |\n");
    printf("======================================================================================\n\n");
    setColor(COLOR_DEFAULT);
    printLogo();
    setColor(COLOR_CYAN);
    printf("\n=======================================================================================\n");
    printf("|                                     MAIN MENU                                       |\n");
    printf("=======================================================================================\n\n");
    printf("         (1) Lihat Data Dosen                (10) Lihat Data Peserta Kuliah            \n");
    printf("         (2) Input Data Dosen                (11) Input Data Peserta Kuliah            \n");
    printf("         (3) Hapus Data Dosen                (12) Hapus Data Peserta Kuliah            \n");
    printf("         (4) Lihat Data Mahasiswa            (13) Input Nilai Peserta Kuliah           \n");
    printf("         (5) Input Data Mahasiswa            (14) Informasi Data                       \n");
    printf("         (6) Hapus Data Mahasiswa            (15) Simpan Paksa Data                    \n");
    printf("         (7) Lihat Data Matkul               (16) Informasi Perangkat Lunak            \n");
    printf("         (8) Input Data Matkul               (17) Keluar                               \n");
    printf("         (9) Hapus Data Matkul                                                         \n");
    printf("\n\n");
    setColor(COLOR_DEFAULT);
}


int tabulateDosen(Dosen *dataDosen, DataSettings *dataSettings) {
    if (dataDosen == NULL || dataSettings == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("=============================================================================\n");
    printf("|         NIP          |                      Nama                          |\n");
    printf("=============================================================================\n");
    for (int i = 0; i < dataSettings->structSize_Dosen; i++) {
        fprintf(stdout, "| %-20s | %-50s |\n", dataDosen[i].NIP, dataDosen[i].nama);
    }
    printf("=============================================================================\n");

    return PROCCESS_SUCCESS;
}

int tabulateMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings) {
    if (dataMahasiswa == NULL || dataSettings == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("==============================================================================================================\n");
    printf("|         NRP          |               Nama             |                        Alamat                      |\n");
    printf("==============================================================================================================\n");
    for (int i = 0; i < dataSettings->structSize_Mahasiswa; i++) {
        fprintf(stdout, "| %-20s | %-30s | %-50s |\n", dataMahasiswa[i].NRP, dataMahasiswa[i].nama, dataMahasiswa[i].alamat);
    }
    printf("==============================================================================================================\n");
    
    return PROCCESS_SUCCESS;
}

int tabulateMatkul(Matkul *dataMatkul, DataSettings *dataSettings) {
    if (dataMatkul == NULL || dataSettings == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("========================================================\n");
    printf("|    KODE    |              Nama              |   SKS  |\n");
    printf("========================================================\n");
    for (int i = 0; i < dataSettings->structSize_Matkul; i++) {
        fprintf(stdout, "| %-10s | %-30s | %-2d SKS |\n", dataMatkul[i].kode, dataMatkul[i].nama, dataMatkul[i].sks);
    }
    printf("========================================================\n");

    return PROCCESS_SUCCESS;
}

int tabulatePesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta) {
    if (dataPesertaKuliah == NULL || dataSettings == NULL || dataMatkul == NULL || dataDosen == NULL || dataPeserta == NULL) {
        return ERROR_INVALIDMEMORY;
    }

    printf("============================================================================================================================================================================================\n");
    printf("|   KODE     |          Nama Matkul           |       NIP Dosen      |          Nama Dosen            |  NRP Mahasiswa  |         Nama Mahasiswa         |  ETS  |  EAS  |   AVG   | Grade |\n");
    printf("============================================================================================================================================================================================\n");
    for (int i = 0; i < dataSettings->structSize_PesertaKuliah; i++) {
        fprintf(stdout, "| %-10s | %-30s | %-20s | %-30s | %-15s | %-30s | %5d | %5d | %7.2f |   %s   |\n", dataPesertaKuliah[i].matkul->kode, dataPesertaKuliah[i].matkul->nama, dataPesertaKuliah[i].dosen->NIP, dataPesertaKuliah[i].dosen->nama, dataPesertaKuliah[i].peserta->NRP, dataPesertaKuliah[i].peserta->nama, dataPesertaKuliah[i].uts, dataPesertaKuliah[i].uas, dataPesertaKuliah[i].rerata, dataPesertaKuliah[i].grade);
    }
    printf("============================================================================================================================================================================================\n");


    return ERROR_NOMEMORY;
}