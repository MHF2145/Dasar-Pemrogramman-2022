#include <stdio.h>
#include <string.h>

struct location {
	char name[25];
	int bomb;
};

struct person {
	char name[25];
	char location[25];
};

int main()
{
	int T;
	scanf("%d", &T);
	struct location arr_loc[25];
	struct person arr_per[25];
	char cleaner[10];
	int counter_loc = 1;
	int counter_per = 1;
	
	int i;
	for(i = 1; i <= T; i++)
	{
		char perintah[5];
		scanf("%s", &perintah);
		
		if(strcmp(perintah, "set") == 0)
		{
			char location[25];
			scanf("%s", &location);
			
			if(strcmp(location, "*") == 0)
			{
				char person[25];
				scanf("%s", &person);
				scanf("%s", &cleaner);
				scanf("%s", &location);
				
				strcpy(arr_per[counter_per].name, person);
				strcpy(arr_per[counter_per].location, location);
				counter_per++;
			}
			else
			{
				int bomb;
				scanf("%d", &bomb);
				
				strcpy(arr_loc[counter_loc].name, location);
				arr_loc[counter_loc].bomb = bomb;
				counter_loc++;
			}
		}
		else if(strcmp(perintah, "chg") == 0)
		{
			char location[25];
			scanf("%s", &location);
			
			if(strcmp(location, "*") == 0)
			{
				char person[25];
				scanf("%s", &person);
				char temp[15];
				scanf("%s", &temp);
				
				if(strcmp(temp, "&") == 0)
				{
					scanf("%s", &location);
					
					int j;
					for(j = 1; j <= sizeof(struct person); j++)
					{
						if(strcmp(arr_per[j].name, person) == 0)
						{
							strcpy(arr_per[j].location, location);
							break;
						}
					}
				}
				else
				{
					int bomb = atoi(temp);
					int j;
					for(j = 1; j <= sizeof(struct person); j++)
					{
						if(strcmp(arr_per[j].name, person) == 0)
						{
							int k;
							for(k = 1; k <= sizeof(struct location); k++)
							{
								if(strcmp(arr_loc[k].name, arr_per[j].location) == 0)
								{
									arr_loc[k].bomb = bomb;
									break;
								}
							}
							break;
						}
					}
				}
			}
			else
			{
				int bomb;
				scanf("%d", &bomb);
				
				int j;
				for(j = 1; j <= sizeof(struct location); j++)
				{
					if(strcmp(arr_loc[j].name, location) == 0)
					{
						arr_loc[j].bomb = bomb;
						break;
					}
				}
			}
		}
		else if(strcmp(perintah, "get") == 0)
		{
			char person[25];
			scanf("%s", &cleaner);
			scanf("%s", &person);
			
			int j;
			for(j = 1; j <= sizeof(struct person); j++)
			{
				if(strcmp(arr_per[j].name, person) == 0)
				{
					int k;
					for(k = 1; k <= sizeof(struct location); k++)
					{
						if(strcmp(arr_loc[k].name, arr_per[j].location) == 0)
						{
							printf("%d\n", arr_loc[k].bomb);
							break;
						}
					}
					break;
				}
			}
		}
	}
}
