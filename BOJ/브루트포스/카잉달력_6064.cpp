#include<iostream>
#include<algorithm>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int gcd(int n, int m) {
	int big, small;
	if (n > m)
		big = n, small = m;
	else
		big = m, small = n;
	while (true) {
		int nmg = big % small;
		if (nmg == 0) return small;
		else {
			big = small;
			small = nmg;
		}
	}
}

int lcd(int n, int m) {
	return n * m / gcd(n, m);
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int result = -1;
		x -= 1;
		y -= 1;
		for (int i = x; i <= lcd(M, N); i += M) {
			if (i%N == y) {
				result = i + 1;
				break;
			}
		}
		cout << result<< '\n';
	}
	return 0;
}



//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int M, N, x, y;
//		scanf("%d %d %d %d", &M, &N, &x, &y);
//		if (y == N) y = 0;
//		int index = 0;
//		int result = -1;
//		while (true) {
//			if ((M*index + x) % N == y) {
//				result = M * index + x;
//				break;
//			}
//			if (M*index + x > M*N) {
//				break;
//			}
//			index++;
//		}
//		cout << result << '\n';
//	}
//	return 0;
//}