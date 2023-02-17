#include <stdio.h>
#include <string.h>

struct catalogue {
	char name[100];
	int price;
	int stock;
	int discount;
};

int main()
{
	struct catalogue arr[1000005];
	memset(arr, -1, sizeof(arr));
	
	int earnings = 0;
	while(1)
	{
		char perintah[10];
		scanf("%s", &perintah);
		
		if(strcmp(perintah, "ADD") == 0)
		{
			int id;
			scanf("%d", &id);
			char name[100];
			scanf("\n%[^\n]s", name);
			int price;
			scanf("%d", &price);
			int stock;
			scanf("%d", &stock);
			
			if(arr[id].price == -1)
			{
				strcpy(arr[id].name, name);
				arr[id].price = price;
				arr[id].stock = stock;
				arr[id].discount = 0;
				
				printf("Menu added\n");
			}
			else
			{
				printf("Menu is already exists\n");
			}
		}
		else if(strcmp(perintah, "REMOVE") == 0)
		{
			int id;
			scanf("%d", &id);
			
			if(arr[id].price != -1)
			{
				arr[id].price = -1;
				printf("Menu removed\n");
			}
			else
			{
				printf("Menu does not exist\n");
			}
		}
		else if(strcmp(perintah, "INFO") == 0)
		{
			int id;
			scanf("%d", &id);
			
			if(arr[id].price != -1)
			{	
				printf("#%d %s\n", id, arr[id].name);
				printf("Price : Rp%d\n", arr[id].price);
				printf("Stock : %dx\n\n", arr[id].stock);
			}
			else
			{
				printf("Menu does not exist\n");
			}
		}
		else if(strcmp(perintah, "ORDER") == 0)
		{
			int id;
			scanf("%d", &id);
			int amount;
			scanf("%d", &amount);
			
			if(arr[id].price != -1)
			{
				if(amount == 0)
				{
					printf("So you want to order or what\n");
				}
				else if(amount > arr[id].stock)
				{
					printf("Apologize, the stock is not enough\n");
				}
				else
				{
					int total_price = amount * arr[id].price * ((100 - arr[id].discount) / 100.0);
					earnings = earnings + total_price;
					printf("Ordered %dx %s for Rp%d\n", amount, arr[id].name, total_price);
				}
			}
			else
			{
				printf("Menu does not exist\n");
			}
		}
		else if(strcmp(perintah, "DISC") == 0)
		{
			int id;
			scanf("%d", &id);
			int discount;
			scanf("%d", &discount);
			
			if(arr[id].price != -1)
			{
				arr[id].discount = discount;
				printf("Discount added\n");
			}
			else
			{
				printf("Menu does not exist\n");
			}
		}
		else if(strcmp(perintah, "CLOSE") == 0)
		{
			printf("Earnings: Rp%d\n", earnings);
			printf("Informatics canteen is closing... thanks for the visit!\n");
			break;
		}
		else
		{
			printf("Unknown command\n");
		}
	}
}
