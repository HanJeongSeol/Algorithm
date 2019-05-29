#include<iostream>
#include<algorithm>
using namespace std;

int maze[501][501];
int check[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int result = 0;
int n, m;

void dfs(int i, int j, int cnt, int sum) {
	result = max(result, sum);
	if (cnt == 4) {
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m&& check[nx][ny] != 1) {
			check[nx][ny] = 1;
			dfs(nx, ny, cnt + 1, sum + maze[nx][ny]);
			check[nx][ny] = 0;
		}
	}
}
void exshape(int x, int y) {
	// っ
	if (x - 1 >= 0 && x < n && y + 2 < m && y >= 0) {
		result = max(result, maze[x][y] + maze[x - 1][y + 1] + maze[x][y + 1] + maze[x][y + 2]);
	}
	// ぬ
	if (x >= 0 && x + 2 < n &&y - 1 >= 0 && y < m) {
		result = max(result, maze[x][y] + maze[x + 1][y] + maze[x + 2][y] + maze[x + 1][y - 1]);
	}
	// で
	if (x >= 0 && x + 2 < n && y + 1 < m && y >= 0) {
		result = max(result, maze[x][y] + maze[x + 1][y] + maze[x + 2][y] + maze[x + 1][y + 1]);
	}
	// た
	if (x >= 0 && x + 1 < n && y + 2 < m && y >= 0) {
		result = max(result, maze[x][y] + maze[x][y + 1] + maze[x][y + 2] + maze[x + 1][y + 1]);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			check[i][j] = 0;
		}
	}

	for (int i = 0; i <n; i++) {
		for (int j = 0; j <m; j++) {
			check[i][j] = 1;
			dfs(i, j, 1, maze[i][j]);
			exshape(i, j);
			check[i][j] = 0;
		}
	}

	cout << result << '\n';
	return 0;
}