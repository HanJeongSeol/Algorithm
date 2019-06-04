/*

	1. n=2인경우 , 10,12,21,23,....,87,89,98 = 총 17가지
	2. 0으로 시작하는 경우는 없다
	d[i][j] = i길이, 즉 i자리수의 수에서 숫자 j가 마지막에 오는 계단수의 경우의 수를 저장한다.
	d[3][3]을 구한다고 하면 길이가 세자리인 수에서 마지막에 오는 수가 3인 경우의 수를 구하면 된다.
	dp로 풀이한다면 d[2][2] + d[2][3], 즉 길이가 두자리인 수에서 2가 마지막에 오는 숫자에 3을 붙이면 되고, 3이 마지막이 오는 숫자에 4를 붙이면 된다.
	따라서 두 가지의 경우의 수를 더해주면 우리가 구하려는 d[3][3]이된다.

	d[i][j]
	조건 : 0이 앞에 올 수 없다 . 따라서 d[0][1] ~ d[0][9]는 모두 1이다.
	j-1 , j+1 두 가지 경우를 더하는 식을 구해야한다.
	if(j-1 >= 0) d[i][j] += d[i-1][j-1]
	if(j+1 <=9) d[i][j] += d[i-1][j+1]
*/

#include<iostream>
using namespace std;

int d[101][10];
const long long mod = 1000000000;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0)
				d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9)
				d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	long long hap = 0;
	for (int i = 0; i <= 9; i++) {
		hap += d[n][i];
	}
	hap %= mod;
	cout << hap << '\n';
	return 0;
}