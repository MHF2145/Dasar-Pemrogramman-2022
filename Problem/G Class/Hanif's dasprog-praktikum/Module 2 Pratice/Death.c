#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () 
{
	long long N, stat, hp, ttl = 0;
	char rider[1000];
	const char p[2] = ".";
	char *player, *nama, *keadaan, *nyawa;
	
	scanf("%lld", &N);
	for ( int i = 0; i < N; i++ ) 
    {	
	scanf("%s[^\n]", rider);
	
	player = strtok (rider, p);
  	nama = strtok (NULL, p);
  	keadaan = strtok (NULL, p);
  	nyawa = strtok (NULL, p); 
	
	stat = atoi (keadaan);
	hp = atoi (nyawa);
	
	if (stat % 5 == 0) 
    {
		printf("%s %lld \n", nama, hp);
	}

	else continue;
	ttl += hp;
	}

	printf("\nTOTAL SCORE: %lld", ttl);

}