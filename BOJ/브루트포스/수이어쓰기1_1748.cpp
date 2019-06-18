/*
	120이 주어졌을 때. 
	1~120까지 사용된 수의 개수 = 120-1+1 = 120;
	10 ~ 120 까지 사용된 10의자리 = 120 - 10 + 1 = 111
	100 ~ 120 까지 사용된 100의자리 = 120 - 100 + 1 = 21
	==> 252개

	1~9까지 개수 = 9개;
	10 ~ 99까지 개수 = 90개
	100 ~ 120까지 개수 = 21개 
	1의자리 = 9*1 = 9
	10의자리 = 90*2 = 180
	100의자리 = 21*3 = 63 
	===> 252

	동일한 값이 나온다.
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
