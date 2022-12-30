#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "myHeader.h"

void itemMaster()
{	
	int cmd = 0;
	
	do
	{
		itemTitle();
		itemList();
		divider();
		option();
		
		scanf("%d", &cmd);
		
		if(cmd == 1)
		{
			addItem();
		}
		else if(cmd == 2)
		{
			deleteItem();
		}
		else if(cmd == 3)
		{
			addStock();
		}
		else if(cmd == 4)
		{
			editItems();
		}
		else if(cmd == 0)
		{
			break;
		}
		else
		{
			printf("Option doesn't exist.\n");
			delay(1);
		}
	}
	while(cmd != 0);
}

void option()
{
	printf("Item Master : \n");
	printf("1. Add Items\n");
	printf("2. Delete Items\n");
	printf("3. Add Stock\n");
	printf("4. Edit Existing Items\n");
	printf("0. Return to Main Menu\n");
	divider();
	printf("Do : ");
}

void addItem()
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
	scanf("%d", &temp.id);
	fflush(stdin);
	
	if(temp.id <= 0)
	{
		printf("Invalid ID, returning.\n");
		delay(1);
		fclose(fp);
		return;
	}
	
	printf("Enter Item Name : ");
	fflush(stdin);
	scanf("%[^\n]s", temp.name);
	
	printf("Enter Item Price : ");
	scanf("%lld", &temp.price);
	
	fseek(fp, (temp.id - 1) * sizeof(itemData), SEEK_SET);
	fwrite(&temp, sizeof(itemData), 1, fp);
	fclose(fp);
}

void deleteItem()
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
	scanf("%d", &temp.id);
	fflush(stdin);
	
	fseek(fp, (temp.id - 1) * sizeof(itemData), SEEK_SET);
	
	if(temp.id <= 0)
	{
		printf("Invalid ID, returning.\n");
		delay(1);
		fclose(fp);
		return;
	}
	
	reset(&temp);
	fwrite(&temp, sizeof(itemData), 1, fp);
	
	fclose(fp);
}

void addStock()
{
	FILE *fp;
	itemData temp = defaultItem;
	int tstock;
	ll tcapital;
	
	if((fp = fopen("Database.dat", "rb+")) == NULL)
	{
		printf("ERROR.\n");
		delay(1);
		return;	
	}
	
	printf("Enter Item ID : ");
	scanf("%d", &temp.id);
	fflush(stdin);
	
	fseek(fp, (temp.id - 1) * sizeof(itemData), SEEK_SET);
	fread(&temp, sizeof(itemData), 1, fp);
	
	if(temp.id <= 0)
	{
		printf("Invalid ID, returning.\n");
		delay(1);
		fclose(fp);
		return;
	}
	
	printf("Add how many items to stock : ");
	scanf("%d", &tstock);
	
	printf("Capital for added items : ");
	scanf("%lld", &tcapital);
	
	temp.stock += tstock;
	temp.capital += tcapital;
	
	fseek(fp, (temp.id - 1) * sizeof(itemData), SEEK_SET);
	fwrite(&temp, sizeof(itemData), 1, fp);
	
	fclose(fp);
}

void editItems()
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
	scanf("%d", &temp.id);
	
	fflush(stdin);
	fseek(fp, (temp.id - 1) * sizeof(itemData), SEEK_SET);
	fread(&temp, sizeof(itemData), 1, fp);
	
	if(temp.id <= 0)
	{
		printf("Invalid ID, returning.\n");
		delay(1);
		fclose(fp);
		return;
	}
	
	char edit[10];
	
	printf("What would you like to edit? <name/price> : ");
	fflush(stdin);
	
	scanf("%s", edit);
	
	if(strcmp(edit, "name") == 0)
	{
		printf("Enter new item name : ");
		fflush(stdin);
		scanf("%[^\n]s", temp.name);
	}
	else if(strcmp(edit, "price") == 0)
	{
		printf("Enter new item price : ");
		scanf("%lld", &temp.price);	
	}
	
	fseek(fp, (temp.id - 1) * sizeof(itemData), SEEK_SET);
	fwrite(&temp, sizeof(itemData), 1, fp);
	fclose(fp);
}
