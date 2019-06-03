//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int d[10001];
//int p[1001];
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		d[i] = -1;
//	}
//	d[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= i; j++) {
//			if (d[i] == -1 || d[i] > d[i - j] + p[j])
//				d[i] = d[i - j] + p[j];
//		}
//	}
//	cout << d[n] << '\n';
//	return 0;
//}



#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int p[1001];
int d[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		d[i] = 10000000;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = min(d[i], d[i - j] + p[j]);
		}
	}

	cout << d[n] << '\n';
	return 0;
}