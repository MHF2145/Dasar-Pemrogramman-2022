#include <stdio.h>
	int Fibonacci(int N);	/*prototype fungsi*/

main()
{
	int N;

		printf("Suku bilangan ke ? "); scanf("%d", &N);
			printf("Nilai suku ke %d adalah %d\n", N, 	Fibonacci(N));
			}

			/*-----Fungsi deret Fibonacci secara rekursi----*/
				int Fibonacci(int N)	/*definisi fungsi*/

				{
					if(N<2) return(N);
						else
							return(Fibonacci(N-2)+Fibonacci(N-1));
							}
