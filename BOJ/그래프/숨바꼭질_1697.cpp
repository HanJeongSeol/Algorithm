#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 100001;
int road[MAX];
bool check[MAX];
int n, k;
queue<int> q;
void bfs() {
	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		if (nx - 1 >= 0) {
			if (check[nx - 1] == false) {
				check[nx - 1] = true;
				road[nx - 1] = road[nx] + 1;
				q.push(nx - 1);
			}
		}
		if (nx + 1 < MAX) {
			if (check[nx + 1] == false) {
				check[nx + 1] = true;
				road[nx + 1] = road[nx] + 1;
				q.push(nx + 1);
			}
		}
		if (nx * 2 < MAX) {
			if (check[nx * 2] == false) {
				check[nx * 2] = true;
				road[nx * 2] = road[nx] + 1;
				q.push(nx * 2);
			}
		}
	}
}

int main() {
	cin >> n >> k;
	road[n] = 0;
	check[n] = true;
	q.push(n);
	bfs();
	cout << road[k] << endl;
	return 0;
}