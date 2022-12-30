#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "myHeader.h"

int main()
{	
	int cmd = 1;
	do
	{
		mainTitle();
		printf("Menu :\n");
		printf("1. Store Item Master\n");
		printf("2. Cashier\n");
		printf("3. Financial Report\n");
		printf("0. Close\n");
		divider();
		printf("Do : ");
		scanf("%d", &cmd);
		
		if(cmd == 1)
		{
			itemMaster();
		}
		else if(cmd == 2)
		{
			cashier();
		}
		else if(cmd == 3)
		{
			report();
		}
		else if(cmd == 0)
		{
			printf("\nSTORE IS CLOSING");
			dots(3);
			printf("\nTHANK YOU!\n");
		}
		else
		{
			printf("Option doesn't exist.\n");
			delay(1);
		}
	}
	while(cmd != 0);
	
	return 0;
}
