#include <stdio.h>
#include <string.h>

struct hadiah {
    char nama[100];
    char ukuran[100];
    int jumlah;
};

int main()
{
	int n;
	scanf("%d", &n);
	struct hadiah arr[n + 1];
	
	int i;
	for (i = 1; i <= n; i++)
	{
		char nama[100];
		scanf("%s", &nama);
		char ukuran[100];
		scanf("%s", &ukuran);
		int jumlah;
		scanf("%d", &jumlah);
		
		strcpy(arr[i].nama, nama);
		strcpy(arr[i].ukuran, ukuran);
		arr[i].jumlah = jumlah;
	}
	
	char nama[100];
	scanf("%s", &nama);
	char ukuran[100];
	scanf("%s", &ukuran);
	int jumlah;
	scanf("%d", &jumlah);
	
	int k;
	for(k = 1; k <= n; k++)
	{	
		if(strcmp(arr[k].nama, nama) == 0 && strcmp(arr[k].ukuran, ukuran) == 0 && arr[k].jumlah >= jumlah)
		{
			printf("Oleh-olehnya ada yaa\n");
			break;
		}
		
		if(k == n)
		{
			printf("Hah? Kamu nanya???\n");
		}
	}
}
