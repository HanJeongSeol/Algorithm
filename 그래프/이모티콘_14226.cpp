#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n;
int visited[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	//memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	visited[1][0] = 0;
	while (!q.empty()) {
		int s, c;
		s = q.front().first;
		c = q.front().second;
		q.pop();

		if (visited[s][s] == 0) {
			visited[s][s] = visited[s][c] + 1;
			q.push(make_pair(s, s));
		}
		if (s + c <= n && visited[s + c][c] == 0) {
			visited[s + c][c] = visited[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		if (s - 1 >= 0 && visited[s - 1][c] == 0) {
			visited[s - 1][c] = visited[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}

	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (visited[n][i] != 0) {
			if (ans == -1 || ans > visited[n][i]) {
				ans = visited[n][i];
			}
		}
	}
	cout << ans << "\n";
}