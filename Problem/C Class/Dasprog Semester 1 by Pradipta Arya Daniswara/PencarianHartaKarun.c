#include <stdio.h>

int main()
{
    int input;
    scanf("%d", &input);
    int limit_kiri = 1;
    int limit_kanan = input;
	int limit_bawah = 1;
	int limit_atas = input;
    
    while(1)
    {
    	if (limit_kiri < limit_kanan && limit_bawah < limit_atas)
	    {
	        int tengah_kk = (limit_kiri + limit_kanan) / 2;
			int tengah_ab = (limit_bawah + limit_atas) / 2;
			
	        printf("LIHAT %lld %lld\n", tengah_kk, tengah_ab);
	        fflush(stdout);
	        
	        int arah;
	        scanf("%d", &arah);
	        
	        if (arah == 1) //barat laut
	        {
	        	limit_kanan = tengah_kk;
	        	limit_bawah = tengah_ab;
	        }
	        if (arah == 2) //utara
	        {
	        	limit_bawah = tengah_ab;
	        }
	        if (arah == 3) //timur laut
	        {
	        	limit_kiri = tengah_kk;
	        	limit_bawah = tengah_ab;
	        }
	        if (arah == 4) //barat
	        {
	        	limit_kanan = tengah_kk;
	        }
	        if (arah == 5) //dah ketemu
	        {
	            printf("KOORDINAT %d %d", tengah_kk, tengah_ab);
	            fflush(stdout);
	            break;
	        }
	        if (arah == 6) //timur
	        {
	        	limit_kiri = tengah_kk;
	        }
	        if (arah == 7) //barat daya
	        {
	        	limit_kanan = tengah_kk;
	        	limit_atas = tengah_ab;
	        }
	        if (arah == 8) //selatan
	        {
	        	limit_atas = tengah_ab;
	        }
	        if (arah == 9) //barat laut
	        {
	        	limit_kiri = tengah_kk;
	        	limit_atas = tengah_ab;
	        }
	    }
	}
}
