#include<iostream>
#include<algorithm>
using namespace std;

int a[9];
int b[9];
bool check[9];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[b[i]];
			if (i != m)cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		b[index] = i;
		go(index + 1, n, m);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	go(0, n, m);
}