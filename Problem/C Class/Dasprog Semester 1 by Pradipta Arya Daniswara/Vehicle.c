#include <stdio.h>

int main()
{
	printf("Speed of vehicles (in miles) : ");
	
	int counter = 0;
	int counter_high = 0;
	int counter_medium = 0;
	int counter_low = 0;
	int arr[30];
	
	int i;
	for(i = 1; i <= 27; i++)
	{
		int speed;
		scanf("%d", &speed);
		arr[i] = speed;
		counter = counter + speed;
		
		if(speed > 90)
		{
			counter_high++;
		}
		else if(speed < 50)
		{
			counter_low++;
		}
		else
		{
			counter_medium++;
		}
	}
	float average = counter / 27.0;
	
	printf("\nVehicles moving at high speed (more than 90 miles/hour) : %d\n", counter_high);
	printf("Vehicles moving at medium speed (50-90 miles/hour) : %d\n", counter_medium);
	printf("Vehicles moving at low speed (less than 50 miles/hour) : %d\n\n", counter_low);
	
	printf("Category of each vehicle :\n");
	for(i = 1; i <= 27; i++)
	{
		if(arr[i] > 90)
		{
			printf("Vehicle #%d (%d miles/hour) : high speed\n", i, arr[i]);
		}
		else if(arr[i] < 50)
		{
			printf("Vehicle #%d (%d miles/hour) : low speed\n", i, arr[i]);
		}
		else
		{
			printf("Vehicle #%d (%d miles/hour) : medium speed\n", i, arr[i]);
		}
	}
	printf("\n");
	
	printf("Average speed of vehicle : %f miles/hour\n", average);
}
