#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    // Your code goes here
	char huruf[1000007]; //sesuai constraint tapi dilebihkan dikit
    scanf("%s", huruf);

    char ngurang[1000007]; //sesuai constraint tapi dilebihkan dikit
    ngurang[0] = huruf[0]; //array buat nampung huruf yang gak sama

	int index = 0; 
	long long int kerugian = 0; // ya karena 100000*122*2000 > 2 milyaran (max int)
    long long int i; 	
	 
	int panjang = strlen(huruf);
    int panjang2; 
	
	for (i=1; i<panjang; i++){
		if (ngurang [index] == huruf [i])
        {
			kerugian += 2000 * ngurang [index]; //dikalikan 2000 karena 2 batu yang hilang
			index--; //buat ngecek case seperti "yxxy"
		}
		else 
        {
			index++; // buat array di bawah
			ngurang [index] = huruf [i]; // mencatat huruf yang (awalnya) gak sama	
		}
	}
	
	panjang2 = index + 1;
	
	if (index + 1 == panjang)
    {
		printf("Di gudang tersisa %d batu\nWah, Jotaro Joemama tidak jadi dipecat", panjang2); 
	}
	else 
    {
		printf("Di gudang tersisa %d batu\nTotal Kerugian: %lld Dolar Imbu", panjang2, kerugian);
	}

    return 0;
}
