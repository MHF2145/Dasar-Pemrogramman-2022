#include <stdio.h>
#include <string.h>

struct barang {
    int kode;
    char nama[100];
    int jumlah;
    int harga;
};

int main()
{
	int n;
	scanf("%d", &n);
	struct barang arr[n + 1];
	
	int i;
	for(i = 1; i <= n; i++)
	{
		int kode;
		scanf("%d", &kode);
		char nama[100];
		scanf("%s", &nama);
		int jumlah;
		scanf("%d", &jumlah);
		int harga;
		scanf("%d", &harga);
		
		arr[i].kode = kode;
		strcpy(arr[i].nama, nama);
		arr[i].jumlah = jumlah;
		arr[i].harga = harga;
	}
	
	int no_transaksi = 0;
	int x;
    while((x = getchar()) != EOF)
    {
    	scanf("%d", &x);
    	
    	char transaksi[10];
    	char temp[10];
    	no_transaksi++;
    	sprintf(temp, "%d", no_transaksi);
    	
    	if(no_transaksi < 10) 
		{
			strcpy(transaksi, "000");
			strcat(transaksi, temp);
		}
    	else if(no_transaksi < 100)
		{
			strcpy(transaksi, "00");
			strcat(transaksi, temp);
		}
    	else if(no_transaksi < 1000) 
		{
			strcpy(transaksi, "0");
			strcat(transaksi, temp);	
		}
    	else
		{
			strcpy(transaksi, temp);
		}
    	
    	printf("------------------------------------\n\n");
    	int termurah;
    	int termahal;
    	int pembayaran = 0;
    	int pass_harga = 0;
    	int j;
    	for(j = 1; j <= x; j++)
		{
			if(arr[j].jumlah > 0)
			{
				if(pass_harga == 0)
				{
					termurah = j;
					termahal = j;
					pass_harga = 1;
				}
				else
				{
					if(arr[j].harga < arr[termurah].harga)
					{
						termurah = j;
					}
					if(arr[j].harga > arr[termahal].harga)
					{
						termahal = j;
					}
				}
				
				arr[j].jumlah--;
				pembayaran = pembayaran + arr[j].harga;
			}
			else
			{
				printf("[ Info ] Barang %d %s tidak tersedia\n\n", arr[j].kode, arr[j].nama);
			}
		}
		
		if(pembayaran == 0)
		{
			printf("No. Transaksi    : %s\n", transaksi);
	    	printf("Total item       : %d\n", x);
	    	printf("Item termurah    : %d Tidak tersedia\n", arr[x].kode);
	    	printf("Item termahal    : %d Tidak tersedia\n", arr[x].kode);
	    	printf("Total pembayaran : %d\n\n", pembayaran);
		}
		else
		{
			printf("No. Transaksi    : %s\n", transaksi);
			printf("Total item       : %d\n", x);
			printf("Item termurah    : %d %s\n", arr[termurah].kode, arr[termurah].nama);
			printf("Item termahal    : %d %s\n", arr[termahal].kode, arr[termahal].nama);
			printf("Total pembayaran : %d\n\n", pembayaran);
		}
    }
    printf("------------------------------------\n");
}
