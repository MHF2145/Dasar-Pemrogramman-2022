#include <stdio.h>
int Fibonacci(int N);	/*prototype fungsi*/

main()
{
	int N;
		printf("Suku bilangin ke ? "); scanf("%d",&N);
			printf("Nilai suku ke %d adalah %d\n", N, 	Fibonacci(N));
			}

			/*----- Fungsi deret Fibonacci tidak secara rekursi -----*/
			int Fibonacci(int N)	/*definisi fungsi*/
			{
				int Fibo_Bawah, Fibo_Atas, X, I;

					if(N<2) return(N);

						Fibo_Bawah			= 0;
							Fibo_Atas		= 1;
								for(I=2; I<=N; I++)
								{
							X		= Fibo_Bawah;
					Fibo_Bawah	= Fibo_Atas;
					Fibo_Atas	= X + Fibo_Bawah;
				}
				return(Fibo_Atas);
			}
