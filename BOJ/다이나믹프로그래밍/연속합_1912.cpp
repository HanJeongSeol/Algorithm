#include<iostream>
#include<algorithm>
using namespace std;

int d[100001];
int a[100001];

int main() {
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
	}

	int ans = -100000;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i])
			ans = d[i];
	}
	cout << ans << '\n';
	return 0;
}