#include<iostream>
#include<algorithm>
using namespace std;

int a[1001];
int d[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = 1;
		for (int j = n - 1; j >= i; j--) {
			if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i<n; i++) {
		if (ans < d[i] + dp[i] - 1) {
			ans = d[i] + dp[i] - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}