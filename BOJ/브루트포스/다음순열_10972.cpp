#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//int a[10001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i1 = 0, j1 = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i]) {
			i1 = i;
		}
	}
	if (i1 == 0) {
		cout << -1 << '\n';
		return 0;
	}
	for (int j = i1; j <n; j++) {
		if (a[j] > a[i1 - 1]) {
			j1 = j;
		}
	}
	swap(a[i1 - 1], a[j1]);
	sort(a.begin() + i1, a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}
