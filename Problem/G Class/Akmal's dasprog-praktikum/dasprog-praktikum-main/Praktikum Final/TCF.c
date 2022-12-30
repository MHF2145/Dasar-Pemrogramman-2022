#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

bool ada[101][101];
char area[101][101];
int t;

typedef struct
{
    char area[101], name[101], num[101];
    int age, best1, best2;
}gay1;

typedef struct
{
    gay1 people[101];
    int sop;
}gay2;

typedef struct
{
    gay2 asal[101];
    char area[101];
}gay3;

int main()
{
	memset(ada, false, sizeof(ada));
    
	scanf("%d", &t);
    
	gay3 data;
	
	int  i, j;
	for (i = 0; i < t; i++)
	{
		int n;
        
		scanf("%s %d", area[i], &n);
        
		data.asal[i].sop = n;
        
        for (j = 0; j < n; j++)
		{
            strcpy(data.asal[i].people[j].area, area[i]);
            scanf("%s %d %s", data.asal[i].people[j].name, &data.asal[i].people[j].age, data.asal[i].people[j].num);
        }
    }

    int search; 
    
    scanf("%d", &search);
    
	int k, l, m;
    for(i = 0; i < search; i++)
	{
        char a[101], b[101];
        
        scanf("%s %s", a, b);
        
        for(j = 0; j < t; j++)
		{
            for(k = 0; k < data.asal[j].sop; k++)
			{
                if(!strcmp(a, data.asal[j].people[k].name))
				{
                    int p = 1;
                    for(l = 0; l < t && p == 1; l++)
					{
                        for(m = 0; m < data.asal[l].sop && p == 1; m++)
						{   
                            if (!strcmp(b, data.asal[l].people[m].name))
							{
                                data.asal[j].people[k].best1 = l;
                                data.asal[j].people[k].best2 = m;
                                ada[j][k] = true;
                                break;
                                p = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < t; i++)
	{
        printf("%s\n", area[i]);
        
        for(j = 0; j < data.asal[i].sop; j++)
		{
            printf("name: %s\nAge: %d\nPhone Number:%s\n", data.asal[i].people[j].name, data.asal[i].people[j].age, data.asal[i].people[j].num);
            
            if(ada[i][j])
			{
                printf("His/Her bestie is: %s\nHis/Her contact info is as follows\nname: %s\nAge: %d\nPhone Number:%s\n", data.asal[data.asal[i].people[j].best1].people[data.asal[i].people[j].best2].name, data.asal[data.asal[i].people[j].best1].people[data.asal[i].people[j].best2].name, data.asal[data.asal[i].people[j].best1].people[data.asal[i].people[j].best2].age, data.asal[data.asal[i].people[j].best1].people[data.asal[i].people[j].best2].num);
            }
            else
			{
                printf("His/Her bestie is: No one\n");
            }
            printf("\n");
        }
    }
    
    return 0;
}
