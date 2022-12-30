#include<stdio.h>
#include<stdbool.h>

char maze[10][10];
int visited[10][10];

void solve(int x, int y){
    if (x >= 0 && x < 10 && y >= 0 && y < 10){
        if (!visited[x][y]){
            
			visited[x][y] = 1;
            
            if(maze[x][y] != '#'){
                solve(x + 1, y);
                solve(x, y + 1);
                solve(x - 1, y);
                solve(x, y - 1);
            }
        }
    }
}

int main(){
	int i, j, mx, my, px, py;;
	
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			scanf("%c", &maze[i][j]);
			
			if(maze[i][j] == 'P'){
				px = i;
				py = j;
			}
			if(maze[i][j] == 'M'){
				mx = i;
				my = j;
			}
		}
		scanf(" ");
	}
	
	solve(px, py);
	
	if(visited[mx][my]){
		printf("[GURETO DAZE!]\n");
	}
	else{
		printf("[YARE YARE DAZE!]\n");
	}
}

