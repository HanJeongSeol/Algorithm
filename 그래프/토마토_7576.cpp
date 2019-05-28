#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int to[1001][1001];
int group[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> to[i][j];
			group[i][j] = -1;
			if (to[i][j] == 1) {
				group[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (to[nx][ny] == 0 && group[nx][ny] == -1) {
				group[nx][ny] = group[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnt < group[i][j]) cnt = group[i][j];
			if (to[i][j] == 0 && group[i][j] == -1) {
				cnt = -1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (to[i][j] == 0 && group[i][j] == -1) {
				cnt = -1;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}