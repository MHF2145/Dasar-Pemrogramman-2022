#include <stdio.h>

void rekursi(int x)
{
	if(x == 1)
	{
		printf("%d ", x);
		return;
	}
	if(x % 4 == 0)
	{
		printf("%d ", x);
		rekursi(x / 4);
	}
	else
	{
		printf("%d ", x);
		rekursi(x + 1);
	}
}

int main()
{
	int x;
	scanf("%d", &x);
	rekursi(x);
}
