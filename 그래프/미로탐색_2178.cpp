#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
int maze[101][101];
int group[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	group[x][y] = 1;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int xn = nx + dx[k];
			int xy = ny + dy[k];
			if (xn >= 0 && xn <n && xy >= 0 && xy <m)
				if (maze[xn][xy] == 1 && group[xn][xy] == 0) {
					q.push(make_pair(xn, xy));
					group[xn][xy] = group[nx][ny] + 1;
				}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == 1 && group[i][j] == 0)
				bfs(i, j);
		}
	}
	cout << group[n - 1][m - 1] << "\n";
	return 0;
}