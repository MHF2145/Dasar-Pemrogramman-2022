#include<stdio.h>
#include<stdbool.h>

typedef struct list
{
	char l[10001];
	char ip[10001];
	bool k;
}list;

int main()
{
	long long n, m, i, j;
	
	scanf("%lld %lld", &n, &m);
	
	list arr[n + 1];
	
	for(i = 0; i < n; i++)
	{
		scanf("%s %s", arr[i].l, arr[i].ip);
	}
	
	char cari[10001];
	
	while(m--)
	{
		scanf("%s", cari);
		
		bool ketemu = false;
		
		for(i = 0; i < n; i++)
		{
			if(strcmp(cari, arr[i].l) == 0 && arr[i].k == false)
			{
				printf("%s Berhasil Di Blokir.\n", arr[i].ip);
				ketemu = true;
				arr[i].k = true;
			}
		}
		
		if(ketemu == false)
		{
			printf("Alamat Tidak Ditemukan...\n");
		}
	}
	
	return 0;
}

