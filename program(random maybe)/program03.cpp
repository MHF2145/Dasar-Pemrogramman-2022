#include <stdio.h>
long int Fak_Rekursi(int N);	/*prototype fungsi*/
main()
{
	int N;
		N=5;
			printf("%d faktorial = %ld \n", N, Fak_Rekursi(N));
			}
			/*----- Fungsi rekursi menghitung N faktorial -----*/
			long int Fak_Rekursi(int N) 	/*definisi fungsi*/
			{
				long int F;
					if(N<=1) return(1);
						else {
							F = N * Fak_Rekursi(N-1);
								return(F);
									}
									}

