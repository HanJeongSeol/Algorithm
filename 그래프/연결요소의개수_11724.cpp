#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, m;
vector<int> a[1001];
bool check[1001];

void dfs(int start) {
	check[start] = true;
	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];
		if (check[next] == false)
			dfs(next);
	}
}

int main() {
	int count = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			count += 1;
		}
	}

	cout << count << '\n';
	return 0;
}