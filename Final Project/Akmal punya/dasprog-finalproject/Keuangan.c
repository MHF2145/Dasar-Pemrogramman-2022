#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "myHeader.h"

void report()
{
	ll total_income = 0, total_capital = 0;
	reportTitle();
	
	FILE *fp;
	itemData temp = defaultItem;
	
	if((fp = fopen("Database.dat", "rb+")) == NULL)
	{
		printf("ERROR.\n");
		delay(1);
		return;	
	}
	
	printf("%-9s|%-26s|%-16s|%-9s|%-16s|%-16s\n", "Id", "Item", "Price", "Stock", "Capital", "Income");
	
	int last = 0;
	while(!feof(fp))
	{
		fread(&temp, sizeof(itemData), 1, fp);
		
		if(temp.id == last) break;
		
		last = temp.id;
		
		if(temp.id > 0)
		{
			total_capital += temp.capital;
			total_income += temp.income;
			printf("%-9d|%-26s|%-16lld|%-9d|%-16lld|%-16lld\n", temp.id, temp.name, temp.price, temp.stock, temp.capital, temp.income);
		}
	}
	
    ll profit = total_income - total_capital;
	
	fclose(fp);
	
	divider();
	
	printf("Total Capital \t: %lld\n", total_capital);
    printf("Total Income \t: %lld\n", total_income);
    
    if(profit < 0) printf("Loss \t\t: %lld\n", -profit);
    else printf("Gain \t\t: %lld\n", profit);
    
	divider();
		
    fflush(stdin);
    printf("\nPress <enter>");
    getchar();
}
