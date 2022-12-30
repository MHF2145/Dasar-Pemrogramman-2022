#include <stdio.h>
#include <string.h>

struct info1
{
    char nama[50];
    char telp[50];
    int umur;
    int temen1;
    int temen2; 
};

struct info2
{
    int banyakorang;
    struct info1 datapenduduk[10];
};

int main(){
    int condition[100][100];
    char namatempat[50][50], orang[50], temenorang[50];

    memset(condition, 0, sizeof(condition));

    int m, n;
    scanf("%d", &n);
    struct info2 data[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", namatempat[i]);
        scanf("%d", &m);

        data[i].banyakorang = m;

        for (int j = 0; j < m; j++)
        {
            scanf("%s %d %s", data[i].datapenduduk[j].nama, &data[i].datapenduduk[j].umur, data[i].datapenduduk[j].telp);
        }   
    }
    
    int o;
    scanf("%d", &o);

    for (int i = 0; i < o; i++)
    {
        scanf("%s %s", orang, temenorang);

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < data[j].banyakorang; k++)
            {
                if (strcmp(data[j].datapenduduk[k].nama, orang) == 0)
                {
                    for (int l = 0; l < n; l++)
                    {
                        for (int p = 0; p < data[l].banyakorang; p++)
                        {
                            if (strcmp(data[l].datapenduduk[p].nama, orang) == 0)
                            {
                                condition[j][k] = 1;
                                data[j].datapenduduk[k].temen1 = l;
                                data[j].datapenduduk[k].temen2 = p;
                                break;
                            }
                        }
                      
                    }
                    
                }
                
            }
            
        }
        
    }
    
    for(int i = 0; i < m ; i++){
		printf("%s\n", namatempat[i]);
		
		for(int j = 0;j < data[i].banyakorang; j++){
			printf("Name: %s\n", data[i].datapenduduk[j].nama);
			printf("Age: %d\n", data[i].datapenduduk[j].umur);
			printf("Phone Number:%s\n", data[i].datapenduduk[j].telp);
			
			if(condition[i][j] == 1){
				printf("His/Her bestie is: %s\n", data[data[i].datapenduduk[j].temen1].datapenduduk[data[i].datapenduduk[j].temen2].nama);
				printf("His/Her contact info is as follows\n");
				printf("Name: %s\n", data[data[i].datapenduduk[j].temen1].datapenduduk[data[i].datapenduduk[j].temen2].nama);
				printf("Age: %d\n", data[data[i].datapenduduk[j].temen1].datapenduduk[data[i].datapenduduk[j].temen2].umur);
				printf("Phone Number:%s\n", data[data[i].datapenduduk[j].temen1].datapenduduk[data[i].datapenduduk[j].temen2].telp);
			}
			else printf("His/Her bestie is: No one\n");
			printf("\n");
		}
	}
    
}