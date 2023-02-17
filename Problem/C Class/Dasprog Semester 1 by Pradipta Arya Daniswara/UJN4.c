#include <stdio.h>
#include <string.h>

struct rekening {
    int id;
    char nama[100];
    int saldo;
};

int main()
{
	int n;
	scanf("%d", &n);
	struct rekening arr[n + 1];
	
	int i;
	for (i = 1; i <= n; i++)
	{
		int id;
		scanf("%d", &id);
		char nama[100];
		scanf("%s", &nama);
		int saldo;
		scanf("%d", &saldo);
		
		arr[i].id = id;
		strcpy(arr[i].nama, nama);
		arr[i].saldo = saldo;
	}
	
	int x;
	scanf("%d", &x);
	
	int j;
	for(j = 1; j <= x; j++)
	{
		char nama[100];
		scanf("%s", &nama);
		int id_perintah;
		scanf("%d", &id_perintah);
		int check = 0;
		
		int k;
		for(k = 1; k <= n; k++)
		{
			if(strcmp(arr[k].nama, nama) == 0)
			{
				check = 1;
				break;
			}
		}
		
		if(id_perintah == 1)
		{
			if(check == 1)
			{
				printf("Saldo %s dengan id %d adalah $%d\n", arr[k].nama, arr[k].id, arr[k].saldo);
			}
			else
			{
				printf("Rekening %s tidak ditemukan!\n", nama);
			}
		}
		
		if(id_perintah == 2)
		{
			int saldo_baru;
			scanf("%d", &saldo_baru);
			if(check == 1)
			{
				arr[k].saldo = saldo_baru;
				printf("Saldo %s dengan id %d diubah menjadi $%d\n", arr[k].nama, arr[k].id, arr[k].saldo);
			}
			else
			{
				printf("Rekening %s tidak ditemukan!\n", nama);
			}
		}
	}
}
