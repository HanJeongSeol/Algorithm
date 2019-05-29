#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[11][11];
int d[11];
int n;

bool next_permutation_self(int *a) {
	int i1 = 0, j1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i]) {
			i1 = i;
		}
	}
	if (i1 == 0) return false;

	for (int j = i1; j < n; j++) {
		if (a[j] > a[i1 - 1]) {
			j1 = j;
		}
	}
	swap(a[j1], a[i1 - 1]);
	sort(a + i1, a + n);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int ans = 987654321;
	for (int i = 0; i < n; i++) {
		d[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	do {
		int sum = 0;
		bool check = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[d[i]][d[i + 1]] == 0) check = false;
			else {
				sum += a[d[i]][d[i + 1]];
			}
		}
		if (check && a[d[n - 1]][d[0]] != 0) {
			sum += a[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation_self(d));

	cout << ans << '\n';
	return 0;
}