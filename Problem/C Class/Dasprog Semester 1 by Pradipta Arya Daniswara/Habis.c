#include <stdio.h>

int rekursi(int x, int y, int pembagi, int counter)
{
	if(x % pembagi != 0 || y % pembagi != 0)
	{
		pembagi++;
	}
	
	if(pembagi > x || pembagi > y)
	{
		return counter;
	}
	
	if(x % pembagi == 0 && y % pembagi == 0)
	{
		x = x / pembagi;
		y = y / pembagi;
		counter = counter * pembagi;
	}
	rekursi(x, y, pembagi, counter);
}

int main()
{
	int x;
	scanf("%d", &x);
	int y;
	scanf("%d", &y);
	int hasil = rekursi(x, y, 2, 1);
	printf("%d\n", hasil);
}
