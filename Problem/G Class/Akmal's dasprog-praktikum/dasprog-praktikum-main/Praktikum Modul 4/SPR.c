#include <stdio.h>
#include <string.h>
 
typedef struct list
{
	char type[101];
    char name[101];
    int val;
    struct list *ptr;
}list;
 
int main()
{
    int n, value;
    int len = 0;
    char cmd[101], s[101], p[101];
 
    scanf("%d", &n);
    
	list arr[n + 1];
    
	while(n--)
	{
        scanf("%s", cmd);
        
        if(strcmp(cmd, "init") == 0) 
		{
            scanf("%s", s);
            
            if(strcmp(s, "*") == 0)
			{
                scanf("%s &%s", s, p);
                
                int i;
                for(i = 0; i < len; i++)
				{
                    if(strcmp(arr[i].type, "var") == 0 && strcmp(arr[i].name, p) == 0)
					{
                        arr[len].ptr = &arr[i];
                    }
                }
                
                strcpy(arr[len].name, s);
                strcpy(arr[len].type, "ptr");
                len++;
            }
            else
			{
                scanf("%d", &value);
                strcpy(arr[len].name, s);
                strcpy(arr[len].type, "var");
                arr[len].val = value;
                len++;
            }
        }
 
        if(strcmp(cmd, "modify") == 0)
		{
            scanf("%s", s);
            
            if(strcmp(s, "*") != 0) 
			{
				int i;
                for(i = 0; i < len; i++) 
				{
                    if(strcmp(arr[i].name, s) == 0) 
					{
                        if(strcmp(arr[i].type, "var") == 0) 
						{
                            scanf("%d", &value);
                            
                            arr[i].val = value;
                            break;
                        }
                        else 
						{
                            scanf(" &%s", p);
                            
							int j;
                            for (j = 0; j < len; j++) 
							{
                                if(strcmp(arr[j].type, "var") == 0 && strcmp(arr[j].name, p) == 0)
								{
                                    break;
                                }
                            }
                            
                            arr[i].ptr = &arr[j];
                            break;
                        }
                    }
                }
            }
            else 
			{
                scanf("%s %d", s, &value);
                
				int i;
                for(i = 0; i < len; i++) {
                    if(strcmp(arr[i].type, "ptr") == 0 && strcmp(arr[i].name, s) == 0) 
					{
                        (arr[i].ptr)->val = value;
                    } 
                }
            }
        }
 
        if(strcmp(cmd, "print") == 0) 
		{
            scanf("%s", s);
            
            int i;
            for(i = 0; i < len; i++)
			{
                if(strcmp(arr[i].type, "var") == 0 && strcmp(arr[i].name, s) == 0)
				{
                    printf("%d\n", arr[i].val);
                    break;
                }
            }
        }
    }
 
    return 0;
}
