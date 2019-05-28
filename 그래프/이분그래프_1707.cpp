#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;;
vector<int> a[20001];
int color[20001];

void dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		scanf("%d %d", &v, &e);

		for (int i = 1; i <= v; i++) {
			a[i].clear();
			color[i] = 0;
		}

		for (int i = 0; i < e; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}
		bool check = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j < a[i].size(); j++) {
				int next = a[i][j];
				if (color[i] == color[next])
					check = false;
			}
		}
		printf("%s\n", check ? "YES" : "NO");
	}
}