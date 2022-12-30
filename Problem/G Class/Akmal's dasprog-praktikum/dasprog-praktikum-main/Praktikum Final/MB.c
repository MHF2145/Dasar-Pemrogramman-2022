#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct gay
{
    char l[101], p[101];
    int val;
	char adr[101];
}gay;

int scan(gay *arr, int n, char *str, int flag)
{
    for (int i = 0; i < n; i++)
	{
        if (strcmp(str, arr[i].p) == 0)
		{
            return scan(arr, n, arr[i].adr, flag);
        } 
		if(strcmp(str, arr[i].l) == 0 && flag == 0)
		{
            return arr[i].val;
        } 
		if(strcmp(str, arr[i].l) == 0)
		{
            arr[i].val = flag;
            return arr[i].val;
        }
    }
    
    return -1;
}

int main(){
    int n;
    char cmd[101];
	                       
    scanf("%d", &n);
    
    gay arr[n + 1];

    for (int i = 0; i < n; i++)
	{          
        scanf("%s", cmd);
        
        char s[101];
        int flag = 0;

        if (strcmp(cmd, "set") == 0)
		{         
            scanf("%s", s);
            
            if (strcmp(s, "*") == 0)
			{
                char a[101];
                
                scanf("%s", a); 
                strcpy(arr[i].p, a);
                scanf(" & %s", arr[i].adr);
            }
            else 
			{
                strcpy(arr[i].l, s);
                scanf("%d", &arr[i].val);
            }
        }
        if(strcmp(cmd, "chg") == 0)
		{ 
            scanf("%s", s);

            if (strcmp(s, "*") == 0)
			{                
                char b[101], c[101];
                
                scanf("%s", b);
                
                for(int i = 0; i < n; i++)
				{
                    if(strcmp(b, arr[i].p) == 0)
					{                      
                        scanf("%s", c);
                        
                        if(strcmp(c, "&") == 0)
						{
							scanf("%s", arr[i].adr);
						}
                        else 
						{
                            scan(arr, n, arr[i].adr, atoi(c));
                       	}
                    }
                }
            }
            else{ 
                for(int i = 0; i < n; i++)
				{
                    if(strcmp(s, arr[i].p) == 0)
					{
                        scanf(" & %s", arr[i].adr);
                    } 
                    else if(strcmp(s, arr[i].l) == 0)
					{
                        scanf("%d", &arr[i].val);
                    } 
                }
            }
        }
        if(strcmp(cmd, "get") == 0)
		{ 
            scanf(" * %s", s);
            printf("%d\n", scan(arr, n, s, flag));
        }
    }
    
    return 0;
}
