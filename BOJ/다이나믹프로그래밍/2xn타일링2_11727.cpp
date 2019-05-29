#include<iostream>
#include<algorithm>
using namespace std;

int d[1001];
int n;

void bottom_up(int n) {
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + (2 * d[i - 2]);
		d[i] %= 10007;
	}
}

int top_down(int n) {
	if (n == 1) return 1;
	if (n == 0) return 1;
	if (d[n] > 0) return d[n];
	d[n] = top_down(n - 1) + (2 * top_down(n - 2));
	return d[n] %= 10007;
}
int main() {
	cin >> n;
	d[0] = 1;
	d[1] = 1;
	//bottom_up(n);
	top_down(n);
	cout << d[n]; 
	return 0;
}