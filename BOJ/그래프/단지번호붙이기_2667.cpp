#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#pragma warning(disable:4996);
using namespace std;

int maze[26][26];
int group[26][26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans[26 * 26];
int n;

void dfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	group[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (maze[nx][ny] == 1 && group[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = cnt;
				}
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &maze[i][j]);
			group[i][j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == 1 && group[i][j] == 0) {
				dfs(i, j, ++cnt);
			}
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[group[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);

	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}