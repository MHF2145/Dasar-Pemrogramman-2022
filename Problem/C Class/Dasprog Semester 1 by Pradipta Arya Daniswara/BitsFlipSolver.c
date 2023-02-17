#include <stdio.h>
#include <string.h>

char bits[32];

void basis(int diff, int counter)
{
    char hasil;
    int bagi = diff % 2;
    
    if (diff == 0)
    {
        return;
    }
    else
    {
        hasil = '0' + bagi;
    }
    diff = diff / 2;
    
    bits[counter] = hasil;
    basis(diff, counter + 1);
}

int main()
{
	int testcase;
	scanf("%d", &testcase);
	int awal;
	scanf("%d", &awal);
	
	int i;
	for(i = 1; i <= testcase; i++)
	{
		memset(bits, '0', sizeof(bits));
		
		int bitflip;
		scanf("%d", &bitflip);
		int tujuan;
		scanf("%d", &tujuan);
		
        if (bitflip > 0)
        {
            awal = awal ^ 1 << bitflip - 1;
        }
        basis(awal ^ tujuan, 0);
        
        char temp = '0';
        int total = 0;
        int j;
        for(j = 0; j < strlen(bits); j++)
        {
            if(bits[j] == '1' && bits[j] != temp)
            {
                total++;
            }
            temp = bits[j];
        }
        awal = tujuan;
        
        printf("%d\n", total);
	}
}
