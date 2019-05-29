/*
	N개의 카드 구매.
	카드의 가격은 P[i] 
	i = 들어있는 카드의 개수
	N=1인 경우 지불해야하는 금액의 최대 값 : D[0] + P[1]
	N-2인 경우 : D[2-1] + P[1], D[2-2] + P[2]
	N=3인 경우 : D[3-1] + P[1], D[3-2] + P[2], D[3-3] + P[1]
	즉 2개 사려고 하면, 한개 샀을 때의 최대 값 + 카드 한개 들어있는 카드팩 가격
	or 아무것도 안샀을 때의 최대 값 + 두개 들어있는 카드팩 가격 두 가지 경우 중 최대 값을 저장하면 된다.
	3개 사려고 하면, 2개 샀을 때의 최대 값 + 한개 들어있는 카드팩 가격 , 1개 샀을 때의 최대값 + 2개 들어있는 카드팩 가격이 된다.


*/

#include<iostream>
#include<algorithm>
using namespace std;

int p[10001];
int d[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=i; j++) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n];
	return 0;
}