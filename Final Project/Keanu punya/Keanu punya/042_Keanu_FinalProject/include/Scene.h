#include "Data.h"

int sceneLihatDataDosen(Dosen *dataDosen, DataSettings *dataSettings);
int sceneLihatDataMahasiswa(Mahasiswa *dataMahasiswa, DataSettings *dataSettings);
int sceneLihatDataMatkul(Matkul *dataMatkul, DataSettings *dataSettings);
int sceneLihatDataPesertaKuliah(PesertaKuliah *dataPesertaKuliah, DataSettings *dataSettings, Matkul *dataMatkul, Dosen *dataDosen, Mahasiswa *dataPeserta);

int sceneInputDataDosen(Dosen **dataDosen, DataSettings *dataSettings);
int sceneInputDataMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings);
int sceneInputDataMatkul(Matkul **dataMatkul, DataSettings *dataSettings);
int sceneInputDataPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta);
int sceneInputNilaiPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta);

int sceneDeleteDataDosen(Dosen **dataDosen, DataSettings *dataSettings);
int sceneDeleteDataMahasiswa(Mahasiswa **dataMahasiswa, DataSettings *dataSettings);
int sceneDeleteDataMatkul(Matkul **dataMatkul, DataSettings *dataSettings);
int sceneDeleteDataPesertaKuliah(PesertaKuliah **dataPesertaKuliah, DataSettings *dataSettings, Matkul *matkul, Dosen *dosen, Mahasiswa *peserta);

int sceneInformasiData(DataSettings *dataSettings);
int sceneSimpanPaksaData(DataSettings *dataSettings);
int sceneAppInfo(void);
int sceneExitApp(void);