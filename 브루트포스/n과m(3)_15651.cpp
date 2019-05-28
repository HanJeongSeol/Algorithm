#include<iostream>
#include<algorithm>
using namespace std;
int a[9];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < index; i++) {
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		a[index] = i;
		go(index + 1, n, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	go(0, n, m);
	return 0;
}