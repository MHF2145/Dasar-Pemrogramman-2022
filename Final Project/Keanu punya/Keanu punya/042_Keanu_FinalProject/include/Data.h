#ifndef _DATA_H
#define _DATA_H

#define SCORE_EMPTY -1
#define AVG_EMPTY -1.0

#define NOT_FOUND -1

/// @brief Keep tracks of user settings and length of custom data types
typedef struct {
    int structSize_Dosen;           // Holds current array length of Dosen*
    int structSize_Mahasiswa;       // Holds current array length of Mahasiswa*
    int structSize_Matkul;          // Holds current array length of Matkul*
    int structSize_PesertaKuliah;   // Holds current array length of PesertaKuliah*
} DataSettings;

/// @brief Lecturer's identity
typedef struct {
    char NIP[20];                   // Lecturer's NIP (ID)
    char nama[50];                  // Lecturer's name
} Dosen;

/// @brief Student's identity
typedef struct {
    char NRP[20];                   // Student's NRP (ID)
    char nama[50];                  // Student's name
    char alamat[50];                // Student's address
} Mahasiswa;

/// @brief Course details
typedef struct {
    char kode[10];                  // Course code
    char nama[30];                  // Course name
    int sks;                        // Course credit
} Matkul;

/// @brief Course takers and lecturers
typedef struct {
    Matkul *matkul;                 // Pointer to course taken
    Dosen *dosen;                   // Pointer to lecturer giving the course
    Mahasiswa *peserta;             // Pointer to student taking the course
    int uts;                        // Midterm exam score (0-100)
    int uas;                        // Term exam score (0-100)
    float rerata;                   // Average score (0-100)
    char grade[3];                  // Final grade (A, AB, B, BC, C, D, E)
    char key_kode[20];              // Course code of the course taken (course codes are always guaranteed unique)
    char key_NIP[20];               // NIP of lecturer giving the course (NIPs are always guaranteed unique)
    char key_NRP[20];               // NRP of student taking the course (NRPs are always guaranteed unique)
} PesertaKuliah;

void *initializeEmptyData(void);

char *scoreToGrade(float score);

// Functions related to data input
int inputDosen(Dosen **dataDosen, DataSettings *dataSettings, const char *NIP, const char *nama);
int inputMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings, const char *NRP, const char *nama, const char *alamat);
int inputMatkul(Matkul **dataMatkul, DataSettings *dataSettings, const char *kode, const char *nama, int sks);
int inputPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta);
int inputNilai(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, int insertPosition, int uts, int uas);

// Functions related to data search
int searchDosen(Dosen *dataDosen, DataSettings *dataSettings, const char *NIP);
int searchMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings, const char *NRP);
int searchMatkul(Matkul *dataMatkul, DataSettings *dataSettings, const char *kode);
int searchPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, const char *kode, const char *NIP, const char *NRP);

int deleteDosen(Dosen **dataDosen, DataSettings *dataSettings, int deletePosition);
int deleteMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings, int deletePosition);
int deleteMatkul(Matkul **dataMatkul, DataSettings *dataSettings, int deletePosition);
int deletePesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, int deletePosition);

int readjustPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);
int forceReadjustPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);


#endif