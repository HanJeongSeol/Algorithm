/*
	1. 가장 긴 증가하는 부분수열 찾기.
	2. d[i] = a[1]~a[i]에서 a[i]를 마지막으로 하는 수열.
	3. 항상 첫 번째 인덱스부터 시작하지 않아도 된다.
		3-1. 30 20 20 30을 넣었을 때 2가 출력되서 틀린줄 알았음.
		 하지만 중간에 20, 30으로 수열이 생성되기 때문에 2가 맞음.
		3-2. 왜 첫 인덱스가 항상 포함되어야 한다고 생각했는지 의문.
		3-3. 결론 항상 틀렸던 이유는 마지막 출력문에서 항상 d[n-1]을 출력했기 때문, 마지막 원소가 항상 큰 수라는 보장이 없다.
		3-4. 따라서 d배열에서 가장 큰 수를 출력해야 정답이 된다.
*/

#include<iostream>
using namespace std;

int d[1001];
int a[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > result)
			result = d[i];
	}
	cout << result << '\n';
	return 0;
}
