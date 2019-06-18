/*
	120�� �־����� ��. 
	1~120���� ���� ���� ���� = 120-1+1 = 120;
	10 ~ 120 ���� ���� 10���ڸ� = 120 - 10 + 1 = 111
	100 ~ 120 ���� ���� 100���ڸ� = 120 - 100 + 1 = 21
	==> 252��

	1~9���� ���� = 9��;
	10 ~ 99���� ���� = 90��
	100 ~ 120���� ���� = 21�� 
	1���ڸ� = 9*1 = 9
	10���ڸ� = 90*2 = 180
	100���ڸ� = 21*3 = 63 
	===> 252

	������ ���� ���´�.
*/


#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i *= 10) {
		count += n - i + 1;
	}

	cout << count << '\n';
	return 0;
}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	int len = 0;
//	int temp = n;
//	while (n > 0) {
//		n /= 10;
//		len++;
//	}
//	n = temp;
//	int count = 0;
//	if (len == 1) {
//		cout << n << '\n';
//		return 0;
//	}
//	for (int i = 1; i < len; i++) {
//		count += i * (9 * (pow(10, i - 1)));
//	}
//	count += len * (n - (pow(10, len-1))+1);
//	cout << count << '\n';
//	return 0;
//}
