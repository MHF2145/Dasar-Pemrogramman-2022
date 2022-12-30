#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[55], telfon[55];
	int umur, temen, bestie;
}info;

typedef struct{
	int populasi;
	info penduduk[15];
}diminta;

int main(){
	int kondisi[100][100];
	char tempat[55][55],aku[55],dia[55];
	memset(kondisi,0,sizeof(kondisi));
	int testcase,a,b;
	scanf("%d", &testcase);
	diminta list[testcase];	
	
	for(int i=0;i<testcase;i++){
		scanf("%s", tempat[i]);
		scanf("%d", &a);
		
		list[i].populasi = a;
		
		for(int j=0;j<a;j++){
			scanf("%s", list[i].penduduk[j].nama);
			scanf("%d", &list[i].penduduk[j].umur);
			scanf("%s", list[i].penduduk[j].telfon);
		}
	}
	
	scanf("%d", &b);
	
	for(int i=0;i<b;i++){
		scanf("%s %s", aku, dia);
		
		for(int j=0;j<testcase;j++){
			for(int k=0;k<list[j].populasi;k++){
				if(strcmp(list[j].penduduk[k].nama,aku) == 0){
					for(int l=0;l<testcase;l++){
						for(int m=0;m<list[l].populasi;m++){
							if(strcmp(list[l].penduduk[m].nama,dia) == 0){
								kondisi[j][k] = 1;
								list[j].penduduk[k].temen = l;
								list[j].penduduk[k].bestie = m;
								break;
							}
						}
					}
				}
			}
		}
	}
	
	for(int i=0;i<testcase;i++){
		printf("%s\n", tempat[i]);
		
		for(int j=0;j<list[i].populasi;j++){
			printf("Name: %s\n", list[i].penduduk[j].nama);
			printf("Age: %d\n", list[i].penduduk[j].umur);
			printf("Phone Number:%s\n", list[i].penduduk[j].telfon);
			
			if(kondisi[i][j] == 1){
				printf("His/Her bestie is: %s\n", list[list[i].penduduk[j].temen].penduduk[list[i].penduduk[j].bestie].nama);
				printf("His/Her contact info is as follows\n");
				printf("Name: %s\n", list[list[i].penduduk[j].temen].penduduk[list[i].penduduk[j].bestie].nama);
				printf("Age: %d\n", list[list[i].penduduk[j].temen].penduduk[list[i].penduduk[j].bestie].umur);
				printf("Phone Number:%s\n", list[list[i].penduduk[j].temen].penduduk[list[i].penduduk[j].bestie].telfon);
			}
			else printf("His/Her bestie is: No one\n");
			printf("\n");
		}
	}		
}	

