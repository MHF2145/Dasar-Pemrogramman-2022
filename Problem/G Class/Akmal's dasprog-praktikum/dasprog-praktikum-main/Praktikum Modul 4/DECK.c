#include<stdio.h>
#include<string.h>

typedef struct card
{
	char p[10001];
	int l;
}card;

void swap(card *a, card *b)
{
    card temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
	int n, i;
	
	
	scanf("%d ", &n);
	
	card deck[n + 1];
	
	for(i = 0; i < n; i++)
	{
		char c;
		int len = 0;
		
		while ((c = getchar()) != '\n')
		{
            deck[i].p[len++] = c;
		}
		
		deck[i].p[len] = '\0';
		
		scanf("%d ",  &deck[i].l);
	}
	
	char s[101];
	
	while(scanf("%s", s))
	{
		int a, b;
		
		if(strcmp(s, "SHOW") == 0)
		{
			for(i = 0; i < n; i++)
			{
				printf("%s %d\n", deck[i].p, deck[i].l);
			}
		}
		if(strcmp(s, "SWAP") == 0)
		{
			scanf("%d %d", &a, &b);
			
			if(a == b)
			{
				printf("[Swap on Same Card]\n");
			}
			else if(a >= n || b >= n)
			{
				printf("[Out of Bounds]\n");
			}
			else
			{
				swap(&deck[a], &deck[b]);
			}
		}
		if(strcmp(s, "END") == 0)
		{
			return 0;
		}
	}
}

