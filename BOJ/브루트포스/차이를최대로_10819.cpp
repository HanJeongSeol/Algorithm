//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int n;
//int calculator(vector<int> a) {
//	int sum = 0;
//	for (int i = 1; i < n; i++) {
//		sum += abs(a[i - 1] - a[i]);
//	}
//	return sum;
//}
//
//int main() {
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	sort(a.begin(), a.end());
//	int ans = 0;
//	int result;
//	while (true) {
//		int result = calculator(a);
//		ans = max(ans, result);
//		int i1 = 0, j1;
//		for (int i = 1; i < n; i++) {
//			if (a[i - 1] < a[i]) {
//				i1 = i;
//			}
//		}
//		if (i1 == 0)
//			break;
//		for (int j = i1; j < n; j++) {
//			if (a[j] > a[i1 - 1]) {
//				j1 = j;
//			}
//		}
//		swap(a[i1 - 1], a[j1]);
//		sort(a.begin() + i1, a.end());
//	}
//	cout << ans << '\n';
//}


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int calculator(vector<int> a) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += abs(a[i - 1] - a[i]);
	}
	return sum;
}

int main() {
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	sort(a.begin(), a.end());
	do {
		ans = max(ans, calculator(a));
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << '\n';
}