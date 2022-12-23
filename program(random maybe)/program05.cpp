#include <stdio.h>
void Masukkan_Data(float X[],int Jumlah); /*prototype fungsi*/
void Quick_Sort(float X[], int Atas, int Bawah); /*prototype fungsi*/
void Tampilkan_Data(float X[], int Jumlah); /*prototype fungsi*/
main()
{
	int N;
	float Nilai[1000];

	printf("Jumlah data ? "); scanf("%d", &N);
	printf("\n");

	Masukkan_Data(Nilai, N);	/*menggunakan fungsi 	memasukkan data*/
	Quick_Sort(Nilai, 0, N-1);	/*menggunakan fungsi 	mengurutkan data*/

	printf("\n");
	printf("Hasil setelah urut:\n");
	Tampilkan_Data(Nilai, N);	/*Menggunakan fungsi 	menampilkan data*/
}

/*----- Fungsi memasukkan data larik -----*/
void Masukkan_Data(float X[], int Jumlah)	/*definisi fungsi*/
{
	int I;
	for(I=0; I<Jumlah; I++) {
		printf("Data ke %d ? ", I+1);
		scanf("%f", &X[I]);}
}

/*----Fungsi mengurutkan data elemen-elemen larik----*/
void Quick_Sort(float X[], int Bawah, int Atas)
/*definisi fungsi*/

{
int I, J, K;
float Sementara;

while(Atas > Bawah){
	I=Bawah;
	J=Atas;
	Sementara=X[Bawah];

	/*memecah larik menjadi 2 bagian*/
	while(I<J){
		while(X[J] > Sementara)--J;
		X[I] = X[J];
		while(I<J && X[I] <= Sementara) ++I;
		X[J]=X[I];}

	X[I] = Sementara;

	/*urutkan rekursi*/
	Quick_Sort(X, Bawah, I-1);
	Bawah = I + 1;
	}
}

/*-----Fungsi menampilkan data elemen-elemen larik-----*/
void Tampilkan_Data(float X[], int Jumlah)	/*definisi fungsi*/
{
	int I;

	for(I=0; I<Jumlah; I++) printf("%f\n", X[I]);
}

