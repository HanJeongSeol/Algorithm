#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int road[1001][1001];
int check[1001][1001][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cnt = 0;
void bfs() {
	check[0][0][0] = 1;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx <n&&ny >= 0 && ny <m) {
				if (road[nx][ny] == 0 && check[nx][ny][z] == 0) {
					check[nx][ny][z] = check[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
				if (road[nx][ny] == 1 && z == 0) {
					check[nx][ny][z + 1] = check[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &road[i][j]);
		}
	}
	bfs();
	if (check[n - 1][m - 1][0] != 0 && check[n - 1][m - 1][1] != 0) {
		cout << min(check[n - 1][m - 1][0], check[n - 1][m - 1][1]);
	}
	else if (check[n - 1][m - 1][0] != 0) {
		cout << check[n - 1][m - 1][0];
	}
	else if (check[n - 1][m - 1][1] != 0) {
		cout << check[n - 1][m - 1][1];
	}
	else {
		cout << -1;
	}
	cout << "\n";
	return 0;
}