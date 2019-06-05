#include<iostream>
#include<algorithm>
using namespace std;

int a[10001];
int d[10001][3];
int dp[10001];

int main() {
	int n;
	cin >> n;

	for (int i = 1;i <= n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	dp[1] = a[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]));
	}

	cout << dp[n] << endl;
	return 0;
}

int main() {
	int n; 
	cin >> n;
	for (int i =1; i <= n; i++) {
		cin >> a[i];
	}
	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		d[i][0] = max(d[i-1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	cout << max(max(d[n][0], d[n][1]),d[n][2]) << '\n';
	return 0;
}