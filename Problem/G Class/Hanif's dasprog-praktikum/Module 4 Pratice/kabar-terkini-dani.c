#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct data
{
	char website[1000];
    char address[1000];
}
data;

int main()
{
	int m, i;
    int n;
	char cari[100];
	
	scanf("%d", &m);
    scanf("%d", &n);
	
	data laman[m + 1];

    for(i = 0; i < m; i++)
        {
            scanf("%s %s", laman[i].website, laman[i].address);
        }
		
    while(n--)
    {
        scanf("%s", cari);
		bool ketemu = false;
        
		
		for(i = 0; i < m; i++){	
			if(strcmp(cari, laman[i].website) == 0){
				printf("%s Berhasil Di Blokir.\n", laman[i].address);
				ketemu = true;
			}
		}
		if(ketemu == false){
			printf("Alamat tidak ditemukan...\n", cari);	
		}	
	}
	return 0;
}