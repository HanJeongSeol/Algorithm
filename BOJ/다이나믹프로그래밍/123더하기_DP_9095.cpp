/*	
	주어진 숫자를 1,2,3으로 만들 수 있는 경우의 수를 출력해야한다.
	1 - 1
	2 - 1+1 , 2
	3 - 1+1+1, 2 + 1, 1+2 , 3
	4 - 1+1+1+1, 2+1+1, 1+2+1, 3+1, 1+1+2, 2+2, 1+3

	2는 1의 경우에서 +1을 한 결과 값 + 자기자신
	3은 2의 경우에서 +1을 한 결과 값 + 1의 경우에서 +2를 한 결과 값 + 자기자신
	4는 3의 경우에서 +1, 2의 경우에서 +2, 1의 경우에서 +3 한 결과 값이다

	즉 d[n] = d[n-1] + d[n-2] + d[n-3]
	
*/
#include<iostream>
#include<algorithm>
using namespace std;

int d[12];

int top_down(int n) {
	if (n == 0) return 1;
	if (n == 1)return 1;
	if (n == 2)return 2;
	return d[n] = top_down(n - 1) + top_down(n - 2) + top_down(n - 3);
}

void bottom_up(int n) {
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}
}
int main() {
	int n,t;
	cin >> t;
	while (t--) {
		cin >> n;
		d[0] = 1;
		d[1] = 1;
		d[2] = 2;
		//top_down(n);
		bottom_up(n);
		cout << d[n] << '\n';
	}
	return 0;
}