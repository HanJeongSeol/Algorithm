#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 100001;
int road[MAX];
bool check[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	road[n] = 0;
	check[n] = true;
	deque <int> dq;
	dq.push_back(n);
	while (!dq.empty()) {
		int nx = dq.front();
		dq.pop_front();
		if (nx * 2 < MAX && check[nx * 2] == false) {
			dq.push_front(nx * 2);
			check[nx * 2] = true;
			road[nx * 2] = road[nx];
		}
		if (nx + 1 < MAX && check[nx + 1] == false) {
			dq.push_back(nx + 1);
			check[nx + 1] = true;
			road[nx + 1] = road[nx] + 1;
		}
		if (nx - 1 >= 0 && check[nx - 1] == false) {
			dq.push_back(nx - 1);
			check[nx - 1] = true;
			road[nx - 1] = road[nx] + 1;
		}

	}
	cout << road[k] << "\n";
	return 0;
}