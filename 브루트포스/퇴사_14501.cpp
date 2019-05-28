#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int num;
int ans = 0;
int a[16];
int b[16];

void go(int index, int sum) {
	//index==num날 까지 상담가능, index==num+1이 돈받는날
	if (index == num + 1) {
		if (sum > ans) ans = sum;
		return;
	}
	if (index > num + 1) return;
	go(index + a[index], sum + b[index]);
	go(index + 1, sum);
}
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> a[i] >> b[i];
	}
	go(1, 0);
	cout << ans << endl;
	return 0;
}