#include <stdio.h>
void Berhenti_N_Kali(int N); 	/*prototype fungsi*/

main()
{
	int N;
		N=3;
		Berhenti_N_Kali(N);
		}
		/*----- Fungsi menampilkan hasil sebanyak N Kali -----*/
		void Berhenti_N_Kali(int N) 	/*definisi fungsi*/
		 {
			static int I=0;
				if(N<=0) return;
					printf ("%d kali\n", ++I);
						Berhenti_N_Kali(N-1);
						}
