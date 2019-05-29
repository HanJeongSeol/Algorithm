#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maze[101][101];
int group[101][101];
int dx[] = { 0,0,1,-1,1,-1,1,-1 };
int dy[] = { 1,-1,0,0 ,-1,1 ,1,-1 };
int w, h;

void dfs(int x, int y, int cnt) {
	group[x][y] = cnt;
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (maze[nx][ny] == 1 && group[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> maze[i][j];
				group[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (maze[i][j] == 1 && group[i][j] == 0) {
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}