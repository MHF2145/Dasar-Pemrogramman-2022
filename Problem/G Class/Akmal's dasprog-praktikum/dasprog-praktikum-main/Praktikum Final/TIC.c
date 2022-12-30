#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
typedef long long ll;

ll cash = 0;

typedef struct
{
    char name[101];
    int prc, stok;
    bool ada;
}list;

list arr[1000001];

void add(list arr[], int idx)
{
	int a, b;
    char s[101];
    
    scanf("\n%[^\n]%*c", s);
    scanf("%d %d", &b, &a);
    
    if(arr[idx].ada)
	{
        printf("Menu is already exist!\n");
    }
    else
	{
        strcpy(arr[idx].name, s);
        arr[idx].prc = b;
        arr[idx].stok = a;
		arr[idx].ada = true;
    }
    
    printf("Menu added\n");
}

void discount(list arr[], int idx, double disc)
{
    if(!arr[idx].ada)
	{
        printf("Menu does not exist\n");
    }
    else
	{
		arr[idx].prc -= ((arr[idx].prc * disc) / 100);
		
        printf("Discount added\n");
    }
}

void info(list data[], int idx)
{
    if(arr[idx].ada)
	{
        printf("#%d %s\nPrice : Rp%d\nStock : %dx\n\n", idx, arr[idx].name, arr[idx].prc, arr[idx].stok);
    }
    else if(arr[idx].ada == false)
	{
        printf("Menu does not exist\n");
    }
}

void order(list arr[], int idx, int n)
{
    if(arr[idx].ada == false)
	{
        printf("Menu does not exist\n");
    }
    else if(n == 0)
	{
        printf("So you want to order or what\n");
    }
    else if(arr[idx].stok < n)
	{
        printf("Apologize, the stock is not enough\n");
    }
    else 
	{
        arr[idx].stok -= n;
        
        printf("Ordered %dx %s for Rp%d\n", n, arr[idx].name, arr[idx].prc * n);
        
        cash += arr[idx].prc * n;
    }
}

void erase(list arr[], int idx)
{
    if(arr[idx].ada == false)
	{
        printf("Menu does not exist\n");
    }
    else
	{
        printf("Menu removed\n");
        
        arr[idx].ada = false;
    }
}

void close()
{
	printf("Earnings: Rp%lld\nInformatics canteen is closing... thanks for the visit!\n", cash);
}

int main()
{
    while(true)
	{
        char cmd[101], name[101];
        int idx, stok, prc, n;
        double dis;
        
        scanf("%s", cmd);
        
        if(strcmp(cmd, "CLOSE") == 0)
		{
        	close();
        	return 0;
        }

        else if(strcmp(cmd, "ADD") == 0)
		{
            scanf("%d", &idx);
            
            add(arr, idx);
        }
        
        else if(strcmp(cmd, "INFO") == 0)
		{
            scanf("%d", &idx);
            
            info(arr, idx);
        }
        
        else if(strcmp(cmd, "ORDER") == 0)
		{
            scanf("%d %d", &idx, &n);
            
            order(arr, idx, n);
        }
        
        else if(strcmp(cmd, "REMOVE") == 0)
		{
            scanf("%d", &idx);
            
            erase(arr, idx);
        }
        
        else if(strcmp(cmd, "DISC") == 0)
		{            
            scanf("%d %lf", &idx, &dis);
            
            discount(arr, idx, dis);
        }
        
        else
		{
            printf("Unknown command\n");
        }
    }
}
