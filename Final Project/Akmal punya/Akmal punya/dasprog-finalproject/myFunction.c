#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "myHeader.h"

void delay(int sec)
{
    int ms = 1000 * sec;
    clock_t start = clock();
    while(clock() < start + ms);
}

void dots(int len)
{
	while(len--)
	{
		printf(".");
		delay(1);
	}
}

void divider()
{
	int i = 98;
	while(i--) printf("-");
	printf("\n");
}

void mainTitle()
{
	system("cls");
	divider();
	printf("|%-38s%-58s|\n", " ", "Cashier System Simulator");
	printf("|%-96s|\n", " ");
	printf("|%-44s%-52s|\n", " ", "~Main Menu~");
	divider();
}

void itemTitle()
{
	system("cls");
	divider();
	printf("|%-38s%-58s|\n", " ", "Cashier System Simulator");
	printf("|%-96s|\n", " ");
	printf("|%-43s%-53s|\n", " ", "~Item Master~");
	divider();
}

void cashierTitle()
{
	system("cls");
	divider();
	printf("|%-38s%-58s|\n", " ", "Cashier System Simulator");
	printf("|%-96s|\n", " ");
	printf("|%-44s%-52s|\n", " ", "~Cashier~");
	divider();
}

void reportTitle()
{
	system("cls");
	divider();
	printf("|%-38s%-58s|\n", " ", "Cashier System Simulator");
	printf("|%-96s|\n", " ");
	printf("|%-44s%-52s|\n", " ", "~Report~");
	divider();
}

void itemList()
{
	FILE *fp;
	itemData temp = defaultItem;
	
	if((fp = fopen("Database.dat", "rb+")) == NULL)
	{
		printf("ERROR.\n");
		delay(1);
		return;	
	}
	
	printf("%-9s|%-26s|%-16s|%-9s\n", "ID", "Item", "Price", "Stock");
	
	int last = 0;
	while(!feof(fp))
	{
		fread(&temp, sizeof(itemData), 1, fp);
		
		if(temp.id == last) break;
		last = temp.id;
		
		if(temp.id > 0) printf("%-9d|%-26s|%-16lld|%-9d\n", temp.id, temp.name, temp.price, temp.stock);
	}
	
	fclose(fp);
}

void reset(itemData *item)
{
	item->id = 0;
	strcpy(item->name, "");
	item->stock = 0;
	item->price = 0;
	item->capital = 0;
	item->income = 0;
	item->transaction = 0;
}

void Struct(ll sum, ll money)
{
	time_t waktu;
	time(&waktu);
	
	FILE *fp, *str;
	itemData temp = defaultItem;
	
	if((fp = fopen("Database.dat", "rb+")) == NULL)
	{
		printf("ERROR.\n");
		delay(1);
		return;	
	}
	
	if((str = fopen("StrukBelanja.txt", "w")) == NULL)
	{
		printf("ERROR.\n");
		delay(1);
		return;	
	}
	
	int i;
	
	for(i = 1; i <= 64; i++) fprintf(str, "-");
	fprintf(str, "\n%-63s*\n", "|");
	fprintf(str, "%-19s%-44s*\n", "|", "Cashier System Simulator");
	fprintf(str, "%-63s*\n", "|");
	for(i = 1; i <= 64; i++) fprintf(str, "-");
	
    fprintf(str, "\n%-26s|%-16s|%-19s\n", "Name", "Amount", "Price");
    
    int last = 0;
    while(!feof(fp))
	{
		fread(&temp, sizeof(itemData), 1, fp);
		
		if(temp.id == last) break;
		
		last = temp.id;
		
		if(temp.transaction > 0)
		{
			fprintf(str, "%-26s|%-16d|%-19lld\n", temp.name, temp.transaction, temp.price * temp.transaction);
			
			temp.transaction = 0;
			fseek(fp, (temp.id - 1) * sizeof(itemData), SEEK_SET);
			fwrite(&temp, sizeof(itemData), 1, fp);
		}
	}
	
	for(i = 1; i <= 64; i++) fprintf(str, "-");
	fprintf(str, "\nTotal   : %lld\n", sum);
	fprintf(str, "Money   : %lld\n", money);
	fprintf(str, "Change  : %lld\n", money - sum);
	for(i = 1; i <= 64; i++) fprintf(str, "-");
	
	fprintf(str, "\nThank You!\n%s", ctime(&waktu));
	
	fclose(str);
}
