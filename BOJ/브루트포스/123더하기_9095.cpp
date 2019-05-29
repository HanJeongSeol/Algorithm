#include<iostream>
#include<algorithm>
using namespace std;

int plus_1(int sum, int ans) {
	if (sum > ans) return 0;
	if (sum == ans) return 1;
	int hap = 0;
	for (int i = 1; i <= 3; i++) {
		hap += plus_1(sum + i, ans);
	}
	return hap;
}

int main() {
	int t;
	int result;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		result = plus_1(0, n);
		cout << result << '\n';
	}
}