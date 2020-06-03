// Review exercies, floodfill labeling some noise in a grid
// connected components
// implementation from memory just to refresh

#include <bits/stdc++.h>
using namespace std;

int n = 10;
int grid[10][10];
int visited[10][10];
int group = 1;

bool oob(int x, int y){
	return x < 0 || y < 0 || x >= n || y >= n;
}

void dfs_visit(int x, int y){
	if(visited[x][y] || oob(x,y) || !grid[x][y]) return;
	visited[x][y] = group;
	dfs_visit(x, y+1);
	dfs_visit(x, y-1);
	dfs_visit(x+1, y);
	dfs_visit(x-1, y);
}

void dfs(){
	for (int i = 0; i < n; ++i) {
		for (int j = 0;j < n;j++) {
			if(!visited[i][j] && grid[i][j]){
				dfs_visit(i, j);
				group++;
			}
		}	
	}
}
int main(int argc, char *argv[])
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			grid[i][j] = rand()%2;	
			visited[i][j] = 0;
			std::cout << grid[i][j]; 
		}	
		std::cout << std::endl;
	}	
	std::cout << std::endl;
	dfs();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <n;j++) {
			std::cout << (char)(visited[i][j]+96);
		}	
		std::cout << std::endl;
	}
	return 0;
}
