#include <stdio.h>
#include <string.h>

#include "../include/Data.h"
#include "../include/UI.h"
#include "../include/ErrorList.h"
#include "../include/Scene.h"

int sceneLihatDataDosen(Dosen *dataDosen, DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("=============================================================================\n");
        printf("|                             Lihat Data Dosen                              |\n");
        printf("=============================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (dataSettings->structSize_Dosen == 0) {
            setColor(COLOR_RED);
            printf("           Data Anda masih kosong, silakan lakukan input data!         \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulateDosen(dataDosen, dataSettings);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS;
}

int sceneLihatDataMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Lihat Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");    
        setColor(COLOR_DEFAULT);

        if (dataSettings->structSize_Mahasiswa == 0) {
            setColor(COLOR_RED);
            printf("                               Data Anda masih kosong, silakan lakukan input data!                         \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulateMahasiswa(dataMahasiswa, dataSettings);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS; 
}

int sceneLihatDataMatkul(Matkul *dataMatkul, DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("========================================================\n");
        printf("|                Lihat Data Mata Kuliah                |\n");
        printf("========================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (dataSettings->structSize_Matkul == 0) {
            setColor(COLOR_RED);
            printf("   Data Anda masih kosong, silakan lakukan input data!  \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulateMatkul(dataMatkul, dataSettings);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS; 
}

int sceneLihatDataPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("============================================================================================================================================================================================\n");
        printf("|                                                                                   Lihat Data Peserta Kuliah                                                                              |\n");
        printf("============================================================================================================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (dataSettings->structSize_PesertaKuliah == 0) {
            setColor(COLOR_RED);
            printf("                                                                      Data Anda masih kosong, silakan lakukan input data!                                                                   \n\n");
            setColor(COLOR_DEFAULT);
        }
        else {
            tabulatePesertaKuliah(dataPesertaKuliah, dataSettings, dataMatkul, dataDosen, dataPeserta);
            printf("\n\n");
        }
        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS; 
}


int sceneInputDataDosen(Dosen **dataDosen, DataSettings *dataSettings) {
    int modifyPosition, operation, operationCancelled;
    char bufferNama[50];
    char bufferNIP[20];
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Input Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Nama Dosen      : ");
        fgets(bufferNama, 50, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferNama) > 0) {
            bufferNama[strlen(bufferNama)-1] = '\0';
        }

        fflush(stdin);
        printf("NIP Dosen       : ");
        fgets(bufferNIP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNIP) > 0) {
            bufferNIP[strlen(bufferNIP)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Input Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        modifyPosition = searchDosen(*dataDosen, dataSettings, bufferNIP);
        if (modifyPosition == -1) {
            printf("Anda akan memasukkan data dosen baru dengan rincian sebagai berikut:\n");
            printf("Nama Dosen      : %s\n", bufferNama);
            printf("NIP Dosen       : %s\n", bufferNIP);
        }
        else {
            printf("Anda akan memodifikasi data dosen yang telah ada dengan rincian sebagai berikut:\n");
            printf("Nama Dosen (Lama)   : %s\n", (*dataDosen)[modifyPosition].nama);
            printf("Nama Dosen (Baru)   : %s\n", bufferNama);
            printf("NIP Dosen           : %s\n\n", bufferNIP);
            printf("Sebagai catatan, NIP tidak dapat dimodifikasi!\n");
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input/pembaruan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input/pembaruan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            if (modifyPosition == -1) {
                inputDosen(dataDosen, dataSettings, bufferNIP, bufferNama);
            }
            else {
                strcpy((*dataDosen)[modifyPosition].nama, bufferNama);
            }
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Input Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input/pembaruan data dosen\n");
        }
        else {
            if (modifyPosition == -1) {
                printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
                printf("Nama Dosen      : %s\n", bufferNama);
                printf("NIP Dosen       : %s\n\n", bufferNIP);
            }
            else {
                printf("Berikut adalah rincian data yang telah berhasil Anda modifikasi:\n");
                printf("Nama Dosen (Baru)   : %s\n", bufferNama);
                printf("NIP Dosen           : %s\n\n", bufferNIP);
                printf("Sebagai catatan, NIP tidak dapat dimodifikasi!\n\n");
            }
        }

        printf("Silakan tekan (1) untuk melakukan input/pembaruan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}

int sceneInputDataMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings) {
    int modifyPosition, operation, operationCancelled;
    char bufferNRP[20];
    char bufferNama[50];
    char bufferAlamat[50];
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("NRP Mahasiswa       : ");
        fgets(bufferNRP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNRP) > 0) {
            bufferNRP[strlen(bufferNRP)-1] = '\0';
        }

        fflush(stdin);
        printf("Nama Mahasiswa      : ");
        fgets(bufferNama, 50, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferNama) > 0) {
            bufferNama[strlen(bufferNama)-1] = '\0';
        }

        fflush(stdin);
        printf("Alamat Mahasiswa    : ");
        fgets(bufferAlamat, 50, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferAlamat) > 0) {
            bufferAlamat[strlen(bufferAlamat)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        modifyPosition = searchMahasiswa(*dataMahasiswa, dataSettings, bufferNRP);
        if (modifyPosition == -1) {
            printf("Anda akan memasukkan data mahasiswa baru dengan rincian sebagai berikut:\n");
            printf("NRP Mahasiswa       : %s\n", bufferNRP);
            printf("Nama Mahasiswa      : %s\n", bufferNama);
            printf("Alamat Mahasiswa    : %s\n\n", bufferAlamat);
        }
        else {
            printf("Anda akan memodifikasi data mahasiswa yang telah ada dengan rincian sebagai berikut:\n");
            printf("NRP Mahasiswa               : %s\n", bufferNRP);
            printf("Nama Mahasiswa (Lama)       : %s\n", (*dataMahasiswa)[modifyPosition].nama);
            printf("Nama Mahasiswa (Baru)       : %s\n", bufferNama);
            printf("Alamat Mahasiswa (Lama)     : %s\n", (*dataMahasiswa)[modifyPosition].alamat);
            printf("Alamat Mahasiswa (Baru)     : %s\n", bufferAlamat);
            printf("Sebagai catatan, NRP tidak dapat dimodifikasi!\n\n");
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input/pembaruan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input/pembaruan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            if (modifyPosition == -1) {
                inputMahasiswa(dataMahasiswa, dataSettings, bufferNRP, bufferNama, bufferAlamat);
            }
            else {
                strcpy((*dataMahasiswa)[modifyPosition].nama, bufferNama);
                strcpy((*dataMahasiswa)[modifyPosition].alamat, bufferAlamat);
            }
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input/pembaruan data dosen\n");
        }
        else {
            if (modifyPosition == -1) {
                printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
                printf("NRP Mahasiswa       : %s\n", bufferNRP);
                printf("Nama Mahasiswa      : %s\n", bufferNama);
                printf("Alamat Mahasiswa    : %s\n\n", bufferAlamat);
            }
            else {
                printf("Berikut adalah rincian data yang telah berhasil Anda modifikasi:\n");
                printf("NRP Mahasiswa               : %s\n", bufferNRP);
                printf("Nama Mahasiswa (Baru)       : %s\n", bufferNama);
                printf("Alamat Mahasiswa (Baru)     : %s\n", bufferAlamat);
                printf("Sebagai catatan, NRP tidak dapat dimodifikasi!\n\n");
            }
        }

        printf("Silakan tekan (1) untuk melakukan input/pembaruan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}

int sceneInputDataMatkul(Matkul **dataMatkul, DataSettings *dataSettings) {
    int modifyPosition, operation, operationCancelled;
    char bufferKode[10];
    char bufferNama[30];
    int bufferSKS;
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Kode Mata Kuliah            : ");
        fgets(bufferKode, 10, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferKode) > 0) {
            bufferKode[strlen(bufferKode)-1] = '\0';
        }

        fflush(stdin);
        printf("Nama Mata Kuliah            : ");
        fgets(bufferNama, 30, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNama) > 0) {
            bufferNama[strlen(bufferNama)-1] = '\0';
        }
        fflush(stdin);

        printf("Jumlah SKS Mata Kuliah      : ");
        scanf("%d", &bufferSKS);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        modifyPosition = searchMatkul(*dataMatkul, dataSettings, bufferKode);
        if (modifyPosition == -1) {
            printf("Anda akan memasukkan data mata kuliah baru dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah            : %s\n", bufferKode);
            printf("Nama Mata Kuliah            : %s\n", bufferNama);
            printf("Jumlah SKS Mata Kuliah      : %d\n\n", bufferSKS);
        }
        else {
            printf("Anda akan memodifikasi data mahasiswa yang telah ada dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah            : %s\n", bufferKode);
            printf("Nama Mata Kuliah (Lama)     : %s\n", (*dataMatkul)[modifyPosition].nama);
            printf("Nama Mata Kuliah (Baru)     : %s\n", bufferNama);
            printf("Jumlah SKS (Lama)           : %d\n", (*dataMatkul)[modifyPosition].sks);
            printf("Jumlah SKS (Baru)           : %d\n", bufferSKS);
            printf("Sebagai catatan, kode mata kuliah tidak dapat dimodifikasi!\n\n");
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input/pembaruan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input/pembaruan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            if (modifyPosition == -1) {
                inputMatkul(dataMatkul, dataSettings, bufferKode, bufferNama, bufferSKS);
            }
            else {
                strcpy((*dataMatkul)[modifyPosition].nama, bufferNama);
                (*dataMatkul)[modifyPosition].sks = bufferSKS;
            }
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Input Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input/pembaruan data dosen\n");
        }
        else {
            if (modifyPosition == -1) {
                printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
                printf("Kode Mata Kuliah            : %s\n", bufferKode);
                printf("Nama Mata Kuliah            : %s\n", bufferNama);
                printf("Jumlah SKS Mata Kuliah      : %d\n\n", bufferSKS);
            }
            else {
                printf("Anda telah memodifikasi data mahasiswa yang telah ada dengan rincian sebagai berikut:\n");
                printf("Kode Mata Kuliah            : %s\n", bufferKode);
                printf("Nama Mata Kuliah (Baru)     : %s\n", bufferNama);
                printf("Jumlah SKS (Baru)           : %d\n", bufferSKS);
                printf("Sebagai catatan, kode mata kuliah tidak dapat dimodifikasi!\n\n");
            }
        }

        printf("Silakan tekan (1) untuk melakukan input/pembaruan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}

int sceneInputDataPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta) {
    int modifyPosition, operation, operationCancelled;
    char bufferKode[10];
    char bufferNIP[30];
    char bufferNRP[30];
    int matkulPosition, dosenPosition, mahasiswaPosition;
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Input Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Kode Mata Kuliah            : ");
        fgets(bufferKode, 10, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferKode) > 0) {
            bufferKode[strlen(bufferKode)-1] = '\0';
        }

        fflush(stdin);
        printf("NIP Dosen Pengampu          : ");
        fgets(bufferNIP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNIP) > 0) {
            bufferNIP[strlen(bufferNIP)-1] = '\0';
        }

        fflush(stdin);
        printf("NRP Peserta Kuliah          : ");
        fgets(bufferNRP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNRP) > 0) {
            bufferNRP[strlen(bufferNRP)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Input Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        matkulPosition = searchMatkul(matkul, dataSettings, bufferKode);
        dosenPosition = searchDosen(dosen, dataSettings, bufferNIP);
        mahasiswaPosition = searchMahasiswa(peserta, dataSettings, bufferNRP);
        modifyPosition = searchPesertaKuliah(*dataPesertaKuliah, dataSettings, bufferKode, bufferNIP, bufferNRP);
        if (matkulPosition == NOT_FOUND || dosenPosition == NOT_FOUND || mahasiswaPosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Anda berusaha memasukkan data yang belum terdaftar dalam sistem: \n\n");
            setColor(COLOR_DEFAULT);

            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            if (matkulPosition == NOT_FOUND) {
                printf("Nama Mata Kuliah        : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
                printf("Bobot SKS               : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
                printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            }

            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            if (dosenPosition == NOT_FOUND) {
                printf("Nama Dosen Pengampu     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            }


            printf("NRP Peserta Kuliah      : %s\n", bufferNRP);
            if (mahasiswaPosition == NOT_FOUND) {
                printf("Nama Peserta Kuliah     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            }

            printf("\nPeriksa kembali data Anda dan tekan (1) untuk mencoba ulang\n");
            printf("atau tekan selain (1) untuk kembali ke menu awal\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }

        if (modifyPosition == NOT_FOUND) {
            printf("Anda akan mendaftarkan peserta kuliah dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
            printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            printf("NRP Peserta Kuliah      : %s\n", peserta[mahasiswaPosition].NRP);
            printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            printf("Sebagai catatan, input nilai dilakukan dengan menu (13) Input Nilai Peserta Kuliah!\n\n");
        }
        else {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Peserta dengan data tersebut sudah terdaftar pada sistem dengan informasi sebagai berikut: \n\n");
            setColor(COLOR_DEFAULT);
            printf("Kode Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->kode);
            printf("Nama Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->nama);
            printf("Bobot SKS               : %d\n", (*dataPesertaKuliah)[modifyPosition].matkul->sks);
            printf("NIP Dosen Pengampu      : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->NIP);
            printf("Nama Dosen Pengampu     : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->nama);
            printf("NRP Peserta Kuliah      : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->NRP);
            printf("Nama Peserta Kuliah     : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->nama);

            if ((*dataPesertaKuliah[modifyPosition]).uts == SCORE_EMPTY) {
                printf("Nilai UTS               : Belum diinput\n");
            }
            else {
                printf("Nilai UTS               : %d\n", (*dataPesertaKuliah)[modifyPosition].uts);
            }

            if ((*dataPesertaKuliah[modifyPosition]).uas == SCORE_EMPTY) {
                printf("Nilai UAS               : Belum diinput\n");
            }
            else {
                printf("Nilai UAS               : %d\n", (*dataPesertaKuliah)[modifyPosition].uas);
            }

            if ((*dataPesertaKuliah[modifyPosition]).rerata == AVG_EMPTY) {
                printf("Nilai Rata-Rata         : Belum diinput\n");
            }
            else {
                printf("Nilai Rata-Rata         : %.2f\n", (*dataPesertaKuliah)[modifyPosition].rerata);
            }

            printf("Grade                   : %s\n\n", (*dataPesertaKuliah)[modifyPosition].grade);

            setColor(COLOR_RED);
            printf("Menu ini hanya digunakan untuk mendaftarkan peserta kuliah baru.\n");
            printf("Untuk melakukan input/ralat nilai, gunakan menu (13) Input Nilai Peserta Kuliah\n\n");
            setColor(COLOR_DEFAULT);

            printf("Tekan (1) untuk mencoba ulang proses input data atau tekan angka selain (1)\n");
            printf("untuk membatalkan input data dan kembali ke menu awal.\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input data\n");
        printf("atau tekan angka selain (1) untuk membatalkan input data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            inputPesertaKuliah(dataPesertaKuliah, dataSettings, matkul+matkulPosition, dosen+dosenPosition, peserta+mahasiswaPosition);
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Input Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input data peserta kuliah\n");
        }
        else {
            printf("Berikut adalah rincian data yang telah berhasil Anda input:\n");
            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
            printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            printf("NRP Peserta Kuliah      : %s\n", peserta[mahasiswaPosition].NRP);
            printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            printf("Sebagai catatan, input nilai dilakukan dengan menu (13) Input Nilai Peserta Kuliah!\n\n");
        }

        printf("Silakan tekan (1) untuk melakukan input/pembaruan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}

int sceneInputNilaiPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta) {
    int modifyPosition, operation, operationCancelled;
    char bufferKode[10];
    char bufferNIP[30];
    char bufferNRP[30];
    int matkulPosition, dosenPosition, mahasiswaPosition;
    int bufferUTS, bufferUAS;
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                          Input Nilai Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Kode Mata Kuliah            : ");
        fgets(bufferKode, 10, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferKode) > 0) {
            bufferKode[strlen(bufferKode)-1] = '\0';
        }

        fflush(stdin);
        printf("NIP Dosen Pengampu          : ");
        fgets(bufferNIP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNIP) > 0) {
            bufferNIP[strlen(bufferNIP)-1] = '\0';
        }

        fflush(stdin);
        printf("NRP Peserta Kuliah          : ");
        fgets(bufferNRP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNRP) > 0) {
            bufferNRP[strlen(bufferNRP)-1] = '\0';
        }
        fflush(stdin);

        printf("Nilai UTS Peserta Kuliah    : ");
        scanf("%d", &bufferUTS);

        printf("Nilai UAS Peserta Kuliah    : ");
        scanf("%d", &bufferUAS);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                          Input Nilai Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        matkulPosition = searchMatkul(matkul, dataSettings, bufferKode);
        dosenPosition = searchDosen(dosen, dataSettings, bufferNIP);
        mahasiswaPosition = searchMahasiswa(peserta, dataSettings, bufferNRP);
        modifyPosition = searchPesertaKuliah(*dataPesertaKuliah, dataSettings, bufferKode, bufferNIP, bufferNRP);
        if (matkulPosition == NOT_FOUND || dosenPosition == NOT_FOUND || mahasiswaPosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Anda berusaha memasukkan data yang belum terdaftar dalam sistem: \n\n");
            setColor(COLOR_DEFAULT);

            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            if (matkulPosition == NOT_FOUND) {
                printf("Nama Mata Kuliah        : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
                printf("Bobot SKS               : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
                printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            }

            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            if (dosenPosition == NOT_FOUND) {
                printf("Nama Dosen Pengampu     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            }


            printf("NRP Peserta Kuliah      : %s\n", bufferNRP);
            if (mahasiswaPosition == NOT_FOUND) {
                printf("Nama Peserta Kuliah     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            }

            printf("\nPeriksa kembali data Anda dan tekan (1) untuk mencoba ulang\n");
            printf("atau tekan selain (1) untuk kembali ke menu awal\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }

        if (modifyPosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Peserta dengan data dibawah belum terdaftar pada mata kuliah yang ditentukan: \n\n");
            setColor(COLOR_DEFAULT);
            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
            printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            printf("NRP Peserta Kuliah      : %s\n", peserta[mahasiswaPosition].NRP);
            printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            printf("Harap daftarkan peserta kuliah terlebih dahulu sebelum melakukan input nilai!\n\n");
            
            printf("Tekan (1) untuk mencoba ulang proses input nilai atau tekan angka selain (1)\n");
            printf("untuk membatalkan input data dan kembali ke menu awal.\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Berikut adalah rincian operasi input nilai pada peserta kuliah yang dipilih: \n\n");
            printf("Kode Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->kode);
            printf("Nama Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->nama);
            printf("Bobot SKS               : %d\n", (*dataPesertaKuliah)[modifyPosition].matkul->sks);
            printf("NIP Dosen Pengampu      : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->NIP);
            printf("Nama Dosen Pengampu     : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->nama);
            printf("NRP Peserta Kuliah      : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->NRP);
            printf("Nama Peserta Kuliah     : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->nama);

            if ((*dataPesertaKuliah[modifyPosition]).uts == SCORE_EMPTY) {
                printf("Nilai UTS (Lama)        : Belum diinput\n");
            }
            else {
                printf("Nilai UTS (Lama)        : %d\n", (*dataPesertaKuliah)[modifyPosition].uts);
            }
            printf("Nilai UTS (Baru)        : %d\n", bufferUTS);

            if ((*dataPesertaKuliah[modifyPosition]).uas == SCORE_EMPTY) {
                printf("Nilai UAS (Lama)        : Belum diinput\n");
            }
            else {
                printf("Nilai UAS (Lama)        : %d\n", (*dataPesertaKuliah)[modifyPosition].uas);
            }
            printf("Nilai UAS (Baru)        : %d\n", bufferUAS);

            if ((*dataPesertaKuliah[modifyPosition]).rerata == AVG_EMPTY) {
                printf("Nilai Rata-Rata (Lama)  : Belum diinput\n");
            }
            else {
                printf("Nilai Rata-Rata (Lama)  : %.2f\n\n", (*dataPesertaKuliah)[modifyPosition].rerata);
            }
            printf("Nilai Rata-Rata (Baru)  : %.2f\n", (bufferUTS+bufferUAS)/2.0f);

            printf("Grade (Lama)            : %s\n", (*dataPesertaKuliah)[modifyPosition].grade);
            printf("Grade (Baru)            : %s\n\n", scoreToGrade((bufferUTS+bufferUAS)/2.0f));
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan input nilai\n");
        printf("atau tekan angka selain (1) untuk membatalkan input nilai\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            inputNilai(*dataPesertaKuliah, dataSettings, modifyPosition, bufferUTS, bufferUAS);
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                          Input Nilai Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan input nilai peserta kuliah\n");
        }
        else {
            printf("Berikut adalah rincian data beserta nilai yang telah berhasil Anda input:\n");
            printf("Kode Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->kode);
            printf("Nama Mata Kuliah        : %s\n", (*dataPesertaKuliah)[modifyPosition].matkul->nama);
            printf("Bobot SKS               : %d\n", (*dataPesertaKuliah)[modifyPosition].matkul->sks);
            printf("NIP Dosen Pengampu      : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->NIP);
            printf("Nama Dosen Pengampu     : %s\n", (*dataPesertaKuliah)[modifyPosition].dosen->nama);
            printf("NRP Peserta Kuliah      : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->NRP);
            printf("Nama Peserta Kuliah     : %s\n", (*dataPesertaKuliah)[modifyPosition].peserta->nama);
            printf("Nilai UTS (Baru)        : %d\n", (*dataPesertaKuliah)[modifyPosition].uts);
            printf("Nilai UAS (Baru)        : %d\n", (*dataPesertaKuliah)[modifyPosition].uas);
            printf("Nilai Rerata (Baru)     : %.2f\n", (*dataPesertaKuliah)[modifyPosition].rerata);
            printf("Grade (Baru)            : %s\n\n", (*dataPesertaKuliah)[modifyPosition].grade);
        }

        printf("Silakan tekan (1) untuk melakukan input/pembaruan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}


int sceneDeleteDataDosen(Dosen **dataDosen, DataSettings *dataSettings) {
    int deletePosition, operation, operationCancelled;
    char bufferNIP[20];
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Hapus Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("NIP Dosen       : ");
        fgets(bufferNIP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNIP) > 0) {
            bufferNIP[strlen(bufferNIP)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Hapus Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        deletePosition = searchDosen(*dataDosen, dataSettings, bufferNIP);
        if (deletePosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Dosen dengan NIP %s tidak ditemukan di sistem.\n\n", bufferNIP);
            setColor(COLOR_DEFAULT);
            
            printf("Periksa kembali data Anda dan tekan (1) untuk mencoba ulang\n");
            printf("atau tekan selain (1) untuk kembali ke menu awal\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Anda akan menghapus data dosen dengan rincian sebagai berikut:\n");
            printf("NIP Dosen       : %s\n", (*dataDosen)[deletePosition].NIP);
            printf("Nama Dosen      : %s\n", (*dataDosen)[deletePosition].nama);
            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan penghapusan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan penghapusan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            deleteDosen(dataDosen, dataSettings, deletePosition);
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                              Hapus Data Dosen                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan operasi penghapusan data dosen\n");
        }
        else {
            printf("Anda telah menghapus data dosen dengan rincian sebagai berikut:\n");
            printf("NIP Dosen       : %s\n", bufferNIP);
            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);
        }

        printf("Silakan tekan (1) untuk melakukan penghapusan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}

int sceneDeleteDataMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings) {
    int deletePosition, operation, operationCancelled;
    char bufferNRP[20];
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Hapus Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("NRP Mahasiswa       : ");
        fgets(bufferNRP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNRP) > 0) {
            bufferNRP[strlen(bufferNRP)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Hapus Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        deletePosition = searchMahasiswa(*dataMahasiswa, dataSettings, bufferNRP);
        if (deletePosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Mahasiswa dengan NRP %s tidak ditemukan di sistem.\n\n", bufferNRP);
            setColor(COLOR_DEFAULT);
            
            printf("Periksa kembali data Anda dan tekan (1) untuk mencoba ulang\n");
            printf("atau tekan selain (1) untuk kembali ke menu awal\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Anda akan menghapus data mahasiswa dengan rincian sebagai berikut:\n");
            printf("NRP Mahasiswa       : %s\n", (*dataMahasiswa)[deletePosition].NRP);
            printf("Nama Mahasiswa      : %s\n", (*dataMahasiswa)[deletePosition].nama);
            printf("Alamat Mahasiswa    : %s\n", (*dataMahasiswa)[deletePosition].alamat);
            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan penghapusan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan penghapusan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            deleteMahasiswa(dataMahasiswa, dataSettings, deletePosition);
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Hapus Data Mahasiswa                                            |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan operasi penghapusan data mahasiswa\n");
        }
        else {
            printf("Anda telah menghapus data mahasiswa dengan rincian sebagai berikut:\n");
            printf("NRP Mahasiswa       : %s\n", bufferNRP);
            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);

        }

        printf("Silakan tekan (1) untuk melakukan penghapusan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}

int sceneDeleteDataMatkul(Matkul **dataMatkul, DataSettings *dataSettings) {
    int deletePosition, operation, operationCancelled;
    char bufferKode[10];
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Hapus Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Kode Mata Kuliah    : ");
        fgets(bufferKode, 10, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferKode) > 0) {
            bufferKode[strlen(bufferKode)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Hapus Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        deletePosition = searchMatkul(*dataMatkul, dataSettings, bufferKode);
        if (deletePosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Mata kuliah dengan kode %s tidak ditemukan di sistem.\n\n", bufferKode);
            setColor(COLOR_DEFAULT);
            
            printf("Periksa kembali data Anda dan tekan (1) untuk mencoba ulang\n");
            printf("atau tekan selain (1) untuk kembali ke menu awal\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);

            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Anda akan menghapus data mata kuliah dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah    : %s\n", (*dataMatkul)[deletePosition].kode);
            printf("Nama Mata Kuliah    : %s\n", (*dataMatkul)[deletePosition].nama);
            printf("Jumlah SKS          : %d\n", (*dataMatkul)[deletePosition].sks);
            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);
        }

        printf("Periksa kembali data dan tekan (1) untuk melakukan penghapusan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan penghapusan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            deleteMatkul(dataMatkul, dataSettings, deletePosition);
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Hapus Data Mata Kuliah                                          |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan operasi penghapusan data mata kuliah\n");
        }
        else {
            printf("Anda telah menghapus data mata kuliah dengan rincian sebagai berikut:\n");
            printf("Kode Mata Kuliah    : %s\n", bufferKode);
            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);
        }

        printf("Silakan tekan (1) untuk melakukan penghapusan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}

int sceneDeleteDataPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta) {
    int deletePosition, operation, operationCancelled;
    char bufferKode[10];
    char bufferNIP[30];
    char bufferNRP[30];
    int matkulPosition, dosenPosition, mahasiswaPosition;
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Hapus Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        fflush(stdin);
        printf("Kode Mata Kuliah            : ");
        fgets(bufferKode, 10, stdin);
        // Replace \n picked by fgets with null terminator 
        if (strlen(bufferKode) > 0) {
            bufferKode[strlen(bufferKode)-1] = '\0';
        }

        fflush(stdin);
        printf("NIP Dosen Pengampu          : ");
        fgets(bufferNIP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNIP) > 0) {
            bufferNIP[strlen(bufferNIP)-1] = '\0';
        }

        fflush(stdin);
        printf("NRP Peserta Kuliah          : ");
        fgets(bufferNRP, 20, stdin);
        // Replace \n picked by fgets with null terminator
        if (strlen(bufferNRP) > 0) {
            bufferNRP[strlen(bufferNRP)-1] = '\0';
        }
        fflush(stdin);

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Hapus Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        matkulPosition = searchMatkul(matkul, dataSettings, bufferKode);
        dosenPosition = searchDosen(dosen, dataSettings, bufferNIP);
        mahasiswaPosition = searchMahasiswa(peserta, dataSettings, bufferNRP);
        deletePosition = searchPesertaKuliah(*dataPesertaKuliah, dataSettings, bufferKode, bufferNIP, bufferNRP);
        if (matkulPosition == NOT_FOUND || dosenPosition == NOT_FOUND || mahasiswaPosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Anda berusaha menghapus data yang belum terdaftar dalam sistem: \n\n");
            setColor(COLOR_DEFAULT);

            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            if (matkulPosition == NOT_FOUND) {
                printf("Nama Mata Kuliah        : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
                printf("Bobot SKS               : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
                printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            }

            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            if (dosenPosition == NOT_FOUND) {
                printf("Nama Dosen Pengampu     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            }


            printf("NRP Peserta Kuliah      : %s\n", bufferNRP);
            if (mahasiswaPosition == NOT_FOUND) {
                printf("Nama Peserta Kuliah     : %sTIDAK DITEMUKAN%s\n", COLOR_RED, COLOR_DEFAULT);
            }
            else {
                printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            }

            printf("\nPeriksa kembali data Anda dan tekan (1) untuk mencoba ulang\n");
            printf("atau tekan selain (1) untuk kembali ke menu awal\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }

        if (deletePosition == NOT_FOUND) {
            setColor(COLOR_RED);
            printf("GAGAL!\n");
            printf("Peserta dengan data dibawah belum terdaftar pada mata kuliah yang ditentukan: \n\n");
            setColor(COLOR_DEFAULT);
            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            printf("Nama Mata Kuliah        : %s\n", matkul[matkulPosition].nama);
            printf("Bobot SKS               : %d\n", matkul[matkulPosition].sks);
            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            printf("Nama Dosen Pengampu     : %s\n", dosen[dosenPosition].nama);
            printf("NRP Peserta Kuliah      : %s\n", peserta[mahasiswaPosition].NRP);
            printf("Nama Peserta Kuliah     : %s\n", peserta[mahasiswaPosition].nama);
            printf("Peserta kuliah tidak dapat dihapus jika tidak terdaftar!\n\n");
            
            printf("Tekan (1) untuk mencoba ulang proses penghapusan data atau tekan angka selain (1)\n");
            printf("untuk membatalkan penghapusan data dan kembali ke menu awal.\n");
            printf("Pilihan Anda: ");
            scanf("%d", &operation);
            if (operation == 1) {
                continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Berikut adalah rincian data peserta kuliah yang akan dihapus: \n\n");
            printf("Kode Mata Kuliah        : %s\n", (*dataPesertaKuliah)[deletePosition].matkul->kode);
            printf("Nama Mata Kuliah        : %s\n", (*dataPesertaKuliah)[deletePosition].matkul->nama);
            printf("Bobot SKS               : %d\n", (*dataPesertaKuliah)[deletePosition].matkul->sks);
            printf("NIP Dosen Pengampu      : %s\n", (*dataPesertaKuliah)[deletePosition].dosen->NIP);
            printf("Nama Dosen Pengampu     : %s\n", (*dataPesertaKuliah)[deletePosition].dosen->nama);
            printf("NRP Peserta Kuliah      : %s\n", (*dataPesertaKuliah)[deletePosition].peserta->NRP);
            printf("Nama Peserta Kuliah     : %s\n", (*dataPesertaKuliah)[deletePosition].peserta->nama);

            if ((*dataPesertaKuliah[deletePosition]).uts == SCORE_EMPTY) {
                printf("Nilai UTS               : Belum diinput\n");
            }
            else {
                printf("Nilai UTS               : %d\n", (*dataPesertaKuliah)[deletePosition].uts);
            }

            if ((*dataPesertaKuliah[deletePosition]).uas == SCORE_EMPTY) {
                printf("Nilai UAS               : Belum diinput\n");
            }
            else {
                printf("Nilai UAS               : %d\n", (*dataPesertaKuliah)[deletePosition].uas);
            }

            if ((*dataPesertaKuliah[deletePosition]).rerata == AVG_EMPTY) {
                printf("Nilai Rata-Rata         : Belum diinput\n");
            }
            else {
                printf("Nilai Rata-Rata         : %.2f\n", (*dataPesertaKuliah)[deletePosition].rerata);
            }

            printf("Grade                   : %s\n\n", (*dataPesertaKuliah)[deletePosition].grade);

            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);
        }

        printf("Periksa kembali data dan tekan (1) untuk melanjutkan penghapusan data\n");
        printf("atau tekan angka selain (1) untuk membatalkan penghapusan data\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            deletePesertaKuliah(dataPesertaKuliah, dataSettings, deletePosition);
            operationCancelled = 0;
        }
        else {
            operationCancelled = 1;
        }

        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                           Hapus Data Peserta Kuliah                                        |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        if (operationCancelled) {
            printf("Anda telah membatalkan penghapusan data peserta kuliah\n");
        }
        else {
            printf("Berikut adalah rincian data peserta kuliah yang telah berhasil Anda hapus:\n");
            printf("Kode Mata Kuliah        : %s\n", bufferKode);
            printf("NIP Dosen Pengampu      : %s\n", bufferNIP);
            printf("NRP Peserta Kuliah      : %s\n", bufferNRP);
            setColor(COLOR_RED);
            printf("OPERASI PENGHAPUSAN DATA YANG TELAH DILAKUKAN TIDAK DAPAT DIBATALKAN\n\n");
            setColor(COLOR_DEFAULT);
        }

        printf("Silakan tekan (1) untuk melakukan penghapusan data lagi\n");
        printf("atau tekan angka selain (1) untuk kembali ke menu utama\n");
        printf("Pilihan Anda: ");
        scanf("%d", &operation);

        if (operation == 1) {
            continue;
        }
        else {
            break;
        }
    }

    return PROCCESS_SUCCESS;
}


int sceneInformasiData(DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                               Informasi Data                                               |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);
        
        printf("Jumlah Dosen                : %d\n", dataSettings->structSize_Dosen);
        printf("Jumlah Mahasiswa            : %d\n", dataSettings->structSize_Mahasiswa);
        printf("Jumlah Mata Kuliah          : %d\n", dataSettings->structSize_Matkul);
        printf("Jumlah Peserta Kuliah       : %d\n\n", dataSettings->structSize_PesertaKuliah);

        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }
    
    return PROCCESS_SUCCESS;
}

int sceneSimpanPaksaData(DataSettings *dataSettings) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                            Simpan Paksa Data                                               |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        printf("Data telah berhasil disimpan secara paksa. Berikut adalah jumlah data tersimpan saat ini:\n");
        
        printf("Jumlah Dosen                : %d\n", dataSettings->structSize_Dosen);
        printf("Jumlah Mahasiswa            : %d\n", dataSettings->structSize_Mahasiswa);
        printf("Jumlah Mata Kuliah          : %d\n", dataSettings->structSize_Matkul);
        printf("Jumlah Peserta Kuliah       : %d\n\n", dataSettings->structSize_PesertaKuliah);

        printf("Silakan tekan 1 untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }
    
    return PROCCESS_SUCCESS;
}

int sceneAppInfo(void) {
    int operation = 0;
    while (operation != 1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                             Informasi Aplikasi                                             |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        printf("Aplikasi Sistem Informasi Akademik\n");
        printf("Author : Keanu F. Taufan (5025221042)\n");
        printf("Repo   : https://github.com/keanutaufan/dasprog-siakademik/ \n");
        printf("Versi  : 1.0.0\n\n");

        printf("Program sederhana ini dibuat sebagai proyek akhir sekaligus syarat kelulusan\n");
        printf("mata kuliah Dasar Pemrograman (IF184101) Institut Teknologi Sepuluh Nopember\n");
        printf("dengan dosen Bpk. Dwi Sunaryono, S.Kom., M.Kom. pada tahun ajaran 2022/2023.\n\n");

        printf("Beberapa key features dalam program sederhana ini:\n");
        printf("- Penyimpanan dengan array of struct yang bersifat dinamis\n");
        printf("- Data yang diinput dan dihapus dapat melakukan self sorting\n");
        printf("- Data berupa representasi biner array of struct tersimpan dalam database lokal\n");
        printf("- Belasan menu dengan UI yang sederhana\n");
        printf("- dan lainnya...\n\n");

        printf("Kode sumber program ini didistribusikan dengan lisensi MIT.\n");
        printf("Anda dapat menggunakan dan memodifikasi sebgaian maupun keseluruhan program\n");
        printf("untuk kepentingan apapun dengan atribusi (lihat file LICENSE pada repositori).\n");
        printf("Jika anda menggunakan kode sumber untuk kepentingan penyelesaian tugas,\n");
        printf("harap perhatikan ketentuan tugas mengenai penggunaan kode sumber eksternal.\n\n");

        printf("Tekan (1) untuk kembali ke menu awal: ");
        scanf("%d", &operation);
    }

    return PROCCESS_SUCCESS; 
}

int sceneExitApp(void) {
    int operation = 0, invalidSelection = 0;
    while (1) {
        clearScreen();
        setColor(COLOR_CYAN);
        printf("==============================================================================================================\n");
        printf("|                                               Keluar Aplikasi                                              |\n");
        printf("==============================================================================================================\n\n");
        setColor(COLOR_DEFAULT);

        printf("Yakin ingin keluar aplikasi?\n");

        if (invalidSelection) {
            setColor(COLOR_RED);
            printf("MOHON HANYA MEMASUKKAN ANGKA YANG VALID!\n");
            setColor(COLOR_DEFAULT);
            invalidSelection = 0;
        }

        printf("Tekan (1) untuk keluar atau (0) untuk batal: ");
        scanf("%d", &operation);
        if (operation == 1) {
            return PROCCESS_SUCCESS;
        }
        else if (operation == 0) {
            return PROCCESS_CANCELLED;
        }
        else {
            invalidSelection = 1;
        }
    }

    return PROCCESS_CANCELLED;
}