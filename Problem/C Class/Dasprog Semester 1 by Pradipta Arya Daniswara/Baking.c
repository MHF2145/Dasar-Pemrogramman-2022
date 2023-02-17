#include <stdio.h>

void white_bread(char size, char manual)
{
	int counter = 0;
	
	printf("\n1. Knead the dough for 15 mins.\n");
	printf("2. Rise the dough for 60 mins.\n");
	printf("3. Knead the dough again for 18 mins.\n");
	printf("4. Rise the dough again for 20 mins.\n");
	printf("5. Shape the dough for 2 seconds.\n");
	counter = counter + 15 * 60 + 60 * 60 + 18 * 60 + 20 * 60 + 2;
	
	if(manual == 'Y')
	{
		printf("6. Lastly, remove the dough for manual baking.\n");
	}
	else if(manual == 'N')
	{
		printf("6. Finally, rise the dough again for 75 mins.\n");
		counter = counter + 75 * 60;
		if(size == 'Y')
		{
			printf("7. Bake the dough for 67 mins and 30 seconds.\n");
			counter = counter + 67 * 60 + 30;
		}
		else if(size == 'N')
		{
			printf("7. Bake the dough for 45 mins.\n");
			counter = counter + 45 * 60;
		}
		printf("8. Lastly, cool the dough for 30 mins before consumption.\n");
		counter = counter + 30 * 60;
	}
	
	baking_time(counter);
}

void sweet_bread(char size, char manual)
{
	int counter = 0;
	
	printf("\n1. Knead the dough for 20 mins.\n");
	printf("2. Rise the dough for 60 mins.\n");
	printf("3. Knead the dough again for 33 mins.\n");
	printf("4. Rise the dough again for 30 mins.\n");
	printf("5. Shape the dough for 2 seconds.\n");
	counter = counter + 20 * 60 + 60 * 60 + 33 * 60 + 30 * 60 + 2;
	
	if(manual == 'Y')
	{
		printf("6. Lastly, remove the dough for manual baking.\n");
	}
	else if(manual == 'N')
	{
		printf("6. Finally, rise the dough again for 75 mins.\n");
		counter = counter + 75 * 60;
		if(size == 'Y')
		{
			printf("7. Bake the dough for 52 mins and 30 seconds.\n");
			counter = counter + 52 * 60 + 30;
		}
		else if(size == 'N')
		{
			printf("7. Bake the dough for 35 mins.\n");
			counter = counter + 35 * 60;
		}
		printf("8. Lastly, cool the dough for 30 mins before consumption.\n");
		counter = counter + 30 * 60;
	}
	
	baking_time(counter);
}

int baking_time(time)
{
	int minutes = time / 60;
	int seconds = time % 60;
	printf("\nTotal baking time : %d minutes and %d seconds\n", minutes, seconds);
}

int main()
{
	printf("Type of bread? (W/S) : ");
	char type;
	scanf(" %c", &type);
	printf("Double the loaf size? (Y/N) : ");
	char size;
	scanf(" %c", &size);
	printf("Manual baking (Y/N) : ");
	char manual;
	scanf(" %c", &manual);
	
	if(type == 'W')
	{
		white_bread(size, manual);
	}
	else if(type == 'S')
	{
		sweet_bread(size, manual);
	}
}
