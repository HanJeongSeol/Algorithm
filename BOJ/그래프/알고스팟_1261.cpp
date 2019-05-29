//#include<iostream>
//#include<deque>
//#include<cstdio>
//#include<algorithm>
//#pragma warning(disable:4996)
//using namespace std;
//
//int n, m;
//int road[555][555];
//int check[555][555];
//int dx[] = { 0,0,1,-1 };
//int dy[] = { 1,-1,0,0 };
//
//int main() {
//	cin >> m >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf("%1d", &road[i][j]);
//			check[i][j] = -1;
//		}
//	}
//	deque<pair<int, int>> dq;
//	check[0][0] = 0;
//	dq.push_back(make_pair(0, 0));
//	while (!dq.empty()) {
//		int x = dq.front().first;
//		int y = dq.front().second;
//		dq.pop_front();
//		for (int k = 0; k < 4; k++) {
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
//				if (check[nx][ny] == -1) {
//					if (road[nx][ny] == 0) {
//						check[nx][ny] = check[x][y];
//						dq.push_front(make_pair(nx, ny));
//					}
//					else {
//						check[nx][ny] = check[x][y] + 1;
//						dq.push_back(make_pair(nx, ny));
//					}
//				}
//			}
//		}
//	}
//	cout << check[n-1][m-1] << "\n";
//	return 0;
//}


#include<iostream>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int road[555][555];
int check[555][555];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &road[i][j]);
			check[i][j] = -1;
		}
	}
	check[0][0] = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_q;

	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (check[nx][ny] == -1) {
					if (road[nx][ny] == 0) {
						check[nx][ny] = check[x][y];
						q.push(make_pair(nx, ny));
					}
					else {
						check[nx][ny] = check[x][y] + 1;
						next_q.push(make_pair(nx, ny));
					}
				}
			}
		}
		if (q.empty()) {
			q = next_q;
			next_q = queue<pair<int, int>>();
		}
	}
	cout << check[n - 1][m - 1] << "\n";
}	