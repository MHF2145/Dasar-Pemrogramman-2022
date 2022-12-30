#include <stdio.h>
#include <string.h>

int main()
{
	// Your code goes here
	int n;
	scanf ("%d", &n);
	char kata[100002]; // perlu diubah nanti
	char bayangan[100002];
	char huruf[1];
	scanf ("%s", kata);

	if (n > strlen(kata))
	{
		n = n % strlen(kata);
	}

	for (int i = 1; i <= n; i++)
	{
		memcpy (bayangan, kata + 1, strlen (kata));
		strncpy (huruf, kata, 1);
		strncat (bayangan, kata, 1);
		strcpy (kata, bayangan);
	}

	printf ("%s", kata);
}