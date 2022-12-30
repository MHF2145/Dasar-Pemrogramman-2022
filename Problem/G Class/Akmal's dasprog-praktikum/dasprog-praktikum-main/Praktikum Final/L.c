#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int visited[1001][1001], idx, x, y, ans = 0, p = 0, n, m, t;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char maze[1001][1001];

void solve(int a,int b)
{
	visited[a][b] = idx;
	p++;
	
	if(p > ans)
	{
		x = a;
		y = b;
		ans = p;
	}
	
	int i;
	for(i = 0; i < 4; i++)
	{
		int mx = a + dx[i];
        int my = b + dy[i];
        
        if(mx < 0 || my < 0 || mx >= n || my >= m || maze[mx][my] == '#' || visited[mx][my])
		{
			continue;
		} 
        
        solve(mx, my);
	}
	
	visited[a][b] = 0;
    p--;	
}

int main()
{
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &m, &n);
		
		int k;
		for(k = 0; k < n; k++)
		{
			scanf("%s", maze[k]);
		}
		
		ans = 0, p = 0;
		idx++;
		
		int i, j;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(maze[i][j] != '#')
				{
					solve(i, j);
					i = n;
					break;
				}
			}	
		}
		
		idx++;
		p = 0; ans = 0;
        
		solve(x, y);
        
		printf("Panjang tali adalah %d.\n", ans - 1);
	}
	
	return 0;
}
