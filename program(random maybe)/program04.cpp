#include <stdio.h>
long int Fak_Rekursi(int N);  	/*prototype fungsi*/
main()
{
	int N;
		N=5;
			printf("%d faktorial = %ld \n", N, Fak_Rekursi(N));
			}
			/*----- Fungsi Rekursi menghitung N  faktorial -----*/
			long int Fak_Rekursi(int N)   	/*definisi fungsi*/
			{
				if(N<=1) return(1);
					else {
						return(N * Fak_Rekursi(N-1));
							}
							}


