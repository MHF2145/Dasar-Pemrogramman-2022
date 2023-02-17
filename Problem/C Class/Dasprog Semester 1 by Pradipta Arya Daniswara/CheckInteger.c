#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int reverse(int input)
{
	int arr[20];
	int counter = 0;
	while(true)
	{
		arr[counter + 1] = input % 10;
		counter++;
		
		if(input < 10)
		{
			break;
		}
		input = input / 10;
	}
	
	int result = 0;
	int i;
	for(i = 1; i <= counter; i++)
	{
		result = result * 10 + arr[i];
	}
	return result;
}

bool prime(int input)
{
	if(input == 1)
	{
		return false;
	}
	
	if(input % 2 == 0 && input != 2)
	{
		return false;
	}
	
	int i;
	for(i = 3; i <= sqrt(input); i = i + 2)
	{
		if(input % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool palindrome(int input)
{
	if(reverse(input) == input)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	printf("Input an integer : ");
	int input;
	scanf("%d", &input);
	
	printf("Reverse : %d\n", reverse(input));
	
	if(prime(input) == true)
	{
		printf("Prime Number\n");
	}
	else
	{
		printf("Non Prime Number\n");
	}
	
	if(palindrome(input) == true)
	{
		printf("Palindrome Number\n");
	}
	else
	{
		printf("Non Palindrome Number\n");
	}
}
