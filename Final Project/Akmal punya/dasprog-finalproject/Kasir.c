#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "myHeader.h"

void cashier()
{
	char con = 'y';
	do 
	{
		cashierTitle();
		itemList();
		divider();
		
		int cmd = 1;
		
		printf("<Enter 0 to stop transaction>\n");
		divider();
		int amount; 
		ll total = 0, payment = 0;
		
		while(cmd != 0)
		{
			FILE *fp;
			itemData temp = defaultItem;
			
			if((fp = fopen("Database.dat", "rb+")) == NULL)
			{
				printf("ERROR.\n");
				delay(1);
				return;	
			}
			
			printf("Enter Item ID : ");
			scanf("%d", &cmd);
			
			fflush(stdin);
			if(cmd == 0)
			{
				break;
			}
			
			fseek(fp, (cmd - 1) * sizeof(itemData), SEEK_SET);
			fread(&temp, sizeof(itemData), 1, fp);
			
			if(temp.id == 0)
			{
				printf("ID not found.\n");
				delay(1);
				fclose(fp);
				continue;
			}
			
			printf("Amount of items to buy : ");
			scanf("%d", &amount);
			
			if(amount > temp.stock)
			{
				printf("Insufficient item stock, returning.\n");
				delay(1);
				fclose(fp);
				continue;
			}
			
			total += (ll) amount * temp.price;
			temp.stock -= amount;
			temp.transaction = amount;
			temp.income += total;
			
			fseek(fp, (cmd - 1) * sizeof(itemData), SEEK_SET);
			fwrite(&temp, sizeof(itemData), 1, fp);
			fclose(fp);
		}
		
		do 
		{
			divider();
			printf("Total             : %lld\n", total);
			printf("Enter payment     : ");
			scanf("%lld", &payment);
			
			if(payment < total)
			{
				printf("Insufficient payment, returning.\n");
				delay(1);
				continue;
			}
			else 
			{
				printf("Change            : %lld\n", payment - total);
				break;
			}
		}
		while(payment < total);
		
		Struct(total, payment);
		
		divider();
		
		printf("\nDo another transaction? <y/n> : ");
		fflush(stdin);
		
		scanf("%c", &con);
		fflush(stdin);
	}
	while(con == 'y');
}
