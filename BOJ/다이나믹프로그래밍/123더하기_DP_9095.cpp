/*	
	�־��� ���ڸ� 1,2,3���� ���� �� �ִ� ����� ���� ����ؾ��Ѵ�.
	1 - 1
	2 - 1+1 , 2
	3 - 1+1+1, 2 + 1, 1+2 , 3
	4 - 1+1+1+1, 2+1+1, 1+2+1, 3+1, 1+1+2, 2+2, 1+3

	2�� 1�� ��쿡�� +1�� �� ��� �� + �ڱ��ڽ�
	3�� 2�� ��쿡�� +1�� �� ��� �� + 1�� ��쿡�� +2�� �� ��� �� + �ڱ��ڽ�
	4�� 3�� ��쿡�� +1, 2�� ��쿡�� +2, 1�� ��쿡�� +3 �� ��� ���̴�

	�� d[n] = d[n-1] + d[n-2] + d[n-3]
	
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