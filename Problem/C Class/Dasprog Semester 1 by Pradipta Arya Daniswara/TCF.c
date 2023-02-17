#include <stdio.h>
#include <string.h>

struct area {
    char name[50];
    int people_count;
};

struct person {
    char name[50];
    int age;
    char phone[50];
    char bestie[50];
};

int main()
{
	int area_count;
	scanf("%d", &area_count);
	struct area arr2[area_count + 100];
	struct person arr[200];
	
	int counter = 0;
	int i;
	for(i = 1; i <= area_count; i++)
	{
		char area[50];
		scanf("%s", &area);
		int people_count;
		scanf("%d", &people_count);
		
		strcpy(arr2[i].name, area);
		arr2[i].people_count = people_count;
		
		int j;
		for(j = 1; j <= people_count; j++)
		{
			char name[50];
			scanf("%s", &name);
			int age;
			scanf("%d", &age);
			char phone[50];
			scanf("%s", &phone);
			
			strcpy(arr[j + counter].name, name);
			arr[j + counter].age = age;
			strcpy(arr[j + counter].phone, phone);
			strcpy(arr[j + counter].bestie, "");
		}
		counter = counter + people_count;
	}
	
	int friend_count;
	scanf("%d", &friend_count);
	for(i = 1; i <= friend_count; i++)
	{
		char friendA[50];
		scanf("%s", &friendA);
		char friendB[50];
		scanf("%s", &friendB);
		
		int j;
		for(j = 1; j <= sizeof(struct person); j++)
		{
			if(strcmp(arr[j].name, friendA) == 0)
			{
				int k;
				for(k = 1; k <= sizeof(struct person); k++)
				{
					if(strcmp(arr[k].name, friendB) == 0)
					{
						strcpy(arr[j].bestie, friendB);
						break;
					}
				}	
			}
		}
	}
	
	counter = 0;
	for(i = 1; i <= area_count; i++)
	{
		printf("%s\n", arr2[i].name);
		int j;
		for(j = 1; j <= arr2[i].people_count; j++)
		{
			printf("Name: %s\n", arr[j + counter].name);
			printf("Age: %d\n", arr[j + counter].age);
			printf("Phone Number:%s\n", arr[j + counter].phone);
			if(strcmp(arr[j + counter].bestie, "") != 0)
			{
				printf("His/Her bestie is: %s\n", arr[j + counter].bestie);
				printf("His/Her contact info is as follows\n");
				int k;
				for(k = 1; k <= sizeof(struct person); k++)
				{
					if(strcmp(arr[k].name, arr[j + counter].bestie) == 0)
					{
						printf("Name: %s\n", arr[k].name);
						printf("Age: %d\n", arr[k].age);
						printf("Phone Number:%s\n", arr[k].phone);
						break;
					}
				}
			}
			else
			{
				printf("His/Her bestie is: No one\n");
			}
			printf("\n");
		}
		counter = counter + arr2[i].people_count;
	}
}
