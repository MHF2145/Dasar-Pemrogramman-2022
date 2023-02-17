#include <stdio.h>

char kotak[1001][1001];
int cek[1001][1001];
int x;
int y;
int max = 0;
int panjang = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void cari_panjang(int a, int b, int baris, int kolom)
{
	cek[a][b] = 1;
	panjang++;
	
	if(panjang > max)
	{
		x = a;
		y = b;
		max = panjang;
	}
	
	int i;
	for(i = 0; i < 4; i++)
	{
		int cekx = a + dx[i];
        int ceky = b + dy[i];
        
        if(cekx < 0 || ceky < 0 || cekx >= kolom || ceky >= baris || kotak[cekx][ceky] == '#' || cek[cekx][ceky])
		{
			continue;
		} 
        
        cari_panjang(cekx, ceky, baris, kolom);
	}
	
	cek[a][b] = 0;
    panjang--;
}

int main()
{
	int testcase;
	scanf("%d", &testcase);
	
	int a;
	for(a = 1; a <= testcase; a++)
	{
		int baris;
		scanf("%d", &baris);
		int kolom;
		scanf("%d", &kolom);
		
		int k;
		for(k = 0; k < kolom; k++)
		{
			scanf("%s", kotak[k]);
		}
		
		int i;
		for(i = 0; i < kolom; i++)
		{
			int j;
			for(j = 0; j < baris; j++)
			{
				if(kotak[i][j] != '#')
				{
					cari_panjang(i, j, baris, kolom);
					i = kolom;
					break;
				}
			}	
		}
        
		cari_panjang(x, y, baris, kolom);
        
		printf("Panjang tali adalah %d.\n", max - 1);
	}
}
