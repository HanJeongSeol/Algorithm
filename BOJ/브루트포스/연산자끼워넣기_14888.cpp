#include<iostream>
#include<algorithm>
using namespace std;

int num, sum;
int a[101];
int plus1, minus1, div1, mul;
int min_1 = 999999999;
int max_1 = -9999999;

void go(int index, int sum, int plus, int minus, int mul, int div) {
	if (index == num) {
		if (sum > max_1) max_1 = sum;
		if (sum < min_1) min_1 = sum;
		return;
	}
	if (plus < 0 || minus < 0 || div < 0 || mul < 0) return;

	if (plus > 0) go(index + 1, sum + a[index], plus - 1, minus, mul, div);
	if (minus > 0) go(index + 1, sum - a[index], plus, minus - 1, mul, div);
	if (mul > 0) go(index + 1, sum * a[index], plus, minus, mul - 1, div);
	if (div > 0) go(index + 1, sum / a[index], plus, minus, mul, div - 1);
}
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	cin >> plus1 >> minus1 >> mul >> div1;
	go(1, a[0], plus1, minus1, mul, div1);
	cout << max_1 << '\n';
	cout << min_1 << '\n';
	return 0;
}