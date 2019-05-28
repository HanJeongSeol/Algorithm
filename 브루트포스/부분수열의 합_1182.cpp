#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ans = 0;
int num;
int result;
void go(vector<int> a, int index, int sum) {
	if (num == index) {
		if (sum == result) {
			ans += 1;
		}
		return;
	}

	go(a, index + 1, sum + a[index]);
	go(a, index + 1, sum);
}

int main() {
	cin >> num >> result;
	vector<int> a(num);
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	go(a, 0, 0);
	if (result == 0) ans -= 1;
	cout << ans << '\n';
	return 0;
}