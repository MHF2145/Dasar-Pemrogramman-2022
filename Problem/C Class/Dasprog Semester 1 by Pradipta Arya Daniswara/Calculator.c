#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int add(int input1, int input2)
{
	return input1 + input2;
}

int sub(int input1, int input2)
{
	return input1 - input2;
}

int mul(int input1, int input2)
{
	return input1 * input2;
}

float div(int input1, int input2)
{
	return 1.0 * input1 / input2;
}

int fact(int input)
{
	int result = 1;
	int i;
	for(i = input; i >= 1; i--)
	{
		result = result * i;
	}
	return result;
}

int main()
{
	while(true)
	{
		printf("1: Addition\n");
		printf("2: Subtraction\n");
		printf("3: Multiplication\n");
		printf("4: Division\n");
		printf("5: Factorial\n");
		printf("6: Quit\n");
		
		printf("Enter the choice : ");
		int choice;
		scanf("%d", &choice);
		
		int input1;
		int input2;
		if(choice >= 1 && choice <= 4)
		{
			printf("Enter two integers : ");
			scanf("%d", &input1);
			scanf("%d", &input2);
			
			switch(choice) {
				case 1:
					printf("Result : %d\n", add(input1, input2));
					break;
				case 2:
					printf("Result : %d\n", sub(input1, input2));
				    break;
				case 3:
				    printf("Result : %d\n", mul(input1, input2));
				    break;
				case 4:
				    printf("Result : %f\n", div(input1, input2));
				    break;
			}
		}
		else if(choice == 5)
		{
			printf("Enter an integer : ");
			scanf("%d", &input1);
			if(input1 > 0)
			{
				printf("Result : %d\n", fact(input1));
			}
		}
		else if(choice == 6)
		{
			break;
		}
	}
}
