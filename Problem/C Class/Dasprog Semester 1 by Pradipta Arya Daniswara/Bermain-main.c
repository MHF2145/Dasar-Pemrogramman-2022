#include <stdio.h>
#include <string.h>

int main()
{
	char input[100000];
	scanf("%s", &input);
	int panjang = strlen(input);
    int counter = 0;
    int hasil = 0;
    
    int kiri;
    int kanan;
    while(input[counter] != '\0') 
	{
		int i;
		for(i = 0; i <= 1; i++)
		{
			kiri = counter;
	        kanan = counter + i;
	        while(kiri >= 0 && kanan < panjang && input[kiri] == input[kanan])
			{
	            kiri--;
	            kanan++;
	            hasil++;
	        }
		}
        counter++;
    }
    printf("%d\n", hasil);
}
