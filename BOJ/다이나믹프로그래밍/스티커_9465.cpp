/*
	1. 2xi의 스티커가 있는데, 각각 가중치를 갖고있다.
	2. 1x4의 스티커를 사용했을 때 뗄 수 있는 스티커는 2x3 , 2x2 두 개의 스티커다.
		2-1. 대각선으로 한 칸 이전의 스티커와, 두 칸 이전의 스티커까지의 합 중 최대 값을 불러오면 된다.
		2-2. 세 칸 이전의 스티커를 떼기 위해서는 두 칸 이전의 스티커를 여러번 사용함으로서 도달 가능하며 효율성이 떨어진다.
	3. 시작은 1x1 or 2x1 둘 중 한 군데에서 시작한다. 따라서 두 결과값을 비교하여 최대값을 출력한다.
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int score[3][100001];
int d[3][100001];

int main() {
	int t; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> score[i][j];
				d[i][j] = 0;
			}
		}
		d[1][1] = score[1][1];
		d[2][1] = score[2][1];
		for (int i = 2; i <= n; i++) {
			d[1][i] += max(d[2][i - 1], d[2][i - 2]) + score[1][i];
			d[2][i] += max(d[1][i - 1], d[1][i - 2]) + score[2][i];


		}

		cout << max(d[1][n], d[2][n]) << '\n';
	}
	return 0;
}