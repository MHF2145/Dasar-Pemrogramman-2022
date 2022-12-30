#include<stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

void WorldSeed(int level[], int n, long long seed, int multiplier, int max_diff)
{
	int i;
	for(i = 0; i < n; i++)
	{
		seed = seed * multiplier % max_diff + 1;
		multiplier = (multiplier + seed) % max_diff + 1;
		level[i] = seed;
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%d\n", level[i]);
	}
}

int main(){
	int n, i, multiplier, max_diff;
	long long seed;
	
	scanf("%d% lld %d %d", &n, &seed, &multiplier, &max_diff);
	
	int level[n];
	
	WorldSeed(level, n, seed, multiplier, max_diff);
	
	// ndak tau algo longest increasing subsequence haha
}
